#include	"data/scripts/vars/anims.h"
#include	"data/scripts/vars/entity.h"
#include	"data/scripts/com/ani0009.h"
#include	"data/scripts/com/key0002.h"
#include	"data/scripts/com/key0004.h"
#include	"data/scripts/com/debu0001.h"
#include	"data/scripts/com/musi0001.h"
#include	"data/scripts/com/targ0002.h"

void main(){

	/*
    Damon Vaughn Caskey
    06/25/2007
    Capture keystrokes and perform actions accordingly.
    */

    int     iPlIndex    = getlocalvar("player");											//Player index.
    void    vSelf       = getplayerproperty(iPlIndex, "entity");							//Get calling entity.
    int     iFlIdle     = getentityproperty(vSelf, "aiflag", "idling");						//Self idling?
    int     iFlAttack   = getentityproperty(vSelf, "aiflag", "attacking");					//Self attacking (freespecial, jumpattack, follow, or attack)?
    int     iFlJump     = getentityproperty(vSelf, "aiflag", "jumping");					//Self jumping?
	int     iTime       = openborvariant("elapsed_time");									//Current time.
    float   fXDir;																			//X velocity.
	float	fZDir;																			//Z veolocity.
	int     iAni;																			//Current animation.
    int     iFrame;																			//Current animation frame.
    void    vTarget;																		//Opponent/target.

	int     iKUpH       = playerkeys(iPlIndex, 0, "moveup");								//Hold "Up".
    int     iKDnH       = playerkeys(iPlIndex, 0, "movedown");								//Hold "Down".
	int     iKLtH       = playerkeys(iPlIndex, 0, "moveleft");								//Hold "Left".
    int     iKRtH       = playerkeys(iPlIndex, 0, "moveright");								//Hold "Right".
    int     iKAtkH      = playerkeys(iPlIndex, 0, "attack");								//Hold "Attack".
    int     iKAtk2H     = playerkeys(iPlIndex, 0, "attack2");								//Hold "Attack2".
    int     iKAtk3H     = playerkeys(iPlIndex, 0, "attack3");								//Hold "Attack3".
    int     iKAtk4H     = playerkeys(iPlIndex, 0, "attack4");								//Hold "Attack4".
    int     iKJmpH      = playerkeys(iPlIndex, 0, "jump");									//Hold "Jump".
    int     iKSpH       = playerkeys(iPlIndex, 0, "special");								//Hold "Special".
	int     iKStH       = playerkeys(iPlIndex, 0, "start");									//Hold "Start".
	int     iKSsH       = playerkeys(iPlIndex, 0, "SCREENSHOT");							//Hold "Screenshot".
    int     iKEscH      = playerkeys(iPlIndex, 0, "esc");									//Hold "esc".
	int     iKAnyH      = playerkeys(iPlIndex, 0, "ANYBUTTON");								//Hold any key.

	int     iKUp        = playerkeys(iPlIndex, 1, "moveup");								//Press "Up".
    int     iKDn        = playerkeys(iPlIndex, 1, "movedown");								//Press "Down".
    int     iKLt        = playerkeys(iPlIndex, 1, "moveleft");								//Press "Left".
    int     iKRt        = playerkeys(iPlIndex, 1, "moveright");								//Press "Right".
	int     iKAtk       = playerkeys(iPlIndex, 1, "attack");								//Press "Attack".
	int     iKAtk2      = playerkeys(iPlIndex, 1, "attack2");								//Press "Attack2".
    int     iKAtk3      = playerkeys(iPlIndex, 1, "attack3");								//Press "Attack3".
    int     iKAtk4      = playerkeys(iPlIndex, 1, "attack4");								//Press "Attack4".
	int     iKJmp       = playerkeys(iPlIndex, 1, "jump");									//Press "Jump".
    int     iKSp        = playerkeys(iPlIndex, 1, "special");								//Press "Special".
    int     iKSt        = playerkeys(iPlIndex, 1, "start");
	int     iKSs        = playerkeys(iPlIndex, 1, "SCREENSHOT");							//Press "Screenshot".
	int     iKEsc       = playerkeys(iPlIndex, 1, "esc");									//Press "escape".
	int     iKAny       = playerkeys(iPlIndex, 1, "ANYBUTTON");								//Press any key.

    int     iKUpR       = playerkeys(iPlIndex, 2, "moveup");								//Release "Up".
    int     iKDnR       = playerkeys(iPlIndex, 2, "movedown");								//Release "Down".
	int     iKLtR       = playerkeys(iPlIndex, 2, "moveleft");								//Release "Left".
    int     iKRtR       = playerkeys(iPlIndex, 2, "moveright");								//Release "Right".
	int     iKAtkR      = playerkeys(iPlIndex, 2, "attack");								//Release "Attack".
    int     iKAtk2R     = playerkeys(iPlIndex, 2, "attack2");								//Release "Attack2".
    int     iKAtk3R     = playerkeys(iPlIndex, 2, "attack3");								//Release "Attack3".
    int     iKAtk4R     = playerkeys(iPlIndex, 2, "attack4");								//Release "Attack4".
	int     iKJmpR      = playerkeys(iPlIndex, 2, "jump");									//Release "Jump".
	int     iKSpR       = playerkeys(iPlIndex, 2, "special");								//Release "Special".
    int     iKStR       = playerkeys(iPlIndex, 2, "start");									//Release "Start".
    int     iKSsR       = playerkeys(iPlIndex, 2, "SCREENSHOT");							//Release "Screenshot".
    int     iKAnyR      = playerkeys(iPlIndex, 2, "ANYBUTTON");								//Release any key.

	//debu0001(vSelf, iKUp, iKDn, iKLt, iKRt, iKAtk, iKAtk2, iKAtk3, iKAtk4, iKSt, iKSs, iKEsc, iKAtkH, iKAtk2H, iKAtk3H, iKAtk4H, iKSp, iKJmpH, iKEscH);

    if (iKSp)
    {
        setentityvar(vSelf, KEY1SP, iTime);													//Store last press of special key.
    }
	else if(iKAtk)
    {
        setentityvar(vSelf, KEY1AT, iTime);													//Store last press of Attack key.
    }

    if (iFlIdle)																			//Idle?
    {
        if (iKAtk)																			//New attack press?
        {
			/*
			Poses. What's the point of thrashing someone if you can't rub their noses in it? This also
			has a nice side effect of stoping players from attacking while they hold the block button.
			*/
			if (iKSpH)																			//Holding Special?
			{
				changeentityproperty(vSelf, "velocity", 0, 0, 0);								//Stop moving.
				changeplayerproperty(vSelf, "playkeys", 0);										//Clear key event.

				if (iKUpH)																		//Holding up?
				{
					ani0009(vSelf, openborconstant("ANI_FOLLOW71"), 0);							//Set pose 2.
				}
				else if (iKDnH)																	//Holding down?
				{
					ani0009(vSelf, openborconstant("ANI_FOLLOW72"), 0);							//Set pose 3.
				}
				else if (iKLtH)																	//Holding left?
				{
					ani0009(vSelf, openborconstant("ANI_FOLLOW73"), 0);							//Set pose 4.
				}
				else if (iKRtH)																	//Holding right?
				{
					ani0009(vSelf, openborconstant("ANI_FOLLOW74"), 0);							//Set pose 5.
				}
				else																			//No direction?
				{
					ani0009(vSelf, openborconstant("ANI_FOLLOW70"), 0);							//Set pose 1.
				}

				iAni = getentityproperty(vSelf, "animationid");									//Get current animation.

				if(iAni != openborconstant("ANI_BLOCK"))										//Not in block animation?
				{
					changeentityproperty(vSelf, "aiflag", "blocking", 0);						//Make sure blocking flag is clear.
				}
			}

			/*
			Down Attack
			*/
            if (iKDnH && getentityproperty(vSelf, "animvalid", ATKDOWN))					//Holding down and have a Down Attack?
            {
                vTarget = findtarget(vSelf, ATKDOWN);										//Look for opponent within range of Down Attack.

                if (vTarget && !getentityproperty(vTarget, "aiflag", "animating"))			//Target found and is not animating (finished with fall)?
                {
                    if (getentityproperty(vTarget, "health") > 0)							//Target still alive?
                    {
                        if (ani0009(vSelf, ATKDOWN, 1))										//Set downattack.
                        {
                            changeentityproperty(vSelf, "velocity", 0,0,0);					//If animation was valid and set, stop moving.
                        }
                    }
                }
            }

			/*
			Music change.
			*/
			vTarget = targ0002(vSelf, openborconstant("ANI_GET"), openborconstant("TYPE_OBSTACLE"), -1, 3);

			if(vTarget)																		//Music change object found?
			{
				musi0001(vTarget, 1);

				if(ani0009(vSelf, openborconstant("ANI_GET"), 1))							//Set/verify animation.
				{
					changeentityproperty(vSelf, "velocity", 0,0,0);							//If animation was valid and set, stop moving.
				}
			}
        }
    }
    else if (iFlJump)																		//Jumping?
    {
        if (!iFlAttack)																		//Not attacking?
        {
            if (iKSp)																		//New Special press?
            {
                ani0009(vSelf, AIRBLOCK, -1);												//Set Airblock.
            }
            else if (iKAtk)																	//New Attack press?
            {
                if (key0002(vSelf, iKLtH, iKRtH))											//Holding Back?
                {
                    ani0009(vSelf, AIRBACK, -1);											//Set Air back attack.
                }
                else if (iKDnH)																//Holding Down?
                {
					fXDir		= getentityproperty(vSelf, "xdir");							//Get X velocity.

                    if (!fXDir)																//Not moving horizontally?
                    {
                        ani0009(vSelf, AIRJ2AL, -1);										//Set Jumpattack 2 alt.
                    }
                }
            }
        }
    }
    else if (iFlAttack)																		//Attacking?
    {
        iAni    = getentityproperty(vSelf, "animationid");									//Get current animation.
        iFrame  = getentityproperty(vSelf, "animpos");										//Get current frame.

        if (iAni == openborconstant("ANI_SPECIAL"))											//Special (dodge) animation?
        {
            if (iKAtk)
            {
                key0004(vSelf, iKLtH, iKRtH);												//Change direction?
                ani0009(vSelf, DODATK, -1);													//Set Dodge Attack.
                changeplayerproperty(vSelf, "playkeys", 0);									//Clear key event.
            }
            else if (iKUp)
            {
                key0004(vSelf, iKLtH, iKRtH);												//Change direction?
                ani0009(vSelf, openborconstant("ANI_ATTACKUP"), -1);						//Set Dodge Up.
                changeplayerproperty(vSelf, "playkeys", 0);									//Clear key event.
            }
            else if (iKDn)
            {
                key0004(vSelf, iKLtH, iKRtH);												//Change direction?
                ani0009(vSelf, openborconstant("ANI_ATTACKDOWN"), -1);						//Set Dodge Down.

            }
        }
        else if (iAni == openborconstant("ANI_ATTACKUP"))									//Sidestep up?
        {
			fZDir = getentityproperty(vSelf, "zdir");										//Get Z velocity.

            if (iKAtk && !fZDir && iFrame > 0)												//Attack press, have stopped moving and not at begining of animation?
            {
                key0004(vSelf, iKLtH, iKRtH);												//Change direction?

                if (iKUpH)
                {
                    ani0009(vSelf, DODATKSU, -1);											//Set Short Side Attack Down.
                }
                else if (iKDnH)
                {
                    ani0009(vSelf, DODATKSD, -1);											//Set Short Side Attack Up.
                }
                else
                {
                    ani0009(vSelf, DODATKU, -1);											 //Set Side Dodge Up Attack.
                }
            }
        }
        else if (iAni == openborconstant("ANI_ATTACKDOWN"))									//Sidestep down?
        {
			fZDir = getentityproperty(vSelf, "zdir");										//Get Z velocity.

            if (iKAtk && !fZDir && iFrame > 0)												//Attack press, have stopped moving and not at begining of animation?
            {
                key0004(vSelf, iKLtH, iKRtH);												//Change direction?

                if (iKUpH)
                {
                    ani0009(vSelf, DODATKSU, -1);											//Set Short Side Attack Down.
                }
                else if (iKDnH)
                {
                    ani0009(vSelf, DODATKSD, -1);											//Set Short Side Attack Up.
                }
                else
                {
                    ani0009(vSelf, DODATKD, -1);											//Set Side Dodge Down Attack.
                }
            }
        }
    }
}
