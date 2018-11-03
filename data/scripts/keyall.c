#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/entity.h"

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
    
	/*
    Damon Vaughn Caskey
    06/25/2007
    Capture keystrokes and perform actions accordingly.
    */

	int     player_index;   // Player index.
	void    ent;			// Player entity.
	int     idle;	
	int		attacking;
	int		jumping;
    int     iXDir       = getentityproperty(ent, "xdir");                         //X velocity.
    int     iAni;                                                                   //Current animation.
    int     iFrame;                                                                 //Current animation frame.
    void    target;                                                                // Target entity.    


	int		player_key_hold;	// Keys currently held.
	int		player_key_press;	// Key press (triggers the key event).

	// Populate the variables.
	ent = getplayerproperty(player_index, "entity");                    

	player_index		= getlocalvar("player");
	player_key_hold		= getplayerproperty(player_index, "keys");
	player_key_press	= getplayerproperty(player_index, "newkeys");

	// Get AI status flags.
	idle		= getentityproperty(ent, "aiflag", "idling");    
	attacking	= getentityproperty(ent, "aiflag", "attacking");
	jumping		= getentityproperty(ent, "aiflag", "jumping");    


	if (idle)
    {	
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
    else if (attacking)                                                             //Attacking?
    {                
		// Dodge counter attack.
		if (dc_command_dodge_attack(player_index))
		{
			return;
		}

		iAni = getentityproperty(ent, "animationid");                          //Get current animation.
		iFrame = getentityproperty(ent, "animpos");                              //Get current frame.
		
		if (iAni == openborconstant("ANI_ATTACKUP"))                           //Sidestep up?             
        {
            if (player_key_press & openborconstant("FLAG_ATTACK") && !getentityproperty(ent, "zdir") && iFrame > 0)         //Attack press, have stopped moving and not at begining of animation?
            {
				dc_player_direction_switch(player_index);
                
                if (player_key_hold & openborconstant("FLAG_MOVEUP"))
                {
					dc_set_attack(ent, DODATKSU);                                   //Set Short Side Attack Down.                    
                }
                else if (player_key_hold & openborconstant("FLAG_MOVEDOWN"))
                {
					dc_set_attack(ent, DODATKSD);                                   //Set Short Side Attack Up.
                }
                else
                {
					dc_set_attack(ent, DODATKU);                                    //Set Side Dodge Up Attack.                                
                }               
            }
        }
        else if (iAni == openborconstant("ANI_ATTACKDOWN"))                         //Sidestep down?                   
        {
            if (player_key_press & openborconstant("FLAG_ATTACK") && !getentityproperty(ent, "zdir") && iFrame > 0)         //Attack press, have stopped moving and not at begining of animation?
            {
				dc_player_direction_switch(player_index);

                if (player_key_hold & openborconstant("FLAG_MOVEUP"))
                {
					dc_set_attack(ent, DODATKSU);                                   //Set Short Side Attack Down.                    
                }
                else if (player_key_hold & openborconstant("FLAG_MOVEDOWN"))
                {
					dc_set_attack(ent, DODATKSD);                                   //Set Short Side Attack Up.
                }
                else
                {
					dc_set_attack(ent, DODATKD);                                    //Set Side Dodge Down Attack.                                
                }                
            }
        }        
    }
}

// Caskey, Damon V.
// 2018-11-03
//
// Turn player entity around if player holds opposite direction key
// to entity's facing.
void dc_player_direction_switch(int player_index)
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
	dc_set_animation(ent, AIRBLOCK);

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
	dc_set_animation(ent, AIRBACK);

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
	dc_set_animation(ent, AIRJ2AL);

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
	dc_player_direction_switch(player_index);
	dc_set_attack(ent, DODATK);

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
	dc_set_attack(ent, ATKDOWN);

	// Stop moving in case we were walking.
	changeentityproperty(ent, "velocity", 0, 0, 0); 

	// Clear attack flag from key press.
	key_press -= openborconstant("FLAG_ATTACK");
	changeplayerproperty(player_index, "newkeys", key_press);

	// Return true.
	return 1;
}

// Caskey, Damon V.
// 2016-09-13
//
// Verify animation and entity, then instruct entity
// to perform animation as an attack.
int dc_set_attack(void ent, int animation)
{
	int is_valid;
	int vartype;
	int result;

	// Get entity vartype.
	vartype = typeof(ent);

	// If the entity is not a valid pointer, use self as default.
	if (vartype != openborconstant("VT_PTR"))
	{
		ent = getlocalvar("self");
	}
	
	// Get animation valid status.
	is_valid = getentityproperty(ent, "animvalid", animation);

	// Animation is valid?
	if (is_valid == 1)
	{
		// Switch using perform attack.
		result = performattack(ent, animation);
	}

	return result;
}

// Caskey, Damon V.
// 2016-09-13
//
// Verify animation and entity, then switch
// entity to new animation.
int dc_set_animation(void ent, int animation)
{
	int is_valid;
	int vartype;
	int result;

	// Get entity vartype.
	vartype = typeof(ent);

	// If the entity is not a valid pointer, use self as default.
	if (vartype != openborconstant("VT_PTR"))
	{
		ent = getlocalvar("self");
	}
	
	// Get animation valid status.
	is_valid = getentityproperty(ent, "animvalid", animation);

	// Animation is valid?
	if (is_valid == 1)
	{
		// Switch to animation.
		changeentityproperty(ent, "animation", animation);
	}	

	return result;
}