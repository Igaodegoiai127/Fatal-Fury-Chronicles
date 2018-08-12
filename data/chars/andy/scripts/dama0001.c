#include "data/scripts/com/dama0002.h"

/*
Take damage for Andy Bogard.

-Ensure lingering special effects from "C4 in UR Face" throw disappear.

-Always fall down and take 50% extra damage if hit out of "C4 in UR Face", 
"Gourin Kai" (grabforward), "Shiranaui Spider Clutch (grabdown), or 
"Gekiheki Haisui Shou" (grab up). Extra damage is non lethal.

-Run normal take damage functions.

*/

void main()
{
    
    void vSelf      = getlocalvar("self");                      //Calling entity.    
    int  iDrop      = getlocalvar("drop");                      //Incomming attack a knockdown?
    int  iAni       = getentityproperty(vSelf, "animationid");  //Current animation.
    int  iDamage    = getlocalvar("damage");                    //Incoming damage.
    int  iHP        = getentityproperty(vSelf, "health");       //Current HP.

    if (iAni == openborconstant("ANI_GRABDOWN")
        || iAni == openborconstant("ANI_GRABFORWARD")
        || iAni == openborconstant("ANI_GRABUP")
        || iAni == openborconstant("ANI_FOLLOW5")
        || iAni == openborconstant("ANI_FREESPECIAL19"))      
    {
        iDamage = 0.5 * iDamage;                                //Get half of incoming damage.

        if (iHP > iDamage)                                      //HP more then damage?
        {
            iHP -= iDamage;                                     //Subtract damage from HP.
        }
        else
        {
            iHP = 1;                                            //Set HP at 1.
        }

        changeentityproperty(vSelf, "health", iHP);             //Apply HP to health (crude way to do this, but Andy has no defense ratios).

        killentity(getentityvar(vSelf, SPAWN));                 //Kill last spawned entity.
        if (!iDrop)                                             //Not a knockdown?
        {
            tossentity(vSelf, 2, 1, 0);                         //Toss to ensure fall.
        }    
    }

    dama0002(); //Run primary take damage function.    
}



