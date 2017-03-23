#include	"data/scripts/vars/entity.h"
#include	"data/scripts/com/draw0001.h"
#include	"data/scripts/com/ht0001.h"
#include	"data/scripts/com/spaw0006.h"

void effe0001(int iMap){
	
    /*
    effe0001
    Damon Vaughn Caskey
    09/15/2009
    Spawn and bind effect entity. It might seem like a good idea to run this as part of a takedamage script, 
    but that won't work. At that point the engine has not set defender to appropriate reactive animation yet. 
    Therefore an animation match bind will kill the effect spawn instantly.

    iMap:      Effect map (decides which effect to spawn).
    */
    
    void  vSelf     = getlocalvar("self");						//Caller.
    void  vModel    = "effe0001";								//Model.
    void  vBound    = getentityvar(vSelf, BINDHE);				//Previous effect entity.
    float fRatio	= getentityvar(vSelf, ADSCALER);			//Caller's current scale ratio.
    float fX		= getentityproperty(vSelf, "x");			//Caller X location.
    float fY		= getentityproperty(vSelf, "a");			//Caller Y location.
	float fZ		= getentityproperty(vSelf, "z");			//Caller Z location.
	float fH;													//Caller's Height.
	void  vSpawn;												//New spawn placeholder.
	
	fH = 0.5 * ht0001(vSelf);									//Get center height.

    if (vBound)													//Previous effect entity in place? 
    {
        if (vModel == getentityproperty(vBound, "model")		//Previous same as proposed?
			&& iMap == getentityproperty(vBound, "map"))
		{  
			bindentity(vBound, vSelf, 0, 1, fH, 1, 4);			//Refresh bind.
			return;												//Exit.			
        }
        else
        {
            killentity(vBound);									//Kill old effect.
        }
    }   
    
	vSpawn = spaw0006(vModel, vModel, fX, fY+fH, fZ, iMap, 0);	//Spawn entity.
	
	changeentityproperty(vSpawn, "parent", vSelf);				//Set caller as parent of spawn.   
    setentityvar(vSelf, SPAWN, vSpawn);							//Store spawn.            
    
    bindentity(vSpawn, vSelf, 0, 1, fH, 1, 4);					//Execute bind.
    setentityvar(vSelf, BINDHE, vSpawn);						//Store bind.
    
	changeentityproperty(vSpawn, "alpha", 1);					//Apply alpha mode 1
	    
	draw0001(vSpawn);											//Apply draw.     
		    
    /*
    Get the map for self. It's a better idea to reserve uniform slots for effect maps,
    but so long as maps start from KOMap and up, everything will work.
    iMap = (iMap + getentityproperty(vSelf, "komap", 0)) - 1;
	*/	
    
    changeentityproperty(vSelf, "colourmap", iMap);             //Set caller's effect map.    
}
