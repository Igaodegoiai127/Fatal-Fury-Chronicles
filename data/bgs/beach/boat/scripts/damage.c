#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/colors.h"
#include "data/scripts/vars/entity.h"
#include "data/scripts/com/bind0007.h"
#include "data/scripts/com/dama0001.h"

//Sound beach boat damage.

void main()
{
    void    vSelf      = getlocalvar("self");                               //Calling entity. 
    void    vAttacker  = getlocalvar("attacker");                           //Damaging entity.
    int     iFall      = getentityproperty(vAttacker, "aiflag", "falling"); //Falling flag.
    void	vSpawn;
	int     iXDir;
    int     iXVel;
    int     iZVel;
    int     iDir;

    if (iFall)																						//Falling?
    {        
        iXDir		= getentityproperty(vSelf, "xdir");												//Get current X velocity.			

		if (iXDir >= 0)																				//Moving Right?
		{
			iDir	= 2;																			//Set facing right.
			iXVel	= -1.5;																			//Set movement left.
            iZVel   = -0.1;
            
		}
		else																						//Moving left.
		{
			iDir	= -2;																			//Set facing left.
			iXVel	= 1.5;																			//Set movement right.
			iZVel   = -0.1;
        }			
		
		dama0001(vAttacker, 0, 100, openborconstant("ATK_NORMAL6"), iDir, 0, 0, 0, 0, 0, 0);	    //Apply damage to self.
		changeentityproperty(vAttacker, "animation", FWATER);					                    //Reset fall animation.
		tossentity(vAttacker, 2.5, iXVel, iZVel);												    //Apply toss values.			       
    }      

	if (!getentityvar(vSelf, SPAWN))
	{
		vSpawn = bind0007("effe0001", "effe0001", 12, 1, 0, 50, 3, 0, openborconstant("ANI_FOLLOW12"), 0, 0, 0);			//Spawn fire.
		changeentityproperty(vSpawn, "setlayer", -7);                                                                       //Set fire layer.
	}
}

