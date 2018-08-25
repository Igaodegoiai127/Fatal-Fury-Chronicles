/*Dust spawn.

Heavy slam dust spawn.

*/

#include "data/scripts/com/bind0008.h"
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
	void	vSpawn;
    
    for (iCount = 0; iCount <= iMaxVar; iCount++)
    {
         setentityvar(vSelf, iCount, NULL());
    }
     
    changeentityproperty(vSelf, "autokill", 1);																//Make sure autokill property is on.
	vSpawn = bind0008("effe0001", "effe0001", 0, 1, 0, 0, 0, 0, openborconstant("ANI_FOLLOW1"), 0, 1);		//Spawn impact effect.
	
	changedrawmethod(vSpawn, "enabled", 1);
	changedrawmethod(vSpawn, "scalex", 384);
	changedrawmethod(vSpawn, "scaley", 384);
	changedrawmethod(vSpawn, "alpha", 1);
	changedrawmethod(vSpawn, "remap", 0);
	
	dc_draw_z_position_autoscale(vSpawn);
    
	//if (vAlias == "0")														//Stage check
    //{
        iBlend  = 1;                                                            //Set blend.
	    iMap	= 0;															//Set map.		    
	    soun0001(SNDIMPH);												        //Set sound.
	    fScaleX = 256;															//X scale.
	    fScaleY = 256;															//Y scale.            
    //}
    
	changedrawmethod(vSelf, "enabled", 1);
	changedrawmethod(vSelf, "scalex", fScaleX);
	changedrawmethod(vSelf, "scaley", fScaleY);
	changedrawmethod(vSelf, "alpha", iBlend);
	changedrawmethod(vSelf, "remap", iMap);
	
	dc_draw_z_position_autoscale(vSelf);    
}


