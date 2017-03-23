#include "data/scripts/vars/entity.h"

void draw0005(void vTarget, float iScaleX, float iScaleY, int iFlipX, int iFlipY, int iShiftX, int iBlend, int iRemap, int iFill, int iRotate, int iARotat){

     /*
     draw0002
     Damon Vaughn Caskey
     01/25/2008
     Sets passed drawmethod parameters to target.
     */
         
            
     setentityvar(vTarget, ADSCALEX,    iScaleX);		//iScaleX adjustment.
     setentityvar(vTarget, ADSCALEY,    iScaleY);		//iScaleY adjustment.
     setentityvar(vTarget, ADFLIPX,     iFlipX);		//Flip X.
     setentityvar(vTarget, ADFLIPY,     iFlipY);		//Flip Y.
     setentityvar(vTarget, ADSHIFTX,    iShiftX);		//Shift X.
     changeentityproperty(vTarget, "alpha", iBlend);	//Set transparency.
     setentityvar(vTarget, ADREMAP,     iRemap);		//Remap.
     setentityvar(vTarget, ADFILL,      iFill);			//Fill color.
     setentityvar(vTarget, ADROTATE,    iRotate);		//Rotate.
     setentityvar(vTarget, ADAROTAT,    iARotat);		//Auto rotation
        
}

