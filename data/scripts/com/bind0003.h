#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_kanga/main.c"

void bind0003(void vModel, int vAlias, int iMap, int iBlend, int fX, int fY, int fZ, int iDir, int iAniFlag)
{
	

    /*
    bind0003
    Damon Vaughn Caskey
    02/25/2008
    Spawn an entity and then bind it to caller; primarly special effects.

    vName:      Model name of spawn.
    vAlias:     Display name of spawn.
    vMap:       Color map of spawn.
    iBlend:     Transparency setting of spawn.
    fX, fY, fZ: Location offset of binding.
    iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
    iAniFlag:   See http://www.lavalit.com/index.php?topic=963.msg14445#msg14445
    */

    void  vSpawn;
    void  vSelf  = getlocalvar("self");                                     //Caller.
    void  vBinde = getentityvar(vSelf, BINDE);                              //Previous bound entity.
    float   iX     = getentityproperty(vSelf, "x") - openborvariant("xpos");  //Caller X location.
	float   iZ     = getentityproperty(vSelf, "z");                           //Caller Z location.
	float   iY     = getentityproperty(vSelf, "y");                           //Caller Y location.

	if (vBinde && getentityproperty(vBinde, "exists"))                      //Previously bound entity in place?
    {
		if (getentityproperty(vBinde, "name") == vAlias)                    //Alias of previous same as new?
        {
			killentity(vBinde);                                             //Kill previous.
        }
    }

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

    changeentityproperty(vSpawn, "parent", vSelf);                          //Set caller as parent of spawn.

	// If caller's drawmethod is on, then
	// adjust offsets to caller's current scale.
	if (getdrawmethod(vSelf, "enabled") == 1)
	{
		fX = dc_kanga_adjust_to_scale_x(vSelf, fX);
		fY = dc_kanga_adjust_to_scale_y(vSelf, fY);
	}
	
	// Get binding property for spawn.
	void bind = get_entity_property(vSpawn, "bind");

	
	// Enable binding to target on each axis.
	set_bind_property(bind, "mode_x", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_y", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_z", openborconstant("BIND_MODE_TARGET"));

	// Set the binding offset.
	set_bind_property(bind, "offset_x", fX);
	set_bind_property(bind, "offset_y", fY);
	set_bind_property(bind, "offset_z", fZ);

	// Set other binding properties.
	set_bind_property(bind, "animation_match", iAniFlag);
	set_bind_property(bind, "direction", iDir);
	set_bind_property(bind, "target", vSelf);
	
	set_bind_property(bind, "sort_id", 1);

	// Update draw for spawn.
    //dc_kanga_z_position_autoscale(vSpawn); 

	//update_bind(vSpawn);

	return vSpawn;
}

