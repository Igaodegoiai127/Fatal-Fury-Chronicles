#include "data/scripts/dc_gauntlet/config.h"

#import "data/scripts/dc_gauntlet/instance.c"

// Base entity functions will act on.
// Get
void dc_gauntlet_get_entity()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_VAR_KEY_ENT);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_GAUNTLET_DEFAULT_ENT;
	}

	return result;
}

// Set
void dc_gauntlet_set_entity(void value)
{
	int instance;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GAUNTLET_VAR_KEY_ENT, value);
}

void dc_gauntlet_set_spawn_entry(char property, void value)
{
	setspawnentry(property, value);
}

void dc_gauntlet_clear_spawn_entry()
{
	clearspawnentry();
}

void dc_gauntlet_spawn()
{
	return spawn();
}