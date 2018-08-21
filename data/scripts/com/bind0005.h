#include "data/scripts/vars/entity.h"
#include "data/scripts/com/draw0001.h"

void bind0005(void vTarget, int iCond){

    /*
    hitwarp
	Damon Vaughn Caskey
	06/20/2007
	Syncronizes self with vTarget's location using hit flags.
    */

    void  vSelf     = getlocalvar("self");                              //Calling entity.
    int   iWarpT    = getentityvar(vSelf, WARPT);                       //Warp condition.
    float fX;                                                           //Warp X adjustment.
    float fY;                                                           //Warp X adjustment.
    float fZ;                                                           //Warp X adjustment.
    float fRatio;                                                       //Caller's current scale ratio.

    if (iWarpT == iCond)                                                //Conditional flag match?
    {
        fX      = getentityvar(vSelf, WARPX);                           //Get warp X adjustment.
        fY      = getentityvar(vSelf, WARPY);                           //Get warp Y adjustment.
        fZ      = getentityvar(vSelf, WARPZ);                           //Get warp Z adjustment.
        fRatio  = getentityvar(vTarget, ADSCALER);                      //Get targets's current scale ratio.

        if(!fX) fX = 0;                                                 //If Null, initialize to 0.
        if(!fY) fY = 0;                                                 //If Null, initialize to 0.
        if(!fZ) fZ = 0;                                                 //If Null, initialize to 0.

        if (getentityproperty(vSelf, "direction"))                      //Facing left?
        {
            fX = -fX;                                                   //Reverse X adjustment.
        }

        fX = (fX * fRatio) + getentityproperty(vTarget, "x");           //Apply requested X offset to X location and apply zoom scale.
        fY = (fY * fRatio) + getentityproperty(vTarget, "a");           //Apply requested Y offset to Y location and apply zoom scale.
        fZ += getentityproperty(vTarget, "z");                          //Apply requested Z offset.

        changeentityproperty(vSelf, "position", fX, fZ, fY);            //Set callers's postion.
        dc_draw_z_position_autoscale(vSelf);                                                //Refresh callers's draw values.
    }

    setentityvar(vSelf, WARPX, NULL());
    setentityvar(vSelf, WARPY, NULL());
    setentityvar(vSelf, WARPZ, NULL());
    setentityvar(vSelf, WARPT, NULL());
}
