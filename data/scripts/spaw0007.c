/*Dust spawn.

Manipulate jumpstart/jumpframe "dust" entity to produce appropriate visual and sound effects.

*/

#include "data/scripts/vars/sounds.h"
#include "data/scripts/dc_draw/main.c"
#include "data/scripts/com/draw0005.h"
#include "data/scripts/com/soun0001.h"

void main(){

    void    vSelf   = getlocalvar("self");    
    int     iCount;
    int     iMaxVar = openborvariant("maxentityvars");
    int     iMap;
    float   fScaleX;
	float   fScaleY;
	int	    iBlend;
    
    for (iCount = 0; iCount <= iMaxVar; iCount++)
    {
         setentityvar(vSelf, iCount, NULL());
    }
     
    changeentityproperty(vSelf, "autokill", 1);                                 //Make sure autokill property is on.
    
    //if (vAlias == "0")															//Stage check
    //{
        iBlend  = 1;                                                            //Set blend.
	    iMap	= 0;															//Set map.		    
	    soun0001(SNDLAND);												        //Set sound.
	    fScaleX = 0.5;															//X scale.
	    fScaleY = 0.5;															//Y scale.            
    //}
	            
    draw0005(vSelf, fScaleX, fScaleY, 0, 0, 0, iBlend, iMap, 0, 0, 0);
    dc_draw_z_position_autoscale(vSelf);    
}


