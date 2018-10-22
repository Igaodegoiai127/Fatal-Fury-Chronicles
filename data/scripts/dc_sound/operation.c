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

int dc_sound_get_model_sound(void ent, int type, int sound)
{
	int result;		// Sound index.
	char model;		// Model name of entity.
	void models;	// Models array.
	void types;		// Sound types array.
	void indexes;	// Sound indexes array.
	int size;		// Size of array.

	model = getentityproperty(ent, "model");

	// Get the model's list array.
	models = getglobalvar(DC_SOUND_VAR_KEY_MODELS);

	// Get array of sound types for a model.
	types = get(models, model);

	// Get array of sound indexes for a sound type.
	indexes = get(types, type);

	// Random sound called for?
	if (sound == DC_SOUND_INDEX_RANDOM)
	{
		// Get size, decrement by 1 to compensate
		// for 0 indexing and use as upper bound
		// for a random int.
		size = size(indexes);
		size--;

		setlocalvar(DC_D20_KEY_UPPER, size);

		sound = dc_d20_random_int();
	}

	result = get(indexes, sound);

	return result;
}

// Caskey, Damon V.
// 2018-10-14
//
// Play requested sample with X axis based stereo.
void dc_sound_play_entity(int type, int chance)
{
	void	entity;
	int		sample_id;		// Sample ID to play.
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

	// Get a random sample ID.
	sample_id = dc_sound_get_model_sound(entity, type, DC_SOUND_INDEX_RANDOM);

	// Play the sample.
	playsample(sample_id, DC_SOUND_DEFAULT_PRIORITY, volume_left, volume_right, DC_SOUND_DEFAULT_SPEED, DC_SOUND_DEFAULT_LOOP);
}

// Caskey, Damon V.
// 2018-10-14
//
// Play requested sample with X axis based stereo.
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

