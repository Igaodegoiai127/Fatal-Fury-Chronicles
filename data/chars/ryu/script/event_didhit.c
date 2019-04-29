#import		"data/scripts/common/common_didhit.c"
#include	"data/scripts/dc_elmers/main.c"

void main()
{
	void ent;
	void damaged;
	int animation_id;

	// We'll need caller and entity that took damage.
	ent = getlocalvar("self");
	damaged = getlocalvar("damagetaker");

	// What animationa re we playing?
	animation_id = get_entity_property(ent, "animation_id");

	// Default Grabattack2 behavior doesn't look right with
	// attacking animation. 
	//
	// 1. Target sort ID moves from behind attacker to in front, directly
	// against logical momentum of the attack.
	//
	// 2. Target is too close when starting fall.
	//
	// To fix these, we'll use my bind/position library to adjust
	// the target's position. First we move the target some distance
	// away along the X axis. Next, move the target one pixel back
	// along Z axis, and then set the target's sort ID 1 less than
	// attacker's. This realigns target, and keeps them visually 
	// behind the attacker.
	if (animation_id == openborconstant("ANI_GRABATTACK2"))
	{
		dc_elmers_set_entity(damaged);

		dc_elmers_get_position_adjust_quantity_x(50);
		dc_elmers_set_offset_x(50);
		dc_elmers_adjust_distance_to_z();

		dc_elmers_get_position_adjust_quantity_z(-1);
		dc_elmers_set_offset_z(-1);

		dc_elmers_adjust_distance_to_z();

		int sort = get_entity_property(ent, "sort_id");
		set_entity_property(damaged, "sort_id", sort - 1);
	}

	// Run the global didhit logic.
	dc_common_didhit();
}
