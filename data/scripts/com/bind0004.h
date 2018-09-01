#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_draw/main.c"

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
	void binding = get_entity_property(vTarget, "binding");

    //Check direction flag to apply any special behaviors.
    if (iDir == 11)
    {
		// Remove self as a bind. This effectivly releases the binding.
		set_binding_property(binding, "target", NULL());
    }
    else if (iDir == 12)
    {
		// Remove self as a bind. This effectivly releases the binding.
		set_binding_property(binding, "target", NULL());
    }
    else if (iDir == 13)
    {
		// Remove self as a bind. This effectivly releases the binding.
		set_binding_property(binding, "target", NULL());

		// Knock bound entity down to reset it.
        damageentity(vTarget, vSelf, 0, 100, openborconstant("ATK_NORMAL"));    
    }
    else
    {
		// If caller's drawmethod is on, then
		// adjust offsets to caller's current scale.
		if (getdrawmethod(vSelf, "enabled") == 1)
		{
			iX = dc_draw_adjust_to_scale_x(vSelf, iX);
			iY = dc_draw_adjust_to_scale_y(vSelf, iY);
		}

		// Get binding toggle and enable flags.
		void binding_enable = get_binding_property(binding, "enable");
		void binding_axis = get_binding_property(binding, "offset");

		// Enable binding on each axis.
		set_axis_principal_int_property(binding_enable, "x", 1);
		set_axis_principal_int_property(binding_enable, "y", 1);
		set_axis_principal_int_property(binding_enable, "z", 1);

		// Set the binding offset.
		set_axis_principal_int_property(binding_axis, "x", iX);
		set_axis_principal_int_property(binding_axis, "y", iY);
		set_axis_principal_int_property(binding_axis, "z", iZ);

		// Set other binding properties.
		set_binding_property(binding, "matching", iAniFlag);
		set_binding_property(binding, "direction", iDir);
		set_binding_property(binding, "target", vSelf);
    }
}
