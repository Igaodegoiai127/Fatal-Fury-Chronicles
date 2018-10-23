#ifndef DC_SOUND_CONFIG1

#include "data/scripts/dc_d20/main.c"

#define DC_SOUND_CONFIG 1

#define DC_SOUND_SAMPLE_INVALID			-1
#define DC_SOUND_FAILURE_LOG			0

#define DC_SOUND_DEFAULT_VOLUME_LEFT	200
#define DC_SOUND_DEFAULT_VOLUME_RIGHT	200
#define DC_SOUND_DEFAULT_PRIORITY		1
#define DC_SOUND_DEFAULT_LOOP			0
#define DC_SOUND_DEFAULT_SPEED			100

// Sound categories.
#define DC_SOUND_TYPE_WHIFF_HEAVY_A		0	// "Air" sound, heavy attacks.
#define DC_SOUND_TYPE_WHIFF_LIGHT_A		1	// "Air" sound, light attacks.
#define DC_SOUND_TYPE_WHIFF_MEDIUM_A	2	// "Air" sound, medium attacks.

// Indexes.
#define DC_SOUND_INDEX_RANDOM			-1	// Seek a random sound index from sound type.

// Variable keys.
#define DC_SOUND_VAR_KEY_ELEMENT		"dcsnd_0"
#define DC_SOUND_VAR_KEY_ENTITY			"dcsnd_1"
#define DC_SOUND_VAR_KEY_LOOP			"dcsnd_2"
#define DC_SOUND_VAR_KEY_MODELS			"dcsnd_3"	// Global var used to store list of models -> types ->indexes.
#define DC_SOUND_VAR_KEY_PRIORITY		"dcsnd_4"
#define DC_SOUND_VAR_KEY_SPEED			"dcsnd_5"
#define DC_SOUND_VAR_KEY_VOLUME_LEFT	"dcsnd_6"
#define DC_SOUND_VAR_KEY_VOLUME_RIGHT	"dcsnd_7"

#endif // !DC_SOUND_CONFIG




