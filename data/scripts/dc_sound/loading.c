#include "data/scripts/dc_sound/config.h"

#import "data/scripts/dc_sound/config.c"

void dc_sounds_setup(char model, int type, char file)
{
	void models;	// Key - model, Value - Sound types array.
	void types;		// Key - Sound Type, Value - Sound index array.
	void indexes;	// Key - Numeric, Value - Sound file index.
	int  sample_id;	// Sample ID loaded to element.


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

	// Get the array size, we can use this as
	// the index since we want to add an element.
	size		= size(indexes);

	// Load the sample and get ID.
	sample_id	= loadsample(file);

	// Add new array element and populate its
	// value with sample ID.
	add(indexes, size, sample_id);

	// Output to the log.
	log("\n Sound sample loaded: ");
	log("\n");
	log("\t");
	log("Model:\t\t" + model);
	log("\n");
	log("\t");
	log("Type:\t\t" + type);
	log("\n");
	log("\t");
	log("Index:\t\t" + size);
	log("\n");
	log("\t");
	log("Sample ID:\t" + sample_id);
	log("\n");
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

	playsample(index, DC_SOUND_DEFAULT_SOUND_PRIORITY, DC_SOUND_DEFAULT_SOUND_VOLUME_LEFT, DC_SOUND_DEFAULT_SOUND_VOLUME_RIGHT, DC_SOUND_DEFAULT_SOUND_SPEED, DC_SOUND_DEFAULT_SOUND_LOOP);

}