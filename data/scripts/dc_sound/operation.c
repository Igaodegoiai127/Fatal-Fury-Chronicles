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
// Return an adjustment factor from horizontal position
// that can be applied to volume channels for a 
// location stereo effect.
void dc_sound_horizontal_factor(float position)
{
	float	center;
	float	result;

	// Positions are absolute, so we need to subtract
	// the level scroll position to get where we 
	// are on the screen.
	position -= openborvariant("xpos");

	// Get median of the screen resolution.
	center = openborvariant("hResolution") * 0.5;

	// Devide position by center. This gives us a factor we
	// can apply to channel volume.
	result = position / center;

	return result;
}

// Apply factor to volumes. At a dead center
	// position, both volumes are original value.
//volume_left -= (volume_left / 2) * fX;
//volume_right = (volume_right / 2) * fX;

//setlocalvar("dc_sound_volume_left_temp", volume_left);
//setlocalvar("dc_sound_volume_right_temp", volume_right);

void dc_sound_quick_play_entity(char sample_path)
{
	void	entity;
	void	axis;
	float	factor;
	float	pos_x;
	int		volume_left;
	int		volume_right;
	int		sample_id;

	sample_id = loadsample(sample_path, DC_SOUND_FAILURE_LOG);

	entity = dc_sound_get_entity();
	axis = get_entity_property(entity, "position_coordinates");

	pos_x = get_axis_principal_float_property(axis, "x");

	factor = dc_sound_horizontal_factor(pos_x);

	volume_left -= (volume_left / 2) * factor;
	volume_right -= (volume_right / 2) * factor;

	playsample(sample_id, DC_SOUND_DEFAULT_PRIORITY, volume_left, volume_right, DC_SOUND_DEFAULT_SPEED, DC_SOUND_DEFAULT_LOOP);
}