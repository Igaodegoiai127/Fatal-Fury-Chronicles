#include "data/scripts/dc_grapple/config.h"


// Temp replacement for targ0001
void grapple_target(void vTarget, void vSelf)
{
	if (!vTarget) { return vSelf; }   //Return "self".	
	else if (vTarget == 1) { return getentityproperty(vSelf, "opponent"); }   //Last entity vSelf interacted with.
	else if (vTarget == 2) { return getentityproperty(vSelf, "grabbing"); }   //Entity vSelf is holding.
	else if (vTarget == 3) { return findtarget(vSelf); }   //vSelf's Nearest opponent.		
	else if (vTarget == 4) { return getentityproperty(vSelf, "parent"); }   //vSelf's parrent.
	else if (vTarget == 5) { return getentityvar(vSelf, BIND); }   //Bound entity.
	else if (vTarget == 6) { return getentityvar(vSelf, BINDHE); }   //Bound hit effect entity.
	else { return vTarget; }   //Target was passed directly, return variable.
}

void bind0010(void vTar, int offset_x, int offset_y, int offset_z, int iDir, int iFrame) {

	/*
	bind0010
	Damon Vaughn Caskey
	12/31/2008
	Bind target to caller and set bound entity's animation frame.

	vTar:       Target entity. See targ0001 function.
	offset_x, offset_y, offset_z: Location offsets.
	iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
	vAni:       Animation for bound entity.
	*/

	void  vSelf = getlocalvar("self");                //Calling entity.
	void  vTarget = grapple_target(vTar, vSelf);               //Target entity.

	if (vTarget)
	{
		// If caller's drawmethod is on, then
		// adjust offsets to caller's current scale.
		if (getdrawmethod(vSelf, "enabled") == 1)
		{
			offset_x = dc_draw_adjust_to_scale_x(vSelf, offset_x);
			offset_y = dc_draw_adjust_to_scale_y(vSelf, offset_y);
		}

		// Get binding property for spawn.
		void binding = get_entity_property(vTarget, "binding");

		// Get binding toggle and enable flags.
		void binding_enable = get_binding_property(binding, "enable");
		void binding_axis = get_binding_property(binding, "offset");

		// Enable binding on each axis.
		set_axis_principal_int_property(binding_enable, "x", 1);
		set_axis_principal_int_property(binding_enable, "y", 1);
		set_axis_principal_int_property(binding_enable, "z", 1);

		// Set the binding offset.
		set_axis_principal_int_property(binding_axis, "x", offset_x);
		set_axis_principal_int_property(binding_axis, "y", offset_y);
		set_axis_principal_int_property(binding_axis, "z", offset_z);

		// Set other binding properties.
		set_binding_property(binding, "animation", openborconstant("BINDING_ANI_NONE"));
		set_binding_property(binding, "direction", iDir);
		set_binding_property(binding, "target", vSelf);

		// Update bound entity's auto scaling.
		dc_draw_z_position_autoscale(vTarget);

		performattack(vTarget, DEFPOSE, 1);
		changeentityproperty(vTarget, "animpos", iFrame);

		/*
		Reset engine's lasthit variants. Otherwise, target will assume sweep values when
		knocked down if last normal attack hit low.
		*/
		changeopenborvariant("lasthitx", 0);
		changeopenborvariant("lasthita", 0);
		changeopenborvariant("lasthitz", 0);
		changeopenborvariant("lasthitt", 0);
	}
}