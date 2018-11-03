/*Dust spawn.

Manipulate land "dust" entity to produce appropriate visual and sound effects.

*/

#include "data/scripts/vars/sounds.h"
#include "data/scripts/dc_draw/main.c"
#include "data/scripts/dc_sound/main.c"

void main(){

    void    vSelf   = getlocalvar("self");    
    int     iCount;
    int     iMaxVar = openborvariant("maxentityvars");
    int     iMap;
    float   fScaleX;
	float   fScaleY;
	int	    iBlend;
    
     
    changeentityproperty(vSelf, "autokill", 1);                                 //Make sure autokill property is on.
    
    //if (vAlias == "0")															//Stage check
    //{
        iBlend  = 1;                                                            //Set blend.
	    iMap	= 0;															//Set map.		    
	    // stereo_sound_command_here(SNDLAND);												        //Set sound.
	    fScaleX = 0.5;															//X scale.
	    fScaleY = 0.5;															//Y scale.            
    //}
	            
    
		changedrawmethod(vSelf, "enabled", 1);
		changedrawmethod(vSelf, "scalex", fScaleX);
		changedrawmethod(vSelf, "scaley", fScaleY);
		changedrawmethod(vSelf, "alpha", iBlend);
		changedrawmethod(vSelf, "remap", iMap);

    dc_draw_z_position_autoscale(vSelf);    
}


