#include "data/scripts/dc_gauntlet/config.h"

#import "data/scripts/dc_gauntlet/instance.c"
#import "data/scripts/dc_gauntlet/model.c"
#import "data/scripts/dc_gauntlet/offset.c"

int dc_gauntlet_get_projectile_direction()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_VAR_KEY_PROJECTILE_DIRECTION);

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

	setlocalvar(instance + DC_GAUNTLET_VAR_KEY_PROJECTILE_DIRECTION, value);
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
	int direction_adjust;
	int movement_type;
	int projectile_type;
	int map;
	void spawn;

	relative = 0; //DC_GAUNTLET_DEFAULT_PROJECTILE_RELATIVE;
	model_name = dc_gauntlet_get_model_name();  
	direction_adjust = dc_gauntlet_get_projectile_direction();
	movement_type = 0;
	map = 0;

	pos_x = dc_gauntlet_find_position_with_offset_x();
	pos_y = dc_gauntlet_find_position_with_offset_y();
	pos_z = dc_gauntlet_find_position_with_offset_z();

	log("\n x,y,z:" + pos_x + ", " + pos_y + ", " + pos_z);

	spawn = projectile(model_name, pos_x, pos_z, pos_y);// , direction_adjust, movement_type, projectile_type, map);

	log("\n spawn: " + spawn);

	return spawn;
}