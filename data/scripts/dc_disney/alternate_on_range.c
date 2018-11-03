#include "data/scripts/dc_disney/config.h"

// Caskey, Damon V.
// 2018-11-03 (orginal 2009-10-26)
//
// Switch to alternate animation if nearest hostile target is
// in the alternate animation's range.
void dc_disney_alternate_on_range(void ent, int animation) 
{
	void target;

	// Find target in range of animation.
	target = findtarget(ent, animation);

	// If we found a target, then switch animations.
	if (target)
	{
		changeentityproperty(ent, "animation", animation);
	}
}
