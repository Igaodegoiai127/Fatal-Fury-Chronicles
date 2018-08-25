/*Dust spawn.

Manipulate jumpstart/jumpframe "dust" entity to produce appropriate visual and sound effects.

*/

#include "data/scripts/vars/sounds.h"
#include "data/scripts/dc_draw/main.c"
#include "data/scripts/com/soun0001.h"

void main(){

    void    vSelf   = getlocalvar("self");    
    int     iCount;
    int     iMaxVar = openborvariant("maxentityvars");
    int     iMap;
    float   fScaleX;
	float   fScaleY;
	int	    iBlend;
     
    changeentityproperty(vSelf, "autokill", 1);                                 //Make sure autokill property is on.
    
    //if (vAlias == "0")														//Stage check
    //{
        iBlend  = 1;                                                            //Set blend.
	    iMap	= 0;															//Set map.		    
	    soun0001(SNDJUMP);												        //Set sound.
	    fScaleX = 128;															//X scale.
	    fScaleY = 128;															//Y scale.            
    //}
	            
	changedrawmethod(vSelf, "enabled", 1);
	changedrawmethod(vSelf, "scalex", fScaleX);
	changedrawmethod(vSelf, "scaley", fScaleY);
	changedrawmethod(vSelf, "alpha", iBlend);
	changedrawmethod(vSelf, "remap", iMap);
	
    dc_draw_z_position_autoscale(vSelf);    
}


