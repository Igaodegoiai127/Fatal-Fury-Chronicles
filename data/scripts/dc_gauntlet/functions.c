#include "data/scripts/dc_gauntlet/config.h"

#import "data/scripts/dc_gauntlet/instance.c"
#import "data/scripts/dc_gauntlet/entity.c"

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

// Caskey, Damon V.
// 2019-04-23
//
// Just a one step way to run spawn functions when we
// all we need is a quick spawn.
void dc_gauntlet_quick_spawn(char model_name)
{
	void spawn;

	dc_gauntlet_clear_spawn_entry();	

	dc_gauntlet_set_spawn_entry("name", model_name);

	spawn = dc_gauntlet_spawn();

	dc_gauntlet_clear_spawn_entry();

	return spawn;
}

