#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/entity.h"
#include "data/scripts/com/ani0009.h"
#include "data/scripts/com/key0002.h"
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
            
        if (!attacking)                                                             //Not attacking?
        {
            if (iSpecial)                                                           //New Special press?
            {               
                ani0009(ent, AIRBLOCK, -1);                                       //Set Airblock.                               
            }
            else if (iAttack)                                                       //New Attack press?
            { 
                if (key0002(ent, iLeftH, iRightH))                                //Holding Back?
                {   
                    ani0009(ent, AIRBACK, -1);                                    //Set Air back attack.                                           
                }
                else if (iDownH)                                                    //Holding Down?
                {
                    if (!iXDir)                                                     //Not moving horizontally?
                    {
                        ani0009(ent, AIRJ2AL, -1);                                //Set Jumpattack 2 alt.                        
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
                ani0009(ent, DODATK, -1);                                         //Set Dodge Attack.                
                changeplayerproperty(ent, "playkeys", 0);                         //Clear key event.                
            }
            else if (iUp)
            {
                key0004(ent, iLeftH, iRightH);                                    //Change direction?
                ani0009(ent, openborconstant("ANI_ATTACKUP"), -1);                //Set Dodge Up.
                changeplayerproperty(ent, "playkeys", 0);                         //Clear key event.
            }
            else if (iDown)
            {
                key0004(ent, iLeftH, iRightH);                                    //Change direction?
                ani0009(ent, openborconstant("ANI_ATTACKDOWN"), -1);              //Set Dodge Down.
                
            }
        }
        else if (iAni == openborconstant("ANI_ATTACKUP"))                           //Sidestep up?             
        {
            if (iAttack && !getentityproperty(ent, "zdir") && iFrame > 0)         //Attack press, have stopped moving and not at begining of animation?
            {
                key0004(ent, iLeftH, iRightH);                                    //Change direction?
                
                if (iUpH)
                {
                    ani0009(ent, DODATKSU, -1);                                   //Set Short Side Attack Down.                    
                }
                else if (iDownH)
                {
                    ani0009(ent, DODATKSD, -1);                                   //Set Short Side Attack Up.
                }
                else
                {
                    ani0009(ent, DODATKU, -1);                                    //Set Side Dodge Up Attack.                                
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
                    ani0009(ent, DODATKSU, -1);                                   //Set Short Side Attack Down.                    
                }
                else if (iDownH)
                {
                    ani0009(ent, DODATKSD, -1);                                   //Set Short Side Attack Up.
                }
                else
                {
                    ani0009(ent, DODATKD, -1);                                    //Set Side Dodge Down Attack.                                
                }                
            }
        }        
    }
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