#include "data/scripts/vars/entity.h"
#include "data/scripts/com/bind0008.h"
#include "data/scripts/dc_kanga/main.c"

void bind0009(void vModel, void vAlias, int iMap, int iBlend, float fAX, float fAY, int iAZ, int iDir, int iAni, int iFrame, int iKill, float iScaleX, float iScaleY, int iFlipX, int iFlipY, int iShiftX, int iFill, int iRotate, int iARotat)
{
	
    /*
     bind0009
     Damon Vaughn Caskey
     02/25/2008
     Runs bind0008 and adds draw adjustments.
     
     vName:      Model name of spawn.
     vAlias:     Display name of spawn. 
     vMap:       Color map of spawn.
     iBlend:     Transparency setting of spawn. 
     fX, fY, fZ: Location offset.
     iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
     */
    
    void  vSpawn;
    
	vSpawn = bind0008(vModel, vAlias, iMap, iBlend, fAX, fAY, iAZ, iDir, iAni, iFrame, iKill);
    
    changedrawmethod(vSpawn, "scalex", iScaleX);
	changedrawmethod(vSpawn, "scaley", iScaleY);
	changedrawmethod(vSpawn, "flipx", iFlipX);
	changedrawmethod(vSpawn, "flipy", iFlipY);
	changedrawmethod(vSpawn, "shiftx", iShiftX);
	changedrawmethod(vSpawn, "alpha", iBlend);
	changedrawmethod(vSpawn, "remap", iMap);
	changedrawmethod(vSpawn, "fillcolor", iFill);
	changedrawmethod(vSpawn, "rotate", iRotate);

	//  Set autoratate here.


    dc_kanga_z_position_autoscale(vSpawn);																				    //Update draw for spawn.    

    if (iAni){        
        changeentityproperty(vSpawn, "animation", iAni);
    }

    changeentityproperty(vSpawn, "autokill", iKill);    
    
    return vSpawn;
}
