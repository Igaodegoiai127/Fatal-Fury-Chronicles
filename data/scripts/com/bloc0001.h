#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/entity.h"
#include "data/scripts/com/ani0009.h"
#include "data/scripts/com/parr0001.h"

void bloc0001(){
    
    void vSelf      = getlocalvar("self");                                                  //Calling entity.        
    void vAttacker  = getlocalvar("attacker");                                              //Attacking entity.
    int  iHeight;                                                                           //Caller height.            
    int  iHitY;                                                                             //Last hit Y.    
    int  iAni       = getentityproperty(vSelf, "animationid");                              //Caller animation.
    int  fY;                                                                                //Attacker Y location.
    int  iBase;                                                                             //Attacker base Y.
    int  iBlockAni;                                                                         //Final block animation.
    int  iTime = openborvariant("elapsed_time");                                            //Elapsed game time.
    int  iKeylst = getentityvar(vSelf, KEY1SP);        

    if (parr0001(vAttacker, 0)) { return; }

    //Fatal Fury style proximity blocking. If entity is blocking (not an attack with autoblock), 
    //switch to the appropriate block animation based on height of incomming attack.
    if (iAni == openborconstant("ANI_BLOCK")                                                //In block animation? 
        || iAni == BLOCKNOR
        || iAni == BLOCKLOW
        || iAni == BLOCKMID
        || iAni == BLOCKHIGH)
    {
        iHeight = getentityproperty(vSelf, "height") + getentityproperty(vSelf, "base");    //Get current height + base.
        iHitY   = openborvariant("lasthita");                                               //Get Y axis of last hit.
    
        if (iHitY < iHeight * 0.3)                                                          //Below 30% of height?
        {
            iBlockAni = BLOCKLOW;                                                           //Low block.
        }
        else if (iHitY < iHeight * 0.75)                                                    //Below 75% of height?
        {
            iBlockAni = BLOCKMID;                                                           //Middle block.
        }
        else                                                                                //Attack is at or above 75% of height.
        {
            fY          = getentityproperty(vAttacker, "a");                                //Get attacker height.
            iBase       = getentityproperty(vAttacker, "base");                             //Get attacker base.

            if ((fY - iBase) > 1)                                                           //Attacker airborne?
            {
                iBlockAni = BLOCKHIGH;                                                      //High block.
            }
            else
            {
                iBlockAni = BLOCKNOR;                                                       //Normal block (BLOCKPAIN).                
            }
        }
        
        ani0009(vSelf, iBlockAni, -1);                                                      //Apply block animation.
    }        
}
