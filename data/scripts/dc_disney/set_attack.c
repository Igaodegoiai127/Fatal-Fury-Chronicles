#include "data/scripts/dc_disney/config.h"

// Caskey, Damon V.
// 2016-09-13
//
// Verify animation and entity, then instruct entity
// to perform animation as an attack.
int dc_disney_set_attack(void ent, int animation)
{
	int is_valid;
	int vartype;
	int result;

	// Get entity vartype.
	vartype = typeof(ent);

	// If the entity is not a valid pointer, use self as default.
	if (vartype != openborconstant("VT_PTR"))
	{
		ent = getlocalvar("self");
	}

	// Get animation valid status.
	is_valid = getentityproperty(ent, "animvalid", animation);

	// Animation is valid?
	if (is_valid == 1)
	{
		// Switch using perform attack.
		result = performattack(ent, animation);
	}

	return result;
}