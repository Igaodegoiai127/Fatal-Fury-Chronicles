#include "data/scripts/vars/entity.h"
#include "data/scripts/com/draw0002.h"

void draw0001(void vTarget){

    /*
    draw0001()
    Damon Vaughn Caskey
    01/25/2008
    Applies requested draweffects and autozoom to all valid entities. The overall effect is to cause an entity to shirink as it
    moves "away" from the player's viewpoint and expand as it moves toward the player's vantage, similar to many Neo-Geo games.

    1. Zoom ratio is stored as entity variable for later use, and applied to ScaleX/ScaleY parameters of setdrawmthod for entity.
    2. This function will overidde other uses of drawmethod. Therfore values are taken and applied from entity variables stored
    by other functions to control other setdrawmethod parameters. This includes manual adjustment of scale values if desired.
    3. Autozoom variance is controlled by fMinZ * X. By changing the value of fMax, it is also possible to change the Z location in
    which entity is shown at its normal size.
    */

    float fScaleX   = getentityvar(vTarget, ADSCALEX);              //X scale adjustment.
    float fScaleY   = getentityvar(vTarget, ADSCALEY);              //Y scale adjustment.
    int   iFlipX    = getentityvar(vTarget, ADFLIPX);               //Flip X.
    int   iFlipY    = getentityvar(vTarget, ADFLIPY);               //Flip Y.
    int   iShiftX   = getentityvar(vTarget, ADSHIFTX);              //Shift X.
    int   iBlend    = getentityvar(vTarget, ADBLEND);               //Blend.
    int   iRemap    = getentityvar(vTarget, ADREMAP);               //Remap.
    int   iFill     = getentityvar(vTarget, ADFILL);                //Fill.
    int   iRotate   = getentityvar(vTarget, ADROTATE);              //Rotate.
    int   iARotat   = getentityvar(vTarget, ADAROTAT);              //Auto Rotation.
    float fMinZ     = openborconstant("PLAYER_MIN_Z") * 1.1;        //Minimum Z location * Zoom factor.
    float fDeltaZ   = (openborconstant("PLAYER_MAX_Z")) - fMinZ;    //Range betwen fMinZ and MaxZ
    float fFactor;                                                  //Autozoom calculation placeholder.

    fFactor  = getentityproperty(vTarget, "z") - fMinZ; //Distance of caller from fMinZ.
    fFactor /= fDeltaZ;                                 //Resolve Delta (midpoint) value.
    fFactor *= 0.1;                                     //Set scale to .9 thru 1
    fFactor += 0.9;                                     //Resolve %.
    setentityvar(vTarget, ADSCALER, fFactor);           //Store scale ratio for use by sub entity (shooting, spawning, binding etc.) functions.
    fFactor *= 256;                                     //% of maximum size.

    if (iARotat)
    {
        iRotate = iRotate + iARotat;
        setentityvar(vTarget, ADROTATE, iRotate);
    }

    //If ScaleX Adjustment provided, apply it with autozoom factor.
    if (fScaleX)
    {
        fScaleX = draw0002(fFactor, fScaleX);
    }
    else
    {
        fScaleX = fFactor;
    }

    //If ScaleY Adjustment provided, apply it with autozoom factor.
    if (fScaleY)
    {
        fScaleY = draw0002(fFactor, fScaleY);
    }
    else
    {
        fScaleY = fFactor;
    }

    if (iRotate)
    {
        if (!getentityproperty(vTarget, "direction"))
        {
            iRotate = -iRotate;
        }
    }

    //If Values are not available, apply defaults.
    if (!iFlipX)  { iFlipX  = 0;    }   //FlipX.
    if (!iFlipY)  { iFlipY  = 0;    }   //FlipY.
    if (!iShiftX) { iShiftX = 0;    }   //ShiftX.
    if (!iBlend)  { iBlend  = 0;    }   //Alpha.
    if (!iRemap)  { iRemap  = -1;   }   //Remap.
    if (!iFill)   { iFill   = 0;    }   //Fill.
    if (!iRotate) { iRotate = 0;    }   //Fill.

    setdrawmethod(vTarget, 1, fScaleX, fScaleY, iFlipX, iFlipY, iShiftX, iBlend, iRemap, iFill, iRotate);  //Set final values to drawmethod.

}
