#include "data/scripts/vars/entity.h"

void draw0004(float iScaleX, float iScaleY, int iFlipX, int iFlipY, int iShiftX, int iBlend, int iRemap, int iFill, int iRotate, int iARotat){

     /*
     draw0002
     Damon Vaughn Caskey
     01/25/2008
     Sets passed drawmethod parameters to caller.
     */
     
     void vSelf = getlocalvar("self"); //Caller.
     
            
     setentityvar(vSelf, ADSCALEX,    iScaleX);		//iScaleX adjustment.
     setentityvar(vSelf, ADSCALEY,    iScaleY);		//iScaleY adjustment.
     setentityvar(vSelf, ADFLIPX,     iFlipX);		//Flip X.
     setentityvar(vSelf, ADFLIPY,     iFlipY);		//Flip Y.
     setentityvar(vSelf, ADSHIFTX,    iShiftX);		//Shift X.     
	 changeentityproperty(vSelf, "alpha", iBlend); //Set transparency.
     setentityvar(vSelf, ADREMAP,     iRemap);		//Remap.
     setentityvar(vSelf, ADFILL,      iFill);		//Fill color.
     setentityvar(vSelf, ADROTATE,    iRotate);		//Rotate.
     setentityvar(vSelf, ADAROTAT,    iARotat);		//Auto rotation
        
}
