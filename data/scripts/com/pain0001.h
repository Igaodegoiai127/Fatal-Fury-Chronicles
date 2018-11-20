#include "data/scripts/vars/colors.h"
#include "data/scripts/vars/entity.h"
#include "data/scripts/com/effe0001.h"
#include "data/scripts/dc_kanga/main.c"


void pain0001(){

    void    vSelf       = getlocalvar("self");                                      //Calling entity.
    int     iAni        = getentityproperty(vSelf, "animationid");                  //Pain animation.
    int     iHeight;                                                                //Caller height.
    int     iHitY;                                                                  //Hit Y.
    int     iNAni       = getentityvar(vSelf, NEXTANI);                             //Next animation request.

    if (iAni == openborconstant("ANI_BURNPAIN"))                                    //Burn attack?
    {
        effe0001(MAPBURN);                                                          //Set effect.
        setentityvar(vSelf, ADREMAP, MAPBURN);                                      //Set burn effect map.
        dc_kanga_z_position_autoscale(vSelf);                                                            //Update draw
    }
   // else if (iAni == openborconstant("ANI_SPAIN"))                                  //Shock attack?
    //{
    //}
    else if (iAni == openborconstant("ANI_GRABBED"))                                //Grab?
    {
    }
    else                                                                            //Normal attack#?
    {
        iHitY   = openborvariant("lasthita");                                       //Get hit Y.
        iHeight = getentityproperty(vSelf, "height");                               //Get caller height.

        if (iHitY < iHeight * 0.75)                                                 //Hit below 75% of height?
        {
            changeentityproperty(vSelf, "animation", openborconstant("ANI_PAIN2")); //Middle pain
        }
    }
}
