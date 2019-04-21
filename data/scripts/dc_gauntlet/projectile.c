#include "data/scripts/dc_gauntlet/config.h"

#import "data/scripts/dc_gauntlet/instance.c"
#import "data/scripts/dc_gauntlet/direction.c"
#import "data/scripts/dc_gauntlet/entity.c"
#import "data/scripts/dc_gauntlet/map.c"
#import "data/scripts/dc_gauntlet/model.c"
#import "data/scripts/dc_gauntlet/offset.c"

int dc_gauntlet_get_projectile_direction()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_PROJECTILE_DIRECTION);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_PROJECTILE_DIRECTION;
	}

	return result;
}

int dc_gauntlet_set_projectile_direction(int value)
{
	int instance;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GAUNTLET_MEMBER_PROJECTILE_DIRECTION, value);
}

void dc_gauntlet_get_projectile_stationary()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_PROJECTILE_STATIONARY);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_PROJECTILE_STATIONARY;
	}

	return result;
}

int dc_gauntlet_set_projectile_stationary(int value)
{
	char id;

	// Get ID.
	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_PROJECTILE_STATIONARY;

	// If value is default, make sure the variable
	// is deleted. The get function returns a default
	// if variable is empty, so there's no reason to
	// waste memory storing default values.
	if (value != DC_GAUNTLET_DEFAULT_PROJECTILE_STATIONARY)
	{
		setlocalvar(id, value);
	}
	else
	{
		setlocalvar(id, NULL());
	}
}

void dc_gauntlet_get_projectile_type()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_PROJECTILE_TYPE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_PROJECTILE_TYPE;
	}

	return result;
}

int dc_gauntlet_set_projectile_type(int value)
{
	char id;

	// Get ID.
	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_PROJECTILE_TYPE;

	// If value is default, make sure the variable
	// is deleted. The get function returns a default
	// if variable is empty, so there's no reason to
	// waste memory storing default values.
	if (value != DC_GAUNTLET_DEFAULT_PROJECTILE_TYPE)
	{
		setlocalvar(id, value);
	}
	else
	{
		setlocalvar(id, NULL());
	}
}

// Caskey, Damon V
// 2019-03-16
//
// Spawn and throw projectile.
void dc_guantlet_spawn_projectile()
{
	int relative;
	char model_name;
	int pos_x;
	int pos_y;
	int pos_z;
	int projectile_stationary;
	int projectile_type;
	int map;
	void spawn;
	
	relative				= 0; //DC_GAUNTLET_DEFAULT_PROJECTILE_RELATIVE;
	model_name				= dc_gauntlet_get_model_name();  
	projectile_stationary	= dc_gauntlet_get_projectile_stationary();
	projectile_type			= dc_gauntlet_set_projectile_type();
	map						= dc_gauntlet_get_map();

	pos_x = dc_gauntlet_find_position_with_offset_x();
	pos_y = dc_gauntlet_find_position_with_offset_y();
	pos_z = dc_gauntlet_find_position_with_offset_z();

	// Adjust launching entity and projectile position
	// to avoid launching into wall. The projectile should
	// have wall handling capability, but it's still better 
	// to launch just in front of a wall instead of inside it.
	pos_x += dc_terriant_quick_shunt(pos_x, pos_y, pos_z);

	// Spawn the projectile.
	spawn = projectile(model_name, pos_x, pos_z, pos_y, DC_GAUNTLET_DEFAULT_PROJECTILE_DIRECTION, projectile_stationary, projectile_type, map);

	// Store the spawn as a local var.
	dc_gauntlet_set_spawn(spawn);

	// Adjust spawn's direction as needed.
	dc_apply_adjusted_direction();

	changeentityproperty(spawn, "subject_to_gravity", 0);
	changeentityproperty(spawn, "no_adjust_base", 0);
	changeentityproperty(spawn, "subject_to_basemap", 1);

	return spawn;
}

int dc_terriant_quick_shunt(int pos_x, int pos_y, int pos_z)
{
	void ent;
	int adjustment;
	int ent_pos_x;

	ent = dc_gauntlet_get_entity();
	ent_pos_x = get_entity_property(ent, "position_x");

	adjustment = 0;

	while (checkwall(pos_x + adjustment, pos_z) > pos_y)
	{
		if (checkwall((pos_x + adjustment) - 1, pos_z))
		{
			adjustment -= 2;
		}
		else
		{
			adjustment -= 2;
		}
	}
	
	ent_pos_x += adjustment;

	set_entity_property(ent, "position_x", ent_pos_x);	

	return adjustment;
}