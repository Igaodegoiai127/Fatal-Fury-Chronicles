#include "data/scripts/dc_sound/config.h"

// Get specified entity, or caller if not available.
void dc_sound_get_entity()
{
	void result = getlocalvar("dc_sound_entity");

	if (!result)
	{
		result = getlocalvar("self");
	}

	return result;
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
// Return an adjusted volume based on position in screen. 
int dc_sound_volume_adjusted_horizontal(float position, int volume)
{
	float	center;
	float	result;
	float	factor;

	// Positions are absolute, so we need to subtract
	// the level scroll position to get where we 
	// are on the screen.

	position -= openborvariant("xpos");

	// Get median of the screen resolution.
	center = openborvariant("hResolution") * 0.5;

	// Divide position by center. This gives us a mutiplication
	// factor based on X posiition on screen:
	//
	// Far left, approaching 0.
	// Center, 1. 
	// Far right, approaching 2.  
	factor = position / center;

	// Divide the orginal volume in half. We then mutiply by
	// our factor to produce an adjusted volume from left to
	// right:
	//
	// Far left, approaching 0.
	// Center, half volume.
	// Far right, approaching original volume.
	result = (volume / 2) * factor;

	// Return the result. 
	// -- Right channel: Use as is.
	// -- Left channel: Subtract from orginal channel volume.
	return result;
}

void dc_sound_quick_play_entity(int sample_id)
{
	void	entity;
	void	axis;
	float	pos_x;
	int		volume_left;
	int		volume_right;

	// If the sound didn't load, just exit.
	if (sample_id == DC_SOUND_SAMPLE_INVALID)
	{
		return;
	}

	// Get set volumes.
	volume_left = dc_sound_get_volume_left();
	volume_right = dc_sound_get_volume_right();

	// Get entity X position.
	entity = dc_sound_get_entity();
	axis = get_entity_property(entity, "position_coordinates");
	pos_x = get_axis_principal_float_property(axis, "x");

	// Get adjusted volumes.
	volume_left -= dc_sound_volume_adjusted_horizontal(pos_x, volume_left);
	volume_right = dc_sound_volume_adjusted_horizontal(pos_x, volume_right);

	// Play the sample.
	playsample(sample_id, DC_SOUND_DEFAULT_PRIORITY, volume_left, volume_right, DC_SOUND_DEFAULT_SPEED, DC_SOUND_DEFAULT_LOOP);
}
