#ifndef DC_GAUNTLET_CONFIG
#define DC_GAUNTLET_CONFIG 1

// Dependencies

// Function macros

// Options.

// Default values.
#define DC_GAUNTLET_DEFAULT_INSTANCE		0
#define DC_GAUNTLET_DEFAULT_ENT			getlocalvar("self")
#define DC_GAUNTLET_DEFAULT_OFFSET_X		0
#define DC_GAUNTLET_DEFAULT_OFFSET_Y		0
#define DC_GAUNTLET_DEFAULT_OFFSET_Z		0
#define DC_GAUNTLET_DEFAULT_TARGET			getlocalvar("self")

// Variable keys. Used to identify cross function
// variables used throughout library.
#define DC_GAUNTLET_VAR_KEY_BASE_ID			"dcgaun"	// Base name of every var ID. Must be unique vs. all other libraries.
#define DC_GAUNTLET_VAR_KEY_INSTANCE		DC_GAUNTLET_VAR_KEY_BASE_ID + 0
#define DC_GAUNTLET_VAR_KEY_ENT				DC_GAUNTLET_VAR_KEY_BASE_ID + 1
#define DC_GAUNTLET_VAR_KEY_OFFSET_X		DC_GAUNTLET_VAR_KEY_BASE_ID + 2
#define DC_GAUNTLET_VAR_KEY_OFFSET_Y		DC_GAUNTLET_VAR_KEY_BASE_ID + 3
#define DC_GAUNTLET_VAR_KEY_OFFSET_Z		DC_GAUNTLET_VAR_KEY_BASE_ID + 4
#define DC_GAUNTLET_VAR_KEY_TARGET			DC_GAUNTLET_VAR_KEY_BASE_ID + 5
#define DC_GAUNTLET_VAR_KEY_THE_END			6			// Should always last, with a value one higher than previous key ID.

#endif // !DC_GAUNTLET_CONFIG