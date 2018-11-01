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

    int     iPlIndex    = getlocalvar("player");                                    //Player index.
    void    vSelf       = getplayerproperty(iPlIndex, "entity");                    //Get calling entity.
    int     iFlIdle     = getentityproperty(vSelf, "aiflag", "idling");             //Self idling?
    int     iFlAttack   = getentityproperty(vSelf, "aiflag", "attacking");          //Self attacking (freespecial, jumpattack, follow, or attack)?
    int     iFlJump     = getentityproperty(vSelf, "aiflag", "jumping");            //Self jumping?
    int     iUpH        = playerkeys(iPlIndex, 0, "moveup");                        //Hold  "Up".
    int     iDownH      = playerkeys(iPlIndex, 0, "movedown");                      //Hold  "Down".
    int     iLeftH      = playerkeys(iPlIndex, 0, "moveleft");                      //Hold  "Left".
    int     iRightH     = playerkeys(iPlIndex, 0, "moveright");                     //Hold  "Right".
    int     iRight      = playerkeys(iPlIndex, 1, "moveright");                     //Press "Right".
    int     iRightR     = playerkeys(iPlIndex, 2, "moveright");                     //Release "Right".
    int     iUp         = playerkeys(iPlIndex, 1, "moveup");                        //Press "Up".
    int     iDown       = playerkeys(iPlIndex, 1, "movedown");                      //Press "Down".
    int     iSpecial    = playerkeys(iPlIndex, 1, "Special");                       //Press "Special".
    int     iAttack     = playerkeys(iPlIndex, 1, "attack");                        //Press "Attack".
    int     iAttack3    = playerkeys(iPlIndex, 1, "attack3");                       //Press "Attack3". 
    int     iAttack4    = playerkeys(iPlIndex, 1, "attack4");                       //Press "Attack4".    
	int     iXDir       = getentityproperty(vSelf, "xdir");                         //X velocity.
    int     iTime       = openborvariant("elapsed_time");                           //Current time.
    int     iAni;                                                                   //Current animation.
    int     iFrame;                                                                 //Current animation frame.
    void    vTarget;                                                                //Opponent.    

    if (iSpecial)
    {
        setentityvar(vSelf, KEY1SP, iTime);                                         //Store last press of special key.        
    }
	else if(iAttack)
    {
        setentityvar(vSelf, KEY1AT, iTime);                                         //Store last press of Attack key.        
    }

    if (iFlIdle)                                                                    //Idle?
    {
        if (iAttack)                                                                //New attack press?
        {
            if (iDownH && getentityproperty(vSelf, "animvalid", ATKDOWN))           //Holding down and have a Down Attack?
            {
                vTarget = findtarget(vSelf, ATKDOWN);                               //Look for opponent within range of Down Attack.
                
                if (vTarget && !getentityproperty(vTarget, "aiflag", "animating"))  //Target found and is not animating (finished with fall)?
                {
                    if (getentityproperty(vTarget, "health") > 0)                   //Target still alive?
                    {                        
                        if (ani0009(vSelf, ATKDOWN, 1))                             //Set downattack.
                        {
                            changeentityproperty(vSelf, "velocity", 0,0,0);         //If downattack was valid and set, stop moving.                                 //Set Downattack.                                        
                        }
                    }
                }
            }
        }
        ////Poses////
        else if (iAttack3)                                                          //New attack3 press?
        {
			
            changeentityproperty(vSelf, "velocity", 0, 0, 0);                       //Stop moving.
            changeplayerproperty(vSelf, "playkeys", 0);                             //Clear key event.

            if (iUpH)                                                               //Holding up?
            {                
                ani0009(vSelf, openborconstant("ANI_FOLLOW71"), 0);                 //Set pose 2.                                        
            }
            else if (iDownH)                                                        //Holding down?
            {                                
                ani0009(vSelf, openborconstant("ANI_FOLLOW72"), 0);                 //Set pose 3.                              
            }
            else if (iLeftH)                                                        //Holding left?
            {
                ani0009(vSelf, openborconstant("ANI_FOLLOW73"), 0);                 //Set pose 4.
            }
            else if (iRightH)                                                       //Holding right?
            {
                ani0009(vSelf, openborconstant("ANI_FOLLOW74"), 0);                 //Set pose 5.
            }
            else                                                                    //No direction?
            {
                ani0009(vSelf, openborconstant("ANI_FOLLOW70"), 0);                 //Set pose 1.
            }
			performattack(vSelf, POWUP, 0);
        }
    }    
    else if (iFlJump)                                                               //Jumping?
    {
        /*
        //Mario style jumpheight control.
        if (playerkeys(iPlIndex, 2, "jump"))                                        //Jump key release?
        {
            iTossV  = getentityproperty(vSelf, "tossv");                            //Get Y velocity.
            iXDir   = getentityproperty(vSelf, "xdir");                             //Get X velocity.
            iZDir   = getentityproperty(vSelf, "zdir");                             //Get Z velocity.
            if (iTossV > 0)                                                         //Not falling already?
            {			
                iTossV /= 4;                                                        //Cut Y velcoity to 25%.
                changeentityproperty(vSelf, "velocity", iXDir, iZDir, iTossV);      //Apply velocity.
            }
        }
        */
            
        if (!iFlAttack)                                                             //Not attacking?
        {
            if (iSpecial)                                                           //New Special press?
            {               
                ani0009(vSelf, AIRBLOCK, -1);                                       //Set Airblock.                               
            }
            else if (iAttack)                                                       //New Attack press?
            { 
                if (key0002(vSelf, iLeftH, iRightH))                                //Holding Back?
                {   
                    ani0009(vSelf, AIRBACK, -1);                                    //Set Air back attack.                                           
                }
                else if (iDownH)                                                    //Holding Down?
                {
                    if (!iXDir)                                                     //Not moving horizontally?
                    {
                        ani0009(vSelf, AIRJ2AL, -1);                                //Set Jumpattack 2 alt.                        
                    }
                }
            }
        }
    }
    else if (iFlAttack)                                                             //Attacking?
    {        
        iAni    = getentityproperty(vSelf, "animationid");                          //Get current animation.
        iFrame  = getentityproperty(vSelf, "animpos");                              //Get current frame.
        
        if (iAni == openborconstant("ANI_SPECIAL"))                                 //Special (dodge) animation?             
        {
            if (iAttack)
            {
                key0004(vSelf, iLeftH, iRightH);                                    //Change direction?
                ani0009(vSelf, DODATK, -1);                                         //Set Dodge Attack.                
                changeplayerproperty(vSelf, "playkeys", 0);                         //Clear key event.                
            }
            else if (iUp)
            {
                key0004(vSelf, iLeftH, iRightH);                                    //Change direction?
                ani0009(vSelf, openborconstant("ANI_ATTACKUP"), -1);                //Set Dodge Up.
                changeplayerproperty(vSelf, "playkeys", 0);                         //Clear key event.
            }
            else if (iDown)
            {
                key0004(vSelf, iLeftH, iRightH);                                    //Change direction?
                ani0009(vSelf, openborconstant("ANI_ATTACKDOWN"), -1);              //Set Dodge Down.
                
            }
        }
        else if (iAni == openborconstant("ANI_ATTACKUP"))                           //Sidestep up?             
        {
            if (iAttack && !getentityproperty(vSelf, "zdir") && iFrame > 0)         //Attack press, have stopped moving and not at begining of animation?
            {
                key0004(vSelf, iLeftH, iRightH);                                    //Change direction?
                
                if (iUpH)
                {
                    ani0009(vSelf, DODATKSU, -1);                                   //Set Short Side Attack Down.                    
                }
                else if (iDownH)
                {
                    ani0009(vSelf, DODATKSD, -1);                                   //Set Short Side Attack Up.
                }
                else
                {
                    ani0009(vSelf, DODATKU, -1);                                    //Set Side Dodge Up Attack.                                
                }               
            }
        }
        else if (iAni == openborconstant("ANI_ATTACKDOWN"))                         //Sidestep down?                   
        {
            if (iAttack && !getentityproperty(vSelf, "zdir") && iFrame > 0)         //Attack press, have stopped moving and not at begining of animation?
            {
                key0004(vSelf, iLeftH, iRightH);                                    //Change direction?

                if (iUpH)
                {
                    ani0009(vSelf, DODATKSU, -1);                                   //Set Short Side Attack Down.                    
                }
                else if (iDownH)
                {
                    ani0009(vSelf, DODATKSD, -1);                                   //Set Short Side Attack Up.
                }
                else
                {
                    ani0009(vSelf, DODATKD, -1);                                    //Set Side Dodge Down Attack.                                
                }                
            }
        }        
    }
}
