#include "data/scripts/dc_d20/main.c"

void oncreate()
{
}

void ondestroy()
{}

void main()
{
	void ent;

	ent = getlocalvar("self");

	dc_water_float_initialize(ent);
	dc_water_float_bob(ent);
}

void dc_water_float_initialize(void ent)
{
	void axis;
	float pos_x;
	float pos_y;
	float pos_z;

	pos_x = getlocalvar("dc_water_float_center_x");

	if (!pos_x)
	{
		axis = get_entity_property(ent, "position_coordinates");

		pos_x = get_axis_principal_float_property(axis, "x");
		pos_y = get_axis_principal_float_property(axis, "y");
		pos_z = get_axis_principal_float_property(axis, "z");

		setlocalvar("dc_water_float_center_x", pos_x);
		setlocalvar("dc_water_float_center_y", pos_y);
		setlocalvar("dc_water_float_center_z", pos_z);
	}	
}

void dc_water_float_bob(void ent)
{
	float pos_center_y;
	float pos_y;
	
	float vel_x;
	float vel_y;
	float vel_z;
	float diff;
	
	void axis;

	pos_center_y = getlocalvar("dc_water_float_center_y");
	
	axis = get_entity_property(ent, "position_coordinates");
	pos_y = get_axis_principal_float_property(axis, "y");

	// Allow base adjustment, and then let's just our base
	// at pit depth. Without any other adjustments, we'd start
	// falling toward the new base.
	changeentityproperty(ent, "no_adjust_base", 1);
	set_entity_property(ent, "position_base_alternate", openborconstant("PIT_DEPTH"));

	diff = pos_y - pos_center_y;

	log("\n diff: " + diff);

	if (diff < -4)
	{
		vel_y = 0.07;
	}
	else if(diff > 4)
	{
		vel_y = -0.07;
	}
	else if (!diff)
	{
		vel_y = -0.07;
	}

	vel_x = getentityproperty(ent, "xDir");
	vel_z = getentityproperty(ent, "zdir");

	changeentityproperty(ent, "velocity", vel_x, vel_z, vel_y);
}