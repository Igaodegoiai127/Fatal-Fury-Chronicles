#ifndef DC_SOUND_CONFIG1

#include "data/scripts/dc_d20/main.c"

#define DC_SOUND_CONFIG 1

#define DC_SOUND_SAMPLE_INVALID			-1
#define DC_SOUND_FAILURE_LOG			0


// Default values.
#define DC_SOUND_DEFAULT_CHANCE			1.0
#define DC_SOUND_DEFAULT_CHANCE_RESET	1
#define DC_SOUND_DEFAULT_LOOP			0
#define DC_SOUND_DEFAULT_PRIORITY		1
#define DC_SOUND_DEFAULT_SPEED			100
#define DC_SOUND_DEFAULT_VOLUME_LEFT	200
#define DC_SOUND_DEFAULT_VOLUME_RIGHT	200

// Sound categories.
//
// Add as many as you like, but don't forget
// to give each new category a unique number ID.
// The order of category names and number IDs do 
// not matter at all. It also doesn't matter what the 
// numbers are for any one item. All that matters is
// that each one is unique. Just to keep things easier
// to read, I like to keep the names alphabetical
// and numbers consecutive, even if it means 
// re-numbering the whole list when I add something.

#define DC_SOUND_TYPE_WHIFF_HEAVY_A		0	// "Air" sound, heavy attacks.
#define DC_SOUND_TYPE_WHIFF_HEAVY_B		1	// "Air" sound, heavy attacks (blade).

#define DC_SOUND_TYPE_WHIFF_LIGHT_A		2	// "Air" sound, light attacks.
#define DC_SOUND_TYPE_WHIFF_LIGHT_B		3	// "Air" sound, light attacks (blade).

#define DC_SOUND_TYPE_WHIFF_MEDIUM_A	4	// "Air" sound, medium attacks.
#define DC_SOUND_TYPE_WHIFF_MEDIUM_B	5	// "Air" sound, medium attacks (blade).

#define DC_SOUND_TYPE_VOICE_HEAVY_A		6	// Yalp, heavy attacks.
#define DC_SOUND_TYPE_VOICE_LIGHT_A		7	// Yalp, light attacks.
#define DC_SOUND_TYPE_VOICE_MEDIUM_A	8	// Yalp, medium attacks.

// Indexes.
#define DC_SOUND_INDEX_RANDOM			-1	// Seek a random sound index from sound type.

// Variable keys.
#define DC_SOUND_VAR_KEY_SOUND_CHANCE		"dcsnd_0"
#define DC_SOUND_VAR_KEY_SOUND_ELEMENT		"dcsnd_1"
#define DC_SOUND_VAR_KEY_SOUND_ENTITY		"dcsnd_2"
#define DC_SOUND_VAR_KEY_SOUND_LOOP			"dcsnd_3"
#define DC_SOUND_VAR_KEY_SOUND_MODELS		"dcsnd_4"	// Global var used to store list of models -> types ->indexes.
#define DC_SOUND_VAR_KEY_SOUND_PRIORITY		"dcsnd_5"
#define DC_SOUND_VAR_KEY_SOUND_SPEED		"dcsnd_6"
#define DC_SOUND_VAR_KEY_SOUND_VOLUME_LEFT	"dcsnd_7"
#define DC_SOUND_VAR_KEY_SOUND_VOLUME_RIGHT	"dcsnd_8"

#endif // !DC_SOUND_CONFIG




