#include	"data/scripts/vars/entity.h"
#include	"data/scripts/com/draw0001.h"
#include	"data/scripts/com/draw0002.h"
#include	"data/scripts/com/spaw0006.h"

void bind0008(char cModel, char cAlias, int iMap, int iBlend, float fAX, float fAY, int iAZ, int iDir, int iAni, int iFrame, int iKill){
		
    /*
     bind0008
     Damon Vaughn Caskey
     02/25/2008
     Spawn an entity, place it in location with relation to caller, but do not bind.
     
     vModel:     Model name of spawn.
     cAlias:     Display name of spawn. 
     vMap:       Color map of spawn.
     iBlend:     Transparency setting of spawn. 
     fX, fY, fZ: Location offset.
     iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
     */
    
    void  vSpawn;
    void  vSelf  = getlocalvar("self");                                     //Caller.
    float fRatio = getentityvar(vSelf, ADSCALER);                           //Caller's current scale ratio.
    int	  iX     = getentityproperty(vSelf, "x") - openborvariant("xpos");  //Caller X location.
    int	  iZ     = getentityproperty(vSelf, "z");                           //Caller Z location.
    int	  iY     = getentityproperty(vSelf, "a");                           //Caller Y location.
	int	  iDir	 = getentityproperty(vSelf, "direction");					//Caller direction.
	
	if (fAX){ fAX = draw0002(fRatio, fAX); }								//If X adjust, apply scaling to fX.
    if (fAY){ fAY = draw0002(fRatio, fAY); }								//If Y adjust, apply scaling to fY.
    if (!iDir){ fAX = -fAX;   }                                             //Reverse horizontal adjustment if facing left.

    if (iMap == -1)                                                         //Map "-1"?
    { 
        iMap = getentityproperty(vSelf, "map");                             //Set iMap to callers current map.
    }  
    
	iX	+= fAX;																//Add X adjustment.	
	iY	+= fAY;																//Add Y adjustment.
	iZ	+= iAZ;																//Add Z adjustment.

	vSpawn = spaw0006(cModel, cAlias, iX, iY, iZ, iMap, 0);					//Spawn entity.	

    setentityvar(vSelf, SPAWN, vSpawn);                                     //Store spawn into last spawn variant.
    changeentityproperty(vSpawn, "direction", iDir);
    changeentityproperty(vSpawn, "parent", vSelf);                          //Set caller as parent of spawn.	
    
	if(iBlend != -1)
	{
		changeentityproperty(vSpawn, "alpha", iBlend);                      //Set transparency.        
	}
    
    draw0001(vSpawn);                                                       //Update draw for spawn.    

    if (iAni)
	{        
        changeentityproperty(vSpawn, "animation", iAni);
    }

    changeentityproperty(vSpawn, "autokill", iKill);
	
    return vSpawn;
}
