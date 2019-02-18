#include "data/scripts/dc_d20/main.c"

void oncreate()
{
	void ent;

	ent = getlocalvar("self");
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
	float pos_x;
	float pos_y;
	float pos_z;

	pos_x = getlocalvar("dc_water_float_center_x");

	if (!pos_x)
	{
		pos_x = get_entity_property(ent, "position_x");
		pos_y = get_entity_property(ent, "position_y");
		pos_z = get_entity_property(ent, "position_z");

		setlocalvar("dc_water_float_center_x", pos_x);
		setlocalvar("dc_water_float_center_y", pos_y);
		setlocalvar("dc_water_float_center_z", pos_z);
	}	
}

#ifndef DC_MOVEMENT_CONFIG

#define DC_MOVEMENT_CONFIG

#define DC_MOVEMENT_FLOAT_MAX_FALL_VELOCITY	9
#define DC_MOVEMENT_FLOAT_MIN_FALL_VELOCITY	4
#define DC_MOVEMENT_FLOAT_MAX_RISE_VELOCITY	9
#define DC_MOVEMENT_FLOAT_MIN_RISE_VELOCITY	4


#endif // !DC_MOVEMENT_CONFIG

float dc_water_float_fall_velocity()
{
	float result;

	dc_d20_set_range_lower(DC_MOVEMENT_FLOAT_MIN_FALL_VELOCITY);
	dc_d20_set_range_upper(DC_MOVEMENT_FLOAT_MAX_FALL_VELOCITY);

	result = dc_d20_random_int() * 0.01;

	result = -result;

	return result;
}

float dc_water_float_rise_velocity()
{
	float result;

	dc_d20_set_range_lower(DC_MOVEMENT_FLOAT_MIN_RISE_VELOCITY);
	dc_d20_set_range_upper(DC_MOVEMENT_FLOAT_MAX_RISE_VELOCITY);

	result = dc_d20_random_int() * 0.01;

	return result;
}

void dc_water_float_bob(void ent)
{
	float pos_center_y;
	float pos_y;
	
	float vel_x;
	float vel_y;
	float vel_z;
	float diff;
	
	pos_center_y = getlocalvar("dc_water_float_center_y");
	
	pos_y = get_entity_property(ent, "position_y");

	// Allow base adjustment, and then let's just our base
	// at pit depth. Without any other adjustments, we'd start
	// falling toward the new base.
	changeentityproperty(ent, "no_adjust_base", 1);
	set_entity_property(ent, "position_base_alternate", openborconstant("PIT_DEPTH"));

	diff = pos_y - pos_center_y;

	if (diff < -4)
	{
		vel_y = dc_water_float_rise_velocity();
	}
	else if(diff > 4)
	{
		vel_y = dc_water_float_fall_velocity();
	}
	else if (!diff)
	{
		vel_y = dc_water_float_fall_velocity();
	}

	//log("\n vel_y:" + vel_y);

	vel_x = getentityproperty(ent, "xDir");
	vel_z = getentityproperty(ent, "zdir");

	changeentityproperty(ent, "velocity", vel_x, vel_z, vel_y);
}