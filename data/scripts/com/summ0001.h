#include	"data/scripts/vars/entity.h"
#include	"data/scripts/com/spaw0006.h"

void summ0001(char cModel, char cAlias, int iMap, int iBlend, int iX, int iY, int iZ, int iDir, int iAni, int iFrame, int iKill){
	
    /*
     summ0001
     Damon Vaughn Caskey
     02/25/2008
     Spawn an entity in relation to screen position, no draw adjustments.
     
     cModel:     Model name of spawn.
     cAlias:     Display name of spawn. 
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
        
	vSpawn = spaw0006(cModel, cAlias, iX, iY, iZ, iMap, 0);					//Spawn entity.

    setentityvar(vSelf, SPAWN, vSpawn);                                     //Store spawn into last spawn variant.
    changeentityproperty(vSpawn, "direction", iDir);
    changeentityproperty(vSpawn, "parent", vSelf);                          //Set caller as parent of spawn.	
    
	if(iBlend != -1)
	{
		changeentityproperty(vSpawn, "alpha", iBlend);							//Set transparency.        
	}

    //draw0001(vSpawn);                                                     //Update draw for spawn.    

    if (iAni)
	{        
        changeentityproperty(vSpawn, "animation", iAni);
    }

    changeentityproperty(vSpawn, "autokill", iKill);

    return vSpawn;
}
