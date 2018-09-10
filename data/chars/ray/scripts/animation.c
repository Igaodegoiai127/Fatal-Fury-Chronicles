/*
Animation script: 

Ray McDougal (AI)

*/

#include "data/scripts/vars/entity.h"

#include "data/scripts/com/bind0004.h" 
#include "data/scripts/dc_grapple/main.c" 
#include "data/scripts/com/dama0001.h" 
#include "data/scripts/com/proj0001.h" 
#include "data/scripts/com/soun0001.h" 
#include "data/scripts/com/stat0001.h" 

// Very simple alternate attack. If first performing an attack
// and combo has at least one hit in it, then randomly perform
// an alternate. This is so we can give a bit of variety 
// to combo finishers for AI.
void dc_combo_alt(float chance, int animation)
{
    #define COMBO_STEP_MIN 1

	void	ent;
	int		combostep;
	int		modulo;
	int		chance_whole;

	ent			= getlocalvar("self");
	combostep	= getentityproperty(ent, "combostep");
	
	// Take our chance percentage and make it whole.
	chance *= 100;

	// Get a modulo value from random number and our 
	// chance value. 
	modulo = rand() % chance_whole;

	if (modulo > 0)
	{
		if (combostep > COMBO_STEP_MIN)
		{
			set_entity_property(ent, "animation_animation", animation);
		}
	}

	#undef COMBO_STEP_MIN
}