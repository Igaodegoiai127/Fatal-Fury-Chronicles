void oncreate()
{}

void ondestroy()
{}

// Caskey, Damon V.
// 2018-11-05
//
// Decrement base. If already at a specified point,
// kill self instead.
void sink_and_suicide()
{
	#define FALL_SPEED		-0.1
	#define TERMINAL_POS_Y	-150

	void	ent;
	float	base;
	float	pos_y;

	ent = getlocalvar("self");

	// Allow base adjustment, and then let's just our base
	// at pit depth. Without any other adjustments, we'd start
	// falling toward the new base.
	changeentityproperty(ent, "no_adjust_base", 1);
	set_entity_property(ent, "position_base_alternate", openborconstant("PIT_DEPTH"));
	
	// Now get vertical position. If we are already at
	// terminal position then we'll kill ourselves. Otherwise
	// we move downward to simulate a slow sinking fall.
	pos_y = get_entity_property(ent, "position_y");
	
	log("\n pos_y: " + pos_y);

	if (pos_y < TERMINAL_POS_Y)
	{
		killentity(ent);
	}
	else
	{	
		// Disable the engine's gravity so we can "fall" at 
		// our own speed using velocity.
		changeentityproperty(ent, "subject_to_gravity", 0);
		
		// Set falling movement.
		changeentityproperty(ent, "velocity", 0, 0, FALL_SPEED);
	}

	#undef FALL_SPEED
	#undef TERMINAL_POS_Y
}