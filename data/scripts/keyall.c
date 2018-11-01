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
    int     iFlIdle     = getentityproperty(ent, "aiflag", "idling");             //Self idling?
    int     iFlAttack   = getentityproperty(ent, "aiflag", "attacking");          //Self attacking (freespecial, jumpattack, follow, or attack)?
    int     iFlJump     = getentityproperty(ent, "aiflag", "jumping");            //Self jumping?
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
    int     iTime       = openborvariant("elapsed_time");                           //Current time.
    int     iAni;                                                                   //Current animation.
    int     iFrame;                                                                 //Current animation frame.
    void    vTarget;                                                                //Opponent.    

	int		player_key_hold;	// Keys currently held.
	int		player_key_press;	// Key press (triggers the key event).

	// Populate the variables.
	ent = getplayerproperty(player_index, "entity");                    

	player_index		= getlocalvar("player");
	player_key_hold		= getplayerproperty(player_index, "keys");
	player_key_press	= getplayerproperty(player_index, "newkeys");

    if (iFlIdle)                                                                    //Idle?
    {
        if (iAttack)                                                                //New attack press?
        {
            if (iDownH && getentityproperty(ent, "animvalid", ATKDOWN))           //Holding down and have a Down Attack?
            {
                vTarget = findtarget(ent, ATKDOWN);                               //Look for opponent within range of Down Attack.
                
                if (vTarget && !getentityproperty(vTarget, "aiflag", "animating"))  //Target found and is not animating (finished with fall)?
                {
                    if (getentityproperty(vTarget, "health") > 0)                   //Target still alive?
                    {                        
                        if (ani0009(ent, ATKDOWN, 1))                             //Set downattack.
                        {
                            changeentityproperty(ent, "velocity", 0,0,0);         //If downattack was valid and set, stop moving.                                 //Set Downattack.                                        
                        }
                    }
                }
            }
        }
        ////Poses////
        else if (iAttack3)                                                          //New attack3 press?
        {
			
            changeentityproperty(ent, "velocity", 0, 0, 0);                       //Stop moving.
            changeplayerproperty(ent, "playkeys", 0);                             //Clear key event.

            if (iUpH)                                                               //Holding up?
            {                
                ani0009(ent, openborconstant("ANI_FOLLOW71"), 0);                 //Set pose 2.                                        
            }
            else if (iDownH)                                                        //Holding down?
            {                                
                ani0009(ent, openborconstant("ANI_FOLLOW72"), 0);                 //Set pose 3.                              
            }
            else if (iLeftH)                                                        //Holding left?
            {
                ani0009(ent, openborconstant("ANI_FOLLOW73"), 0);                 //Set pose 4.
            }
            else if (iRightH)                                                       //Holding right?
            {
                ani0009(ent, openborconstant("ANI_FOLLOW74"), 0);                 //Set pose 5.
            }
            else                                                                    //No direction?
            {
                ani0009(ent, openborconstant("ANI_FOLLOW70"), 0);                 //Set pose 1.
            }
			performattack(ent, POWUP, 0);
        }
    }    
    else if (iFlJump)                                                               //Jumping?
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
            
        if (!iFlAttack)                                                             //Not attacking?
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
    else if (iFlAttack)                                                             //Attacking?
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
