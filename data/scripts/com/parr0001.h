#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/entity.h"

int parr0001(void vOpp, int iDam){

    /*
    parr0001
    Damon Vaughn Caskey
    Moved from bloc001 12032009
    Check for block timing and apply parry accordingly.
    
    vOpp: Attacking entity.
    */

    void vSelf      = getlocalvar("self");                                                  //Calling entity.        
    void vOpp;                                                                              //Attacking entity.
    int  iHitY;                                                                             //Last hit Y.    
    int  iAni       = getentityproperty(vSelf, "animationid");                              //Caller animation.
    int  fAY;                                                                               //Attacker Y location.
    int  iABase;                                                                            //Attacker base Y.
    int  iTime = openborvariant("elapsed_time");                                            //Elapsed game time.
    int  iHP;                                                                               //Current health.
    int  iNAni;
	int  iPause;

    if ((iTime) <= 500)                                                           //Block press within .05 seconds?
    {
        if (getentityproperty(vSelf, "animvalid", PARRY))                                   //Have parry animation?
        {            
            vOpp        = getlocalvar("attacker");
            fAY         = getentityproperty(vOpp, "a");                                     //Get attacker height.
            iABase      = getentityproperty(vOpp, "base");                                  //Get attacker base.
        
            setentityvar(vSelf, NEXTANI, PARRY);                                            //Set parry animation (will be activated by onpainscript).
            
            if (iDam)                                                                       //Damage?                 
            {
                iHP = getentityproperty(vSelf, "health");                                   //Get health.
                changeentityproperty(vSelf, "health", iHP + iDam);                          //Nullify damage.                
            }
            	                
	        iNAni   = getentityproperty(vOpp, "nextanim");
	        iPause  = getlocalvar("pauseadd") + 35;

	        changeentityproperty(vOpp, "nextanim", iNAni + iPause);
	        changeentityproperty(vOpp, "nextthink", iNAni + iPause); 
                            
            return 1;
        }        
    }

    return 0;
}
