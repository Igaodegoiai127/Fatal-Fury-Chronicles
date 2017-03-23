#include	"data/scripts/vars/colors.h"     //Color constants.
#include	"data/scripts/vars/entity.h"	//Entity var constants.
#include	"data/scripts/vars/sounds.h"	//Sound group constants.

#include	"data/scripts/com/bind0010.h"	//Grapple binding.
#include	"data/scripts/com/bind0019.h"	//Grapple binding release.
#include	"data/scripts/com/dama0001.h"	//Damage entity.
#include	"data/scripts/com/effe0001.h"	//Damage effects.
#include	"data/scripts/com/hit0001.h"	//Hit flags.
#include	"data/scripts/com/parr0001.h"	//Parry functions.
#include	"data/scripts/com/soun0005.h"	//Stereo sound player.

void dama0002(){
    
    //Main take damage function; called by almost all entities when they take damage.

    void    vSelf       = getlocalvar("self");									//Calling entity. 
    void    vAttacker   = getlocalvar("attacker");								//Damaging entity.
    int     iAType      = getlocalvar("attacktype");							//Incomming attack type.
    int     iDrop       = getlocalvar("drop");									//Incomming attack drop power.
    int     iAni        = getentityproperty(vSelf, "animationid");				//Current animation.
    float   fDam        = 0.0+getlocalvar("damage");                            //Incoming damage.
    float   fHP         = 0.0+getentityproperty(vSelf, "health");               //Hitpoints.
    float	fMaxHP		= 0.0+getentityproperty(vSelf, "maxhealth");			//Max hitpoints.
	int		iD, iI, iF;															//Bound direction setting, index, and frame.
 	int     iAni, iPos, iLnd;													//Animation, frame, land frame. 
	float	fX, fZ;																//X and Z location.
    
    //If attacker is a projectile, set opponent to the attacker's parent.    
    if(getentityproperty(vAttacker, "type") == openborconstant("TYPE_OBSTACLE"))
    {
        if(getentityproperty(vAttacker, "mp"))
        {
            changeentityproperty(vSelf, "opponent", getentityproperty(vAttacker, "parent"));
        }
    }    

    hit0001(0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);							//Erase hit flags.

	bind0019(vSelf);															//Release all grappled entities.		
	
	if (!fDam){ return; }														//If damage isn't "real", forget the rest.

    //if (parr0001(vAttacker, fDam)) { return; }									//Parry for unblockable attack. See parr0001 for details.    

    if(fHP > 0)																	//Damage is survivable?                                                         
	{
		iAni = getentityproperty(vSelf, "animationid");							//Get animation.
		iPos = getentityproperty(vSelf, "animpos");								//Get current frame.
		iLnd = getentityproperty(vSelf, "landframe", iAni);						//Get landframe.

        if (iPos != iLnd)														//Not landing?
        {   
            if (iDrop > 0)                                                      //Knockdown hit?
		    {
				if (iAType == openborconstant("ATK_BURN") 
                    && iAni != openborconstant("ANI_BURN"))                     //Burn hit and not already burning?
			    {         
				    soun0005(vSelf, VOIBRN, -1, 1, 0, 0);						//Burn sound.					
			    }
			    else
			    {
				    if ((fHP / fMaxHP) <= 0.25 )								//Damage below 25% max health?                        
				    {						
					    soun0005(vSelf, VOIDYN, -1, 1, 0, 0);		            //Dying sound (always).                        
				    }
				    else
				    {
						soun0005(vSelf, VOIPN, -1, 1, 0, 0);					//Pain sound (always).					    						
				    }
			    }
		    }
		    else
		    {
				soun0005(vSelf, VOIPN, -1, 0.5, 0, 0);							//Pain sound (50%).							
		    }
        }
        else
        {			
		    if ((fHP / fMaxHP) <= 0.25 )										//Damage below 25% max health?                        
		    {
			    soun0005(vSelf, VOIDYN, -1, 1, 0, 0);							//Dying sound (always). 
		    }
		    else
		    {
			    soun0005(vSelf, VOIPN, -1, 1, 0, 0);							//Pain sound (always).						
		    }		    
	    }
	}
	else
	{	

		fX	= getentityproperty(vSelf, "x");									//Get X location.
		fZ	= getentityproperty(vSelf, "z");									//Get Z location.

		if(checkhole(fX, fZ))													//In a pit?
		{
			soun0005(vSelf, VOIPIT, -1, 1, 0, 0);								//Pit KO sound (always).
		}
		else
		{
			soun0005(vSelf, VOIDIE, -1, 1, 0, 0);								//KO sound (always). 
		}
	}    
} 
