#include "data/scripts/dc_sound/config.h"
#import "data/scripts/dc_sound/config.c"
#import "data/scripts/dc_sound/adjustments.c"

// Caskey, Damon V.
// 2018-10-23
//
// Get a sample ID from sound type and the current 
// target entity's model.
int dc_sound_get_entity_sound(int type)
{
	void ent;
	char model;
	int sample_id;

	// Get target entity.
	ent = dc_sound_get_entity();

	model = getentityproperty(ent, "model");

	// Now that we have a model, run model sound function 
	// to get a sample ID.
	sample_id = dc_sound_get_model_sound(model, type);

	return sample_id;
}

// Caskey, Damon V.
// 2018-10-23
//
// Calculate chance to perform action against current
// chance setting and return result. 
//
// 0 Fail (no).
// 1 Pass (yes).
int dc_sound_sound_chance()
{
	float chance;
	int percentage;
	int random;

	chance = dc_sound_get_sound_chance();

	// Conver chance to whole number percentage.
	percentage = chance * 100;

	// Get random 0-100.
	setlocalvar(DC_D20_KEY_UPPER, 100);
	random = dc_d20_random_int();

	if (percentage >= random)
	{
		return 1;
	}

	return 0;
}


// Caskey, Damon V.
// 2018-10-23
//
// Get a sample ID from sound type and a known model.
int dc_sound_get_model_sound(char model, int type)
{
	void ent;		// Target entity.
	int result;		// Sound index.
	void models;	// Models array.
	void types;		// Sound types array.
	void indexes;	// Sound indexes array.
	int size;		// Size of array.

	// Get the model's list array.
	models = getglobalvar(DC_SOUND_VAR_KEY_SOUND_MODELS);

	// Get array of sound types for a model.
	types = get(models, model);

	// Get array of sound indexes for a sound type.
	indexes = get(types, type);

	// Get a sound index (sample id) from indexes array.
	result = dc_sound_select_sample_id(indexes);

	return result;
}

// Caskey, Damon V.
// 2018-10-23
// 
// Get a sound index (sample ID) from a sound indexes array. 
int dc_sound_select_sample_id(void indexes)
{
	int result;
	int size;
	int element;

	// Get element setting.
	element = dc_sound_get_sound_element();

	// If element is set to random, then get a 
	// random item from the available range of 
	// array elements.
	if (element == DC_SOUND_INDEX_RANDOM)
	{
		// Get size, decrement by 1 to compensate
		// for 0 indexing and use as upper bound
		// for a random int.
		size = size(indexes);
		size--;

		setlocalvar(DC_D20_KEY_UPPER, size);

		element = dc_d20_random_int();
	}

	// Get sound index value from indexes array.
	result = get(indexes, element);

	// Return result.
	return result;
}

// Caskey, Damon V.
// 2018-10-14
//
// Play requested sample with X axis based stereo.
void dc_sound_quick_play(int type)
{
	void	ent;
	int		sample_id;		// Sample ID to play.
	void	axis;
	float	pos_x;
	int		volume_left;
	int		volume_right;

	// If random chance doesn't pass, exit now.
	if (!dc_sound_sound_chance())
	{
		return;
	}

	// Get set volumes.
	volume_left = dc_sound_get_sound_volume_main_left();
	volume_right = dc_sound_get_sound_volume_main_right();

	// Get entity X position.
	ent = dc_sound_get_entity();
	axis = get_entity_property(ent, "position_coordinates");
	pos_x = get_axis_principal_float_property(axis, "x");

	// Get adjusted volumes.
	volume_left -= dc_sound_volume_adjusted_horizontal(pos_x, volume_left);
	volume_right = dc_sound_volume_adjusted_horizontal(pos_x, volume_right);

	// Get a sample ID.
	sample_id = dc_sound_get_entity_sound(type);

	// Play the sample.
	dc_playsample(sample_id, volume_left, volume_right);
}

// Caskey, Damon V.
// 2018-10-23
// 
// Wrapper for the OpenBOR playsample() function. Gets any leftover
// config values before playing sound and verifies the sample ID.
// There's no way to know id a sample ID is actually valid, but
// it must be a positive integer, so we cna t least check that.
//
// Returns 1 if sample plays, 0 otherwise.
int dc_playsample(int sample_id, int volume_left, int volume_right)
{

	int priority;
	int speed;
	int loop;

	// Sample ID must be a valid integer.
	if (typeof(sample_id) != openborconstant("VT_INTEGER"))
	{
		return 0;
	}

	// Sample ID must be 0+.
	if (sample_id < 0)
	{
		return 0;
	}

	loop = dc_sound_get_sound_loop();
	priority = dc_sound_get_sound_priority();
	speed = dc_sound_get_sound_speed();

	// Play the sample.
	playsample(sample_id, priority, volume_left, volume_right, speed, loop);

	return 1;
}
