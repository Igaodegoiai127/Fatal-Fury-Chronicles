#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_draw/main.c"

void bind0012(void vTarget){

    /*
    bind0012
	Damon Vaughn Caskey
	06/20/2007
	Syncronizes target with caller's location with hit flags.
    */

    void  vSelf     = getlocalvar("self");                              //Calling entity.
    int   iWarpT    = getentityvar(vSelf, HITWRT);                      //Warp condition.
    float fX        = getentityvar(vSelf, HITWRX);                      //Warp X adjustment.
    float fY        = getentityvar(vSelf, HITWRY);                      //Warp X adjustment.
    float fZ        = getentityvar(vSelf, HITWRZ);                      //Warp X adjustment.
    float fRatio;                                                       //Caller's current scale ratio.

    if (fX || fY || fZ)                                                 //Any warp flags at all?
    {
        if (iWarpT)                                                     //Any warp condition?
        {
            setentityvar(vTarget, WARPX, fX);                           //Warp X adjustment.
            setentityvar(vTarget, WARPY, fY);                           //Warp Y adjustment.
            setentityvar(vTarget, WARPZ, fZ);                           //Warp Z adjustment.
            setentityvar(vTarget, WARPT, iWarpT);                       //Set warp condition.
        }
        else
        {
            fRatio = getentityvar(vSelf, ADSCALER);                     //Get caller's current scale ratio.

            if(!fX) fX = 0;                                             //If Null, initialize to 0.
            if(!fY) fY = 0;                                             //If Null, initialize to 0.
            if(!fZ) fZ = 0;                                             //If Null, initialize to 0.

            if (getentityproperty(vTarget, "direction"))                //Facing left?
            {
                fX = -fX;                                               //Reverse X adjustment.
            }

            fX = (fX * fRatio) + getentityproperty(vSelf, "x");         //Apply requested X offset to X location and apply zoom scale.
            fY = (fY * fRatio) + getentityproperty(vSelf, "a");         //Apply requested Y offset to Y location and apply zoom scale.
            fZ = fZ + getentityproperty(vSelf, "z");                    //Apply requested Z offset.

            changeentityproperty(vTarget, "position", fX, fZ, fY);      //Set target postion.

            dc_draw_z_position_autoscale(vTarget);                                          //Refresh target's draw values.
        }
    }
}
