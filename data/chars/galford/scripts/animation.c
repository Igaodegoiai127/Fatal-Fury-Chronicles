/*
Animation script: 
Galford
*/

#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_fidelity/main.c"
#include "data/scripts/dc_gauntlet/main.c"
#include "data/scripts/dc_velocity/main.c"
#include "data/scripts/dc_damage/main.c"
#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_gauntlet/main.c"

void weapon_spawn()
{
	void ent = getlocalvar("self");
	void spawn = dc_gauntlet_quick_spawn("Justice_Sword");

	//dc_elmers_set_target(ent);
	//dc_elmers_set_entity(spawn);

	//dc_elmers_quick_bind();

	changeentityproperty(ent, "weapon", 1);

	set_entity_property(spawn, "position_x", get_entity_property(ent, "position_x"));
	set_entity_property(spawn, "position_y", 0);
	set_entity_property(spawn, "position_z", 100000);

	set_entity_property(spawn, "spawn_type", openborconstant("SPAWN_TYPE_WEAPON"));
	set_entity_property(ent, "weapon_item", spawn);

}