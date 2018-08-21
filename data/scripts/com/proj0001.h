#include "data/scripts/vars/entity.h"
#include "data/scripts/com/proj0002.h"

void proj0001(void vName, float fX, float fZ, float fY, float iXSpeed, float iYSpeed, float iZSpeed, int iType, int iPType, int iScaleX, int iScaleY, int iFlipX, int iFlipY, int iShiftX, int iBlend, int iMap, int iFill, int iRotate, int iFlip){
     	
    /*
    proj0001
    Damon Vaughn Caskey
    02/11/2008
    Launch projectile with all draw adjustments.

    vName:         projectile model name.
    fX, fY, fZ:    Spawn location adjustment.
    iX/Y/ZSpeed:   Speed adjustment of projectile (as of 02112008, X speed is ignored for knife types).
    iType:         Unknown.
    iPType:        Projectile launch type. 0 = knife, 1 = bomb.

    See dc_draw_z_position_autoscale() for following:
    iScaleX adjustment.
    iScaleY adjustment.
    Flip X.
    Flip Y.
    Shift X.
    Alpha.
    iMap.
    Fill color.
    Rotation.     
    */
        
    void vProj = proj0002(vName, fX, fZ, fY, iXSpeed, iYSpeed, iZSpeed, iType, iPType, iFlip);  //Call proj0001 to do basic projectile launch.
    int  iDir  = getentityproperty(vProj, "direction");                                         //Projectile's direction. This will have already been set up by proj0002 function.

    changeentityproperty(vProj, "map", iMap);   //Set remap color.

    //Store settings for draw function.                     
    if (iScaleX){ setentityvar(vProj, ADSCALEX, iScaleX); }     //iScaleX adjustment.
    if (iScaleY){ setentityvar(vProj, ADSCALEY, iScaleY); }     //iScaleY adjustment.
    if (iFlipX) { setentityvar(vProj, ADFLIPX,  iFlipX);  }     //Flip X.
    if (iFlipY) { setentityvar(vProj, ADFLIPY, iFlipY);   }     //Flip Y.
    if (iShiftX){ setentityvar(vProj, ADSHIFTX, iShiftX); }     //Shift X.
    if (iBlend) { setentityvar(vProj, ADBLEND, iBlend);   }     //Alpha.
    if (iMap)   { setentityvar(vProj, ADREMAP, iMap);     }     //Remap.
    if (iFill)  { setentityvar(vProj, ADFILL, iFill);     }     //Fill color.   
    
    if (iRotate)
    {    
       if (!iDir) { iRotate = -iRotate; }                       //Reverse rotation.
       setentityvar(vProj, ADROTATE, iRotate);                  //Set Rotation.    
    }
}
