#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/entity.h"
#include "data/scripts/com/key0004.h"

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
    int     iUpH        = playerkeys(player_index, 0, "moveup");                        //Hold  "Up".
    int     iDownH      = playerkeys(player_index, 0, "movedown");                      //Hold  "Down".
    int     iLeftH      = playerkeys(player_index, 0, "moveleft");                      //Hold  "Left".
    int     iRightH     = playerkeys(player_index, 0, "moveright");                     //Hold  "Right".
    int     iRight      = playerkeys(player_index, 1, "moveright");                     //Press "Right".
    int     iRightR     = playerkeys(player_index, 2, "moveright");                     //Release "Right".
    int     iUp         = playerkeys(player_index, 1, "moveup");                        //Press "Up".
    int     iDown       = playerkeys(player_index, 1, "movedown");                      //Press "Down".
    int     iSpecial    = playerkeys(player_index, 1, "Special");                       //Press "Special".
    int     iAttack     = playerkeys(player_index, 1, "attack");                        //Press "Attack".
    int     iAttack3    = playerkeys(player_index, 1, "attack3");                       //Press "Attack3". 
    int     iAttack4    = playerkeys(player_index, 1, "attack4");                       //Press "Attack4".    
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


    if (idle)                                                                    //Idle?
    {
		// Hitting downed enemies.
		if (dc_try_down_attack(player_index))
		{
			return;
		}
	}    
    else if (jumping)                                                               //Jumping?
    {
        /*
        //Mario style jumpheight control.
        if (playerkeys(player_index, 2, "jump"))                                        //Jump key release?
        {
            iTossV  = getentityproperty(ent, "tossv");                            //Get Y velocity.
            iXDir   = getentityproperty(ent, "xdir");                             //Get X velocity.
            iZDir   = getentityproperty(ent, "zdir");                             //Get Z velocity.
            if (iTossV > 0)                                                         //Not falling already?
            {			
                iTossV /= 4;                                                        //Cut Y velcoity to 25%.
                changeentityproperty(ent, "velocity", iXDir, iZDir, iTossV);      //Apply velocity.
            }
        }
        */
           
		// Not attacking?
        if (!attacking)                                                             
        {

			// Check keys.
            if (iSpecial)                                                           
            {
				dc_set_animation(ent, AIRBLOCK);
            }
            else if (iAttack)                                                       
            { 
				// Holding Back?
                if (dc_check_key_back(player_index))
                {   
					// Set Air back attack. 
					dc_set_attack(ent, AIRBACK);                                                                              
                }
                else if (iDownH)                                                    
                {
					// Not moving horizontally?
                    if (!iXDir)                  
                    {
						// Set Jumpattack 2 alt.
						dc_set_attack(ent, AIRJ2AL);
                    }
                }
            }
        }
    }
    else if (attacking)                                                             //Attacking?
    {        
        iAni    = getentityproperty(ent, "animationid");                          //Get current animation.
        iFrame  = getentityproperty(ent, "animpos");                              //Get current frame.
        
        if (iAni == openborconstant("ANI_SPECIAL"))                                 //Special (dodge) animation?             
        {
            if (iAttack)
            {
                key0004(ent, iLeftH, iRightH);                                    //Change direction?
				dc_set_attack(ent, DODATK);                                         //Set Dodge Attack.                
                changeplayerproperty(ent, "playkeys", 0);                         //Clear key event.                
            }
            else if (iUp)
            {
                key0004(ent, iLeftH, iRightH);                                    //Change direction?
				dc_set_attack(ent, ent, openborconstant("ANI_ATTACKUP"));         //Set Dodge Up.
                changeplayerproperty(ent, "playkeys", 0);                         //Clear key event.
            }
            else if (iDown)
            {
                key0004(ent, iLeftH, iRightH);                                    //Change direction?
				dc_set_attack(ent, openborconstant("ANI_ATTACKDOWN"));              //Set Dodge Down.
				changeplayerproperty(ent, "playkeys", 0);                         //Clear key event.
                
            }
        }
        else if (iAni == openborconstant("ANI_ATTACKUP"))                           //Sidestep up?             
        {
            if (iAttack && !getentityproperty(ent, "zdir") && iFrame > 0)         //Attack press, have stopped moving and not at begining of animation?
            {
                key0004(ent, iLeftH, iRightH);                                    //Change direction?
                
                if (iUpH)
                {
					dc_set_attack(ent, DODATKSU);                                   //Set Short Side Attack Down.                    
                }
                else if (iDownH)
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
            if (iAttack && !getentityproperty(ent, "zdir") && iFrame > 0)         //Attack press, have stopped moving and not at begining of animation?
            {
                key0004(ent, iLeftH, iRightH);                                    //Change direction?

                if (iUpH)
                {
					dc_set_attack(ent, DODATKSU);                                   //Set Short Side Attack Down.                    
                }
                else if (iDownH)
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