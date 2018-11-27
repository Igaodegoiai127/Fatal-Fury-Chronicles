#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/entity.h"

#include "data/scripts/dc_disney/main.c"


void oncreate()
{
	log("\n");
	log("keyall.c");
	log("\t");
	log("- oncreate().");
	log("\n");
}

void ondestroy()
{
	log("\n");
	log("keyall.c");
	log("\t");
	log("- oncreate().");
	log("\n");
}

void main(){
    
	int     player_index;		// Player index.
	void    ent;				// Player entity.
	int     idle;				// AI flag.
	int		attacking;			// AI flag.
	int		jumping;			// AI flag.
	
	// Populate the variables.
	ent = getplayerproperty(player_index, "entity");                    

	player_index		= getlocalvar("player");
	
	// Get AI status flags.
	idle		= getentityproperty(ent, "aiflag", "idling");    
	attacking	= getentityproperty(ent, "aiflag", "attacking");
	jumping		= getentityproperty(ent, "aiflag", "jumping");    

	// Set base entity for animation control library.
	dc_disney_set_entity(ent);

	// Run different action attempts based on basic entity state.
	if (idle)
    {
		// Backward dash (2x Special)
		if (dc_command_back_dash(player_index))
		{
			return;
		}

		// Hitting downed enemies.
		if (dc_try_down_attack(player_index))
		{
			return;
		}
	}    
    else if (jumping)
    {
		// Air block.
		if (dc_command_airblock(player_index))
		{
			return;
		}

		// Air back attack.
		if(dc_command_air_back_attack(player_index);
		{
			return;
		}
           
		// Alternate drop attack (Attack + down, not moving).
		if (dc_command_air_alternate_drop_attack(player_index))
		{
			return;
		}
    }
    else if (attacking)
    {                
		// Dodge counter attack.
		if (dc_command_dodge_attack(player_index))
		{
			return;
		}

		//  Side step follow up attacks.
		if (dc_command_sidestep_follow_up(player_index))
		{
			return;
		}
    }
}

// Caskey, Damon V.
// 2018-11-03
//
// Return true if entity is in last from of a side dodge.
int dc_check_sidestep_complete(void ent)
{
	int animation;
	int frame;
	float velocity_z;

	// Must be playing at least one of the side
	// dodge animations.
	animation = getentityproperty(ent, "animationid");

	if (animation == openborconstant("ANI_ATTACKDOWN")	||	
		animation == openborconstant("ANI_ATTACKUP"))
	{
		// Nothing, just continue.
	}
	else
	{
		return 0;
	}

	// Not on the first frame.
	frame = getentityproperty(ent, "animpos");

	if (!frame)
	{
		return 0;
	}

	// Not moving along Z axis.
	velocity_z = getentityproperty(ent, "zdir");

	if (velocity_z)
	{
		return 0;
	}

	// Got this far - we can return true.
	return 1;
}

// Caskey, Damon V.
// 2018-11-03
//
// Perform sidestep attacks if available.
int dc_command_sidestep_follow_up(int player_index)
{
	void ent;
	int key_press;
	int key_hold;
	int success; 

	// Get base entity.
	ent = getplayerproperty(player_index, "entity");

	// Have to be finished with sidestep.
	if (!dc_check_sidestep_complete(ent))
	{
		return 0;
	}

	// Verify key press.
	key_press = getplayerproperty(player_index, "newkeys");

	if (!(key_press & openborconstant("FLAG_ATTACK")))
	{
		return 0;
	}

	// Must have the animation.
	if (!getentityproperty(ent, "animvalid", DODATK))
	{
		return 0;
	}

	// Set the direction.
	dc_command_direction_switch(player_index);

	//  Perform action based on direction key.
	key_hold = getplayerproperty(player_index, "keys");

	if (key_hold & openborconstant("FLAG_MOVEUP"))
	{
		success = dc_disney_perform_attack(DODATKSU);
	}
	else if (key_hold & openborconstant("FLAG_MOVEDOWN"))
	{
		success = dc_disney_perform_attack(DODATKSD);
	}
	else
	{
		success = dc_disney_perform_attack(DODATKD);
	}

	// If animation set function returned true, then
	// animation was available and played. Return 
	// true.
	if (success)
	{
		// Clear key flag from key press.
		key_press -= openborconstant("FLAG_ATTACK");
		changeplayerproperty(player_index, "newkeys", key_press);

		// Return true.
		return 1;
	}

	return 0;
	
}

// Caskey, Damon V.
// 2018-11-01
//
// Perform backward dash if possible. Return true on success.
int dc_command_back_dash(int player_index)
{
	void ent;		// Base entity.
	int key_press;	// Key pressed.
	int key_hold;	// Key(s) hold.
	int time_current;
	int time_set;

	// Get base entity.
	ent = getplayerproperty(player_index, "entity");

	// Key press.
	key_press = getplayerproperty(player_index, "newkeys");

	if (!(key_press & openborconstant("FLAG_SPECIAL")))
	{
		return 0;
	}

	// Get time.
	time_set = getlocalvar(player_index + "_sp");

	//  Get current time.
	time_current = openborvariant("elapsed_time");

	//  Set tracking var for next cycle.
	setlocalvar(player_index + "_sp", time_current + 50);

	// Fail on first cycle.
	if (!time_set)
	{
		return;
	}

	// Last attempt has to be within time of current
	// attempt.
	if (time_current > time_set)
	{
		return;
	}

	// If we got this far then we can set a down attack.
	dc_disney_perform_attack(openborconstant("ANI_FREESPECIAL"));

	// Stop moving in case we were walking.
	changeentityproperty(ent, "velocity", 0, 0, 0);

	// Clear attack flag from key press.
	key_press -= openborconstant("FLAG_SPECIAL");
	changeplayerproperty(player_index, "newkeys", key_press);

	// Return true.
	return 1;
}

// Caskey, Damon V.
// 2018-11-03
//
// Turn player entity around if player holds opposite direction key
// to entity's facing.
void dc_command_direction_switch(int player_index)
{
	void ent;			// Base entity
	int direction;		// Entity direction.
	int opposite_key;	// Player key command vs. entity direction.

	// If player isn't holding opposite key, then we don't 
	// care about anything else.
	opposite_key = dc_check_key_back(player_index);
	
	if (!opposite_key)
	{
		return;
	}

	// We got this far, so let's turn the entity around.

	// Get base entity and direction.
	ent			= getplayerproperty(player_index, "entity");
	direction	= getentityproperty(ent, "direction");

	// Update direction variable as nessesaary.
	if (direction == openborconstant("DIRECTION_LEFT"))
	{
		direction = openborconstant("DIRECTION_RIGHT");
	}
	else if (direction == openborconstant("DIRECTION_RIGHT"))
	{
		direction = openborconstant("DIRECTION_LEFT");
	}

	// Apply updated direction to entity.
	changeentityproperty(ent, "direction", direction);
}

// Caskey, Damon V.
// 2018-11-03
//
// Return true if current directional key is "back" in relation to entity direction.
int dc_check_key_back(int player_index)
{

	void ent;		// Base entity
	int key_hold;	// Key(s) hold.
	int direction;	// Current facing.

	// Get base entity.
	ent = getplayerproperty(player_index, "entity");

	// Get key hold and direction.
	key_hold	= getplayerproperty(player_index, "keys");
	direction	= getentityproperty(ent, "direction");

	// Direction and key opposing? Then we return true.
	if (direction == openborconstant("DIRECTION_LEFT"))
	{
		if (key_hold &  openborconstant("FLAG_MOVERIGHT"))
		{
			return 1;
		}
	}
	else if (direction == openborconstant("DIRECTION_RIGHT"))
	{
		if (key_hold &  openborconstant("FLAG_MOVELEFT"))
		{
			return 1;
		}
	}
	
	// No checks passed, return false.
	return 0;
}

// Caskey, Damon  V.
// 2018-11-03
//
// Perform airblock on command if possible. Return true on success.
int dc_command_airblock(int player_index)
{
	void ent;
	int key_press;
	int attacking;
	//int jumping;

	// Get base entity.
	ent = getplayerproperty(player_index, "entity");

	// Verify key press.
	key_press = getplayerproperty(player_index, "newkeys");

	if (!(key_press & openborconstant("FLAG_SPECIAL")))
	{
		return 0;
	}

	// Must be jumping.
	//jumping = getentityproperty(ent, "aiflag", "jumping");

	//if (!jumping)
	//{
	//	return 0;
	//}

	// Can't be attacking.
	attacking = getentityproperty(ent, "aiflag", "attacking");

	if (attacking)
	{
		return 0;
	}

	// Must have an air block.
	if (!getentityproperty(ent, "animvalid", AIRBLOCK))
	{
		return 0;
	}

	// Set the animation.
	dc_disney_play_animation(AIRBLOCK);

	// Clear key flag from key press.
	key_press -= openborconstant("FLAG_SPECIAL");
	changeplayerproperty(player_index, "newkeys", key_press);

	// Return true.
	return 1;

}

// Caskey, Damon  V.
// 2018-11-03
//
// Perform air back attack on command if possible. Return true on success.
int dc_command_air_back_attack(int player_index)
{
	void ent;
	int key_press;
	int attacking;
	
	// Get base entity.
	ent = getplayerproperty(player_index, "entity");

	// Verify key press.
	key_press = getplayerproperty(player_index, "newkeys");

	if (!(key_press & openborconstant("FLAG_ATTACK")))
	{
		return 0;
	}

	// Verify key back.
	if (!dc_check_key_back(player_index))
	{
		return 0;
	}

	// Can't be attacking.
	attacking = getentityproperty(ent, "aiflag", "attacking");

	if (attacking)
	{
		return 0;
	}

	// Must have the animation.
	if (!getentityproperty(ent, "animvalid", AIRBACK))
	{
		return 0;
	}

	// Set the animation.
	dc_disney_play_animation(AIRBACK);

	// Clear key flag from key press.
	key_press -= openborconstant("FLAG_ATTACK");
	changeplayerproperty(player_index, "newkeys", key_press);

	// Return true.
	return 1;

}

// Caskey, Damon  V.
// 2018-11-03
//
// Perform air alternate drop attack (hold down + attack, when
// not moving along X axis) on command if possible. 
// Return true on c.
int dc_command_air_alternate_drop_attack(int player_index)
{
	void ent;
	int key_press;
	int key_hold;
	int attacking;
	float velocity_x;
	
	// Get base entity.
	ent = getplayerproperty(player_index, "entity");

	// Verify key press.
	key_press = getplayerproperty(player_index, "newkeys");

	if (!(key_press & openborconstant("FLAG_ATTACK")))
	{
		return 0;
	}

	// Verify key hold.
	key_hold = getplayerproperty(player_index, "keys");

	if (!(key_hold & openborconstant("FLAG_MOVEDOWN")))
	{
		return 0;
	}

	// Can't be attacking.
	attacking = getentityproperty(ent, "aiflag", "attacking");

	if (attacking)
	{
		return 0;
	}

	// Can't be moving along X axis.
	velocity_x = getentityproperty(ent, "xdir");

	if (velocity_x)
	{
		return 0;
	}

	// Must have the animation.
	if (!getentityproperty(ent, "animvalid", AIRJ2AL))
	{
		return 0;
	}

	// Set the animation.
	dc_disney_play_animation(AIRJ2AL);

	// Clear key flag from key press.
	key_press -= openborconstant("FLAG_ATTACK");
	changeplayerproperty(player_index, "newkeys", key_press);

	// Return true.
	return 1;

}

// Caskey, Damon  V.
// 2018-11-03
//
// Perform attack out of dodge while changing direction
// accoring to player command. Return true on success.
int dc_command_dodge_attack(int player_index)
{
	void ent;
	int key_press;
	int animation;

	// Get base entity.
	ent = getplayerproperty(player_index, "entity");

	animation = getentityproperty(ent, "animationid");

	if (animation != openborconstant("ANI_SPECIAL"))
	{
		return 0;
	}

	// Verify key press.
	key_press = getplayerproperty(player_index, "newkeys");

	if (!(key_press & openborconstant("FLAG_ATTACK")))
	{
		return 0;
	}

	// Must have the animation.
	if (!getentityproperty(ent, "animvalid", DODATK))
	{
		return 0;
	}

	// Set the direction and animation.
	dc_command_direction_switch(player_index);
	dc_disney_perform_attack(DODATK);

	// Clear key flag from key press.
	key_press -= openborconstant("FLAG_ATTACK");
	changeplayerproperty(player_index, "newkeys", key_press);

	// Return true.
	return 1;

}

// Caskey, Damon V.
// 2018-11-01
//
// Verify conditions for down attack and execute if possible.
int dc_try_down_attack(int player_index)
{
	void ent;		// Base entity.
	int key_press;	// Key pressed.
	int key_hold;	// Key(s) hold.
	void target;	// Target entity.
	int idle;


	// Get base entity.
	ent = getplayerproperty(player_index, "entity");

	// Key press must be attack 1.
	key_press = getplayerproperty(player_index, "newkeys");
		
	if (!(key_press & openborconstant("FLAG_ATTACK")))
	{
		return 0;
	}

	// Key hold must be Down.
	key_hold = getplayerproperty(player_index, "keys");

	if (!(key_hold & openborconstant("FLAG_MOVEDOWN")))
	{
		return 0;
	}

	// Must have a down attack.
	if (!getentityproperty(ent, "animvalid", ATKDOWN))
	{
		return 0;
	}

	// Must have a target within range of Down attack.
	// Any target in range of down attack?
	target = findtarget(ent, ATKDOWN);

	if (!target)
	{
		return 0;
	}

	// Target cannot be animating. This is how we
	// know it has completed a fall.
	if (getentityproperty(target, "aiflag", "animating"))
	{
		return 0;
	}

	// Target cannot be dead.
	if (getentityproperty(target, "dead"))
	{
		return 0;
	}

	// If we got this far then we can set a down attack.
	dc_disney_perform_attack(ATKDOWN);

	// Stop moving in case we were walking.
	changeentityproperty(ent, "velocity", 0, 0, 0); 

	// Clear attack flag from key press.
	key_press -= openborconstant("FLAG_ATTACK");
	changeplayerproperty(player_index, "newkeys", key_press);

	// Return true.
	return 1;
}