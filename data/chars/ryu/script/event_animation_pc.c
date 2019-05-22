#include "data/scripts/dc_damage/main.c"
#include "data/scripts/dc_disney/main.c"
#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_gauntlet/main.c"
#include "data/scripts/dc_gracie/main.c"
#include "data/scripts/dc_fidelity/main.c"
#include "data/scripts/dc_velocity/main.c"

#define DC_MEMBER_LOOPS "dcloops"
#define DC_LOOPS_CONTROL_MAX_LOOPS 4
#define DC_LOOPS_CONTROL_MIN_LOOPS 1

#define DC_HURRICANE_LOOP_COST		3

void dc_disney_loop(int frame)
{
	int loops;
	void ent;
	int player_index;
	int keys;
	
	int mp;

	// Get current loops, and start at 0 if 
	// there's no value set.
	loops = getlocalvar(DC_MEMBER_LOOPS);

	if (loops == NULL())
	{
		loops = 0;
	}

	ent = getlocalvar("self");
	player_index = get_entity_property(ent, "player_index");
	keys = getplayerproperty(player_index, "keys");

	mp = get_entity_property(ent, "mp");

	// We're at the maximum loop count or don't have
	// enough energy. Delete the loop count variable and exit.
	if (loops >= DC_LOOPS_CONTROL_MAX_LOOPS || mp < DC_HURRICANE_LOOP_COST)
	{
		setlocalvar(DC_MEMBER_LOOPS, NULL());
		return;
	}

	// Player wants more loops? Allow it to max.
	// Otherwise keep looping to minimum.
	if (keys & openborconstant("FLAG_JUMP"))
	{	
		// Deduct the energy to keep looping.
		mp -= DC_HURRICANE_LOOP_COST;
		set_entity_property(ent, "mp", mp);

		set_entity_property(ent, "animation_frame", frame);				
	}
	else if(loops < DC_LOOPS_CONTROL_MIN_LOOPS)
	{
		set_entity_property(ent, "animation_frame", frame);
	}
	else
	{
		setlocalvar(DC_MEMBER_LOOPS, NULL());
		return;
	}

	// Increment loops and populate variable for next cycle.
	loops++;

	setlocalvar(DC_MEMBER_LOOPS, loops);
}