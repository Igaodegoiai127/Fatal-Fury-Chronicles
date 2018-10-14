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


#define DC_SOUND_DEFAULT_VOLUME_LEFT	200
#define DC_SOUND_DEFAULT_VOLUME_RIGHT	200
#define DC_SOUND_DEFAULT_SPEED			100

// Get specified entity, or caller if not available.
void dc_sound_get_entity()
{
	void result = getlocalvar("dc_sound_entity");

	if (!entity)
	{
		entity = getlocalvar("self");
	}

	return entity;
}

// Get specified volume, or default if not available.
int dc_sound_get_volume_left()
{
	int result = getlocalvar("dc_sound_volume_left");

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_SOUND_DEFAULT_VOLUME_LEFT;
	}

	return result;
}

// Get specified volume, or default if not available.
int dc_sound_get_volume_right()
{
	int result = getlocalvar("dc_sound_volume_right");

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_SOUND_DEFAULT_VOLUME_RIGHT;
	}

	return result;
}

// Get specified speed, or default if not available.
int dc_sound_get_volume_right()
{
	int result = getlocalvar("dc_sound_speed");

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_SOUND_DEFAULT_SPEED;
	}

	return result;
}

// Caskey, Damon V. 
// 2018-10-13
//
// Set sound volume localvars based on X position. 
// This provides a location stereo effect.
void dc_sound_volume_adjust_position_x()
{
	void	entity;
	int		volume_left;
	int		volume_right;
	int		screen_center;
	float	center;
	float	position;
	float	factor;

	entity			= dc_sound_get_entity();
	volume_left		= dc_sound_get_volume_left();
	volume_right	= dc_sound_get_volume_right();

	// First let's find the overall position
	// with screnn scrolling accounted for.
	position = getentityproperty(vEnt, "x") - openborvariant("xpos");

	// Get median of the screen resolution.
	center = openborvariant("hResolution") * 0.5;

	// Devide posiiton by center. This gives us a factor we
	// can apply to channel volume.
	factor = position / center;

	// Apply factor to volumes. At a dead center
	// position, both volumes are original value.
	volume_left -= (volume_left / 2) * fX;
	volume_right = (volume_right / 2) * fX;

	setlocalvar("dc_sound_volume_left_temp", volume_left);
	setlocalvar("dc_sound_volume_right_temp", volume_right);
}

void dc_sound_play(int category, int sample, float chance)
{
	void entity;

	entity = getlocalvar("dc_sound_entity");


}

// Very simple alternate attack. If first performing an attack
// and combo has at least one hit in it, then randomly perform
// an alternate. This is so we can give a bit of variety 
// to combo finishers for AI.
void dc_combo_alt(int animation)
{
    #define COMBOSTEP_MIN_DEFAULT 1
	#define CHANCE_DEFAULT 0.3

	void	ent;
	int		combostep;
	int		modulo;
	int		chance;
	int		combostep_min;

	ent			= getlocalvar("self");
	combostep	= getentityproperty(ent, "combostep");
	
	// Get user value. If there isn't one, fall back
	// to default.
	combostep_min = getlocalvar("dc_combo_alt_combostep_min");

	if (typeof(combostep_min) == openborconstant("VT_EMPTY"))
	{
		combostep_min = COMBOSTEP_MIN_DEFAULT;
	}

	// Get user value. If there isn't one, fall back
	// to default.
	chance = getlocalvar("dc_combo_alt_chance");

	if (typeof(chance) == openborconstant("VT_EMPTY"))
	{
		chance = CHANCE_DEFAULT;
	}

	// Take our chance percentage and make it whole.
	chance *= 100;

	// Get a modulo value from random number and our 
	// chance value. 
	modulo = rand() % chance;

	if (modulo > 0)
	{
		if (combostep > combostep_min)
		{
			changeentityproperty(ent, "animation", animation);
		}
	}

	#undef COMBOSTEP_MIN_DEFAULT
	#undef CHANCE_DEFAULT

}