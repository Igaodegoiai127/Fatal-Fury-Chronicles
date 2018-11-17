#include "data/scripts/vars/entity.h"

void summ0001(void vModel, void vAlias, int iMap, int iBlend, int iX, int iY, int iZ, int iDir, int iAni, int iFrame, int iKill){
	
    /*
     summ0001
     Damon Vaughn Caskey
     02/25/2008
     Spawn an entity in relation to screen position, no draw adjustments.
     
     vName:      Model name of spawn.
     vAlias:     Display name of spawn. 
     vMap:       Color map of spawn.
     iBlend:     Transparency setting of spawn. 
     fX, fY, fZ: Location offset.
     iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
     */
    
    void  vSpawn;
    void  vSelf  = getlocalvar("self");                                     //Caller.
    
    //iX     = iX - openborvariant("xpos");                                 //Caller X location.
    	
    if (iMap == -1)                                                         //Map "-1"?
    { 
        iMap = getentityproperty(vSelf, "map");                             //Set iMap to callers current map.
    }  
    
    clearspawnentry();                                                      //Clear current spawn entry.
    setspawnentry("name",   vModel);                                        //Aquire spawn entity by name.
    setspawnentry("alias",  vAlias);                                        //Set alias.
    setspawnentry("map",    iMap);                                          //Set color remap.
	setspawnentry("coords", iX, iZ, iY);                                    //Spawn location.
    vSpawn = spawn();                                                       //Spawn entity.
    clearspawnentry();                                                      //Clear current spawn entry.
        
    setentityvar(vSelf, SPAWN, vSpawn);                                     //Store spawn into last spawn variant.
    changeentityproperty(vSpawn, "direction", iDir);
    changeentityproperty(vSpawn, "parent", vSelf);                          //Set caller as parent of spawn.
	
    setentityvar(vSpawn, ADBLEND, iBlend);                                  //Set transparency.        
    
    //dc_kanga_z_position_autoscale(vSpawn);                                                     //Update draw for spawn.    

    if (iAni)
	{        
        changeentityproperty(vSpawn, "animation", iAni);
    }

    changeentityproperty(vSpawn, "autokill", iKill);

    return vSpawn;
}
