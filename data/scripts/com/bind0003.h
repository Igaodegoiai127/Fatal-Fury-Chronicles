#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_draw/main.c"
void bind0003(void vModel, int vAlias, int iMap, int iBlend, float fX, float fY, float fZ, int iDir, int iAniFlag){

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
    float fRatio = getentityvar(vSelf, ADSCALER);                           //Caller's current scale ratio.
    int   iX     = getentityproperty(vSelf, "x") - openborvariant("xpos");  //Caller X location.
    int   iZ     = getentityproperty(vSelf, "z");                           //Caller Z location.
    int   iY     = getentityproperty(vSelf, "a");                           //Caller Y location.

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

    setentityvar(vSelf, SPAWN, vSpawn);                                     //Store spawn into last spawn variant.
    setentityvar(vSelf, BINDE, vSpawn);                                     //Store into bind variant.

    changeentityproperty(vSpawn, "parent", vSelf);                          //Set caller as parent of spawn.

    setentityvar(vSpawn, ADBLEND, iBlend);                                  //Set transparency.

	// If caller's drawmethod is on, then
	// adjust offsets to caller's current scale.
	if (getdrawmethod(vSelf, "enabled") == 1)
	{
		fX = dc_draw_adjust_to_scale_x(vSelf, fX);
		fY = dc_draw_adjust_to_scale_y(vSelf, fY);
	}

	// Get binding property for spawn.
	void binding = get_entity_property(vSpawn, "binding");

	// Get binding toggle and enable flags.
	void binding_enable = get_binding_property(binding, "enable");
	void binding_axis = get_binding_property(binding, "offset");

	// Enable binding on each axis.
	set_axis_principal_int_property(binding_enable, "x", 1);
	set_axis_principal_int_property(binding_enable, "y", 1);
	set_axis_principal_int_property(binding_enable, "z", 1);

	// Set the binding offset.
	set_axis_principal_int_property(binding_axis, "x", fX);
	set_axis_principal_int_property(binding_axis, "y", fY);
	set_axis_principal_int_property(binding_axis, "z", fZ);

	// Set other binding properties.
	set_binding_property(binding, "matching", iAniFlag);
	set_binding_property(binding, "direction", iDir);
	set_binding_property(binding, "target", vSelf);
	set_binding_property(binding, "sort_id", 1);

    dc_draw_z_position_autoscale(vSpawn);                                                       //Update draw for spawn.

    return vSpawn;                                                          //Return spawned entity.
}

