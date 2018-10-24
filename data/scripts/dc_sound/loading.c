#include "data/scripts/dc_sound/config.h"

#import "data/scripts/dc_sound/config.c"

void dc_sounds_populate_database(char category, int sample)
{
	void array_categories;
	void array_samples;

	// Array is kept as a localvar
	// Get the array of sounds.
	array_categories = getglobalvar("categories_global");

	// Can't do anything else if we didn't get 
	// an array of categories.
	if (!array_categories)
	{
		return;
	}

	// Get pointer for samples array stored in this
	// category element.
	array_samples = dc_sounds_get_samples_array(array_categories, category);
}

void dc_sounds_get_categories_array(char identifier)
{
	void array_categories;

	// Array is kept as a localvar
	// Get the array of sounds.
	array_categories = getglobalvar("categories_global");

	// If there is no category array, then
	// let's create one and get the pointer.
	if (!array_categories)
	{
		// Create categories array of minimal size.
		array_categories = array(1);
	}

}

// Caskey, Damon  V.
// 2018-10-15
//
// Get samples array pointer from category element
// in categories array. If the category element does
// not contain a sample array, it will be populated
// with a new samples array.
//
// Returns the samples array pointer
void dc_sounds_get_samples_array(void categories, char category)
{
	void array_samples;

	// Get pointer for samples array stored in this
	// category element.
	array_samples = get(categories, category);

	// If there is no samples array in this category, 
	// then we need to create and use it to populate
	// this category element.
	if (!array_samples)
	{
		// Create a samples array.  We'll start
		// with minimal size.
		array_samples = array(1);

		// Place the pointer for our sample array
		// into the categories array element for
		// current category.
		set(categories, category, array_samples);
	}

	// Return the samples array pointer.
	return array_samples;
}

void dc_sounds_setup_ip(char model, int type, char file)
{
	void models;	// Key - model, Value - Sound types array.
	void types;		// Key - Sound Type, Value - Sound index array.
	void indexes;	// Key - Numeric, Value - Sound file index.
	void index;		// Sound file index.

	int size;	// Array size.
	int i;		// Loop index.

	// Get the model's list array.
	models = getglobalvar(DC_SOUND_VAR_KEY_SOUND_MODELS);

	// Initialize array if it doesn't exist.
	if (!models)
	{
		// Create the array.
		models = array(0);

		// Store pointer to array in a globalvar for
		// future access.
		setglobalvar(DC_SOUND_VAR_KEY_SOUND_MODELS, models);
	}

	// Get array of sound types for a model.
	types = get(models, model);

	// Initialize array if it doesn't exist.
	if (!types)
	{
		// Create the array.
		types = array(0);

		// Store pointer to array in an element of
		// the parent array.
		set(models, model, types);
	}

	// Get array of sound indexes for a sound type.
	indexes = get(types, type);

	// Initialize array if it doesn't exist.
	if (!indexes)
	{
		// Create the array.
		indexes = array(0);

		// Store pointer to array in an element of
		// the parent array.
		set(types, type, indexes);
	}

	// Now we need to locate an empty slot
	// in the indexes array and load a sound.
	size = size(indexes);
	log("\n size (before): " + size);

	add(indexes, size, loadsample(file));

	size = size(indexes);
	log("\n size (after): " + size);
}

// Caskey, Damon V.
// 2018-10-22
// 
// Test if a sound loaded properly.
void dc_sounds_loaded_test(char model, int type, int index)
{
	void models;	// Key - model, Value - Sound types array.
	void types;		// Key - Sound Type, Value - Sound index array.
	void indexes;	// Key - Numeric, Value - Sound file index.

	// Get the model's list array.
	models = getglobalvar(DC_SOUND_VAR_KEY_SOUND_MODELS);

	// Get array of sound types for a model.
	types = get(models, model);

	// Get array of sound indexes for a sound type.
	indexes = get(types, type);

	// Get array of sound indexes for a sound type.
	index = get(indexes, index);

	log("\n\n dc_sounds_loaded_test");
	log("\n");
	
	log("\t");
	log("Models Array: " + models);
	log("\n");

	log("\t");
	log("Types Array: " + types);
	log("\n");

	log("\t");
	log("Indexes Array: " + indexes);
	log("\n");

	log("\t");
	log("Sound index: " + index);
	log("\n");

	playsample(index, DC_SOUND_DEFAULT_PRIORITY, DC_SOUND_DEFAULT_VOLUME_LEFT, DC_SOUND_DEFAULT_VOLUME_RIGHT, DC_SOUND_DEFAULT_SPEED, DC_SOUND_DEFAULT_LOOP);

}