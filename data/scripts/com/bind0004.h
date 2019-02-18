#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_kanga/main.c"

void bind0004(void vTar, int iX, int iY, int iZ, int iDir, int iAniFlag){

    /*
    bind0004
    Damon Vaughn Caskey
    03/12/2008
    Basic binding functions. Idea was to consolidate binding to reduce redundant code. Proved very cumbersome
    and will be phased out over time.

    vTar:       Target entity. See targ0001 function.
    iX, iY, iZ: Location offsets.
    iDir:       Facing and bind set:    0   = No change.
                                        1   = Same as self facing.
                                        -1  = Opposite of self
                                        2   = Face right
                                        -2  = Face left.
                                        11  = Release previous bind and delete record of bind.
                                        12  = Release previous bind but store record as if binding normally.
                                        13  = Release previous bind, knock bound entity down to reset it (it may have been stuck
                                              in a looping animation), and delete record of bind.

    iAniFlag:   See http://www.lavalit.com/index.php?topic=963.msg14445#msg14445
    */

    void  vSelf   = getlocalvar("self");           //Calling entity.
    void  vTarget = targ0001(vTar, vSelf);          //Target entity.
    float fRatio;                                  //Caller's current scale ratio.

	// Get binding property.
	void bind = get_entity_property(vTarget, "bind");

    //Check direction flag to apply any special behaviors.
    if (iDir == 11)
    {
		// Remove self as a bind. This effectivly releases the binding.
		set_bind_property(bind, "target", NULL());
    }
    else if (iDir == 12)
    {
		// Remove self as a bind. This effectivly releases the binding.
		set_bind_property(bind, "target", NULL());
    }
    else if (iDir == 13)
    {
		// Remove self as a bind. This effectivly releases the binding.
		set_bind_property(bind, "target", NULL());

		// Knock bound entity down to reset it.
        damageentity(vTarget, vSelf, 0, 100, openborconstant("ATK_NORMAL"));    
    }
    else
    {
		// If caller's drawmethod is on, then
		// adjust offsets to caller's current scale.
		if (getdrawmethod(vSelf, "enabled") == 1)
		{
			iX = dc_kanga_adjust_to_scale_x(vSelf, iX);
			iY = dc_kanga_adjust_to_scale_y(vSelf, iY);
		}
		
		// Enable binding to target on each axis.
		set_bind_property(bind, "mode_x", openborconstant("BIND_MODE_TARGET"));
		set_bind_property(bind, "mode_y", openborconstant("BIND_MODE_TARGET"));
		set_bind_property(bind, "mode_z", openborconstant("BIND_MODE_TARGET"));

		// Set the binding offset.
		set_bind_property(bind, "offset_x", iX);
		set_bind_property(bind, "offset_y", iY);
		set_bind_property(bind, "offset_z", iZ);

		// Set other binding properties.
		set_bind_property(bind, "animation_match", iAniFlag);
		set_bind_property(bind, "direction", iDir);
		set_bind_property(bind, "target", vSelf);
    }
}
