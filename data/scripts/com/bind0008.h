#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_draw/main.c"

void bind0008(void vModel, void vAlias, int iMap, int iBlend, float offset_x, float offset_y, int iAZ, int iDir, int iAni, int iFrame, int iKill){

    /*
     bind0008
     Damon Vaughn Caskey
     02/25/2008
     Spawn an entity, place it in location with relation to caller, but do not bind.

     vName:      Model name of spawn.
     vAlias:     Display name of spawn.
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

	// If caller's drawmethod is on, then
	// adjust offsets to caller's current scale.
	if (getdrawmethod(vSelf, "enabled") == 1)
	{
		offset_x = dc_draw_adjust_to_scale_x(vSelf, offset_x);
		offset_x = dc_draw_adjust_to_scale_y(vSelf, offset_y);
	}
    
	// Reverse horizontal adjustment if facing left.
	if (iDir == openborconstant("DIRECTION_LEFT"))
	{ 
		offset_x = -offset_x;   
	}                                             

    if (iMap == -1)                                                         //Map "-1"?
    {
        iMap = getentityproperty(vSelf, "map");                             //Set iMap to callers current map.
    }

    clearspawnentry();                                                      //Clear current spawn entry.
    setspawnentry("name",   vModel);                                        //Aquire spawn entity by name.
    setspawnentry("alias",  vAlias);                                        //Set alias.
    setspawnentry("map",    iMap);                                          //Set color remap.
	setspawnentry("coords", iX + offset_x, iZ + iAZ, iY + offset_y);                  //Spawn location.
    vSpawn = spawn();                                                       //Spawn entity.
    clearspawnentry();                                                      //Clear current spawn entry.

    setentityvar(vSelf, SPAWN, vSpawn);                                     //Store spawn into last spawn variant.
    changeentityproperty(vSpawn, "direction", iDir);
    changeentityproperty(vSpawn, "parent", vSelf);                          //Set caller as parent of spawn.

    setentityvar(vSpawn, ADBLEND, iBlend);                                  //Set transparency.

	// If blend is any enabled value, apply to drawmethod.
	if (iBlend)
	{
		changedrawmethod(vSpawn, "enabled", 1);
		changedrawmethod(vSpawn, "alpha", iBlend);
	}

    dc_draw_z_position_autoscale(vSpawn);                                                       //Update draw for spawn.

    if (iAni)
	{
        changeentityproperty(vSpawn, "animation", iAni);
    }

    changeentityproperty(vSpawn, "autokill", iKill);

    return vSpawn;
}
