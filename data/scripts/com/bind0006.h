#include "data/scripts/vars/entity.h"
#include "data/scripts/com/bind0003.h"
#include "data/scripts/com/draw0001.h"

void bind0006(void vName, void vAlias, void vMap, int iBlend, int iX, int iY, int iZ, int iDir, int iAniFlag, float fScaleX, float fScaleY, int iFlipX, int iFlipY, int iShiftX, int iFill, int iRotate){
	
    /*
    bind0006
    Damon Vaughn Caskey
    02/25/2008
    Performs bind0003 functions and adds draw adjustments.

    vName:      Model name of spawn.
    vAlias:     Display name of spawn. 
    vMap:       Color map of spawn.
    iBlend:     Transparency setting of spawn. 
    fX, fY, fZ: Location offset of binding.
    iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
    iAniFlag:   See http://www.lavalit.com/index.php?topic=963.msg14445#msg14445
    */

    void vTarget = bind0003(vName, vAlias, vMap, iBlend, iX, iY, iZ, iDir, iAniFlag);
        
    setentityvar(vTarget, ADSCALEX,   fScaleX);   //iScaleX adjustment.
    setentityvar(vTarget, ADSCALEY,   fScaleY);   //iScaleY adjustment.
    setentityvar(vTarget, ADFLIPX,    iFlipX);    //Flip X.
    setentityvar(vTarget, ADFLIPY,    iFlipY);    //Flip Y.
    setentityvar(vTarget, ADSHIFTX,   iShiftX);   //Shift X.
    setentityvar(vTarget, ADFILL,     iFill);     //Fill color.
    setentityvar(vTarget, ADROTATE,   iRotate);   //Rotate.

    dc_draw_z_position_autoscale(vTarget);                            //Run draw to imediatly apply adjustments.        
}