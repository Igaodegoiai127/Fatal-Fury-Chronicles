#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/entity.h"
#include "data/scripts/com/draw0001.h"
#include "data/scripts/vars/frames.h"

void bind0010(void vTar, int iX, int iY, int iZ, int iDir, int iFrame){

    /*
    bind0010
    Damon Vaughn Caskey
    12/31/2008
    Bind target to caller and set bound entity's animation frame.

    vTar:       Target entity. See targ0001 function.
    iX, iY, iZ: Location offsets.
    iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
    vAni:       Animation for bound entity.
    */

    void  vSelf   = getlocalvar("self");                //Calling entity.
    void  vTarget = targ0001(vTar, vSelf);               //Target entity.
    float fRatio  = getentityvar(vSelf, ADSCALER);      //Caller's current scale ratio.

    if (vTarget){
        fRatio      = getentityvar(vSelf, ADSCALER);                        //Get caller's current scale ratio.

        if (iX){ iX = draw0002(fRatio, iX); }                           //If X bind, apply scaling to fX.
        if (iY){ iY = draw0002(fRatio, iY); }                           //If Y bind, apply scaling to fY.

        bindentity(vTarget, vSelf, iX, iZ, iY, iDir, 0);                    //Execute bind.
        setentityvar(vSelf, BIND, vTarget);                                 //Make record of binding.

        dc_draw_z_position_autoscale(vTarget);

        performattack(vTarget, DEFPOSE, 1);
        changeentityproperty(vTarget, "animpos", iFrame);

        /*
        Reset engine's lasthit variants. Otherwise, target will assume sweep values when
        knocked down if last normal attack hit low.
        */
        changeopenborvariant("lasthitx", 0);
        changeopenborvariant("lasthita", 0);
        changeopenborvariant("lasthitz", 0);
        changeopenborvariant("lasthitt", 0);
    }
}

