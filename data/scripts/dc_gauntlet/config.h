#ifndef DC_GAUNTLET_CONFIG
#define DC_GAUNTLET_CONFIG 1

// Dependencies

// Name of library. Used mainly as a base for variable IDs. Must
// be unique vs all other libraries. Try to keep it short.
#define DC_GAUNTLET_BASE_ID	 "dcgaun"

// Base values
#define DC_GAUNTLET_DRAWMETHOD_SCALE_MAX_X			256
#define DC_GAUNTLET_DRAWMETHOD_SCALE_MAX_Y			256

// Options.
#define DC_GAUNTLET_INVERT_DIRECTION				1
#define DC_GAUNTLET_INVERT_DISABLED					0

#define DC_GAUNTLET_INITIAL_POSITION_ENT			0
#define DC_GAUNTLET_INITIAL_POSITION_LEVEL			1
#define DC_GAUNTLET_INITIAL_POSITION_SCREEN			2

#define DC_GAUNTLET_PROJECTILE_STATIONARY_DISABLED	0
#define DC_GAUNTLET_PROJECTILE_STATIONARY_ENABLED	1

#define	DC_GAUNTLET_PROJECTILE_TYPE_KNIFE			0
#define DC_GAUNTLET_PROJECTILE_TYPE_BOMB			1

#define DC_GAUNTLET_PROJECTILE_PATH_AIR				0
#define DC_GAUNTLET_PROJECTILE_PATH_GROUND			1

// Default values.
#define DC_GAUNTLET_DEFAULT_INSTANCE				0
#define	DC_GAUNTLET_DEFAULT_AUTOKILL				0
#define	DC_GAUNTLET_DEFAULT_DIRECTION_ADJUST		openborconstant("DIRECTION_ADJUST_SAME")
#define DC_GAUNTLET_DEFAULT_ENT						getlocalvar("self")
#define	DC_GAUNTLET_DEFAULT_INITIAL_POSITION		DC_GAUNTLET_INITIAL_POSITION_ENT
#define DC_GAUNTLET_DEFAULT_INVERT_X				DC_GAUNTLET_INVERT_DIRECTION
#define DC_GAUNTLET_DEFAULT_INVERT_Y				DC_GAUNTLET_INVERT_DISABLED
#define DC_GAUNTLET_DEFAULT_INVERT_Z				DC_GAUNTLET_INVERT_DISABLED
#define DC_GAUNTLET_DEFAULT_MAP						0
#define DC_GAUNTLET_DEFAULT_MODEL_NAME				"knife"
#define DC_GAUNTLET_DEFAULT_OFFSET_X				0
#define DC_GAUNTLET_DEFAULT_OFFSET_Y				0
#define DC_GAUNTLET_DEFAULT_OFFSET_Z				0
#define DC_GAUNTLET_DEFAULT_PROJECTILE_DIRECTION	NULL()
#define DC_GAUNTLET_DEFAULT_PROJECTILE_PATH			DC_GAUNTLET_PROJECTILE_PATH_AIR
#define DC_GAUNTLET_DEFAULT_PROJECTILE_RELATIVE		0
#define DC_GAUNTLET_DEFAULT_PROJECTILE_STATIONARY	DC_GAUNTLET_PROJECTILE_STATIONARY_DISABLED
#define DC_GAUNTLET_DEFAULT_PROJECTILE_TYPE			DC_GAUNTLET_PROJECTILE_TYPE_KNIFE
#define DC_GAUNTLET_DEFAULT_TARGET					getlocalvar("self")

// Variable keys. Used to identify cross function
// variables used throughout library.
#define DC_GAUNTLET_MEMBER_INSTANCE					DC_GAUNTLET_BASE_ID + 0
#define DC_GAUNTLET_MEMBER_AUTOKILL					DC_GAUNTLET_BASE_ID + 1
#define DC_GAUNTLET_MEMBER_DIRECTION_ADJUST			DC_GAUNTLET_BASE_ID + 2
#define DC_GAUNTLET_MEMBER_ENT						DC_GAUNTLET_BASE_ID + 3
#define DC_GAUNTLET_MEMBER_INITIAL_POSITION			DC_GAUNTLET_BASE_ID + 4
#define DC_GAUNTLET_MEMBER_INVERT_X					DC_GAUNTLET_BASE_ID + 5
#define DC_GAUNTLET_MEMBER_INVERT_Y					DC_GAUNTLET_BASE_ID + 6
#define DC_GAUNTLET_MEMBER_INVERT_Z					DC_GAUNTLET_BASE_ID + 7
#define DC_GAUNTLET_MEMBER_MAP						DC_GAUNTLET_BASE_ID + 8
#define DC_GUANTLET_MEMBER_MODEL_NAME				DC_GAUNTLET_BASE_ID + 9
#define DC_GAUNTLET_MEMBER_OFFSET_X					DC_GAUNTLET_BASE_ID + 10
#define DC_GAUNTLET_MEMBER_OFFSET_Y					DC_GAUNTLET_BASE_ID + 11
#define DC_GAUNTLET_MEMBER_OFFSET_Z					DC_GAUNTLET_BASE_ID + 12
#define DC_GAUNTLET_MEMBER_PROJECTILE_DIRECTION		DC_GAUNTLET_BASE_ID + 13
#define DC_GAUNTLET_MEMBER_PROJECTILE_RELATIVE		DC_GAUNTLET_BASE_ID + 14
#define DC_GAUNTLET_MEMBER_PROJECTILE_STATIONARY	DC_GAUNTLET_BASE_ID + 15
#define DC_GAUNTLET_MEMBER_PROJECTILE_TYPE			DC_GAUNTLET_BASE_ID + 16
#define DC_GAUNTLET_MEMBER_SPAWN					DC_GAUNTLET_BASE_ID + 17
#define DC_GAUNTLET_MEMBER_THE_END					18			// Should always last, with a value one higher than previous key ID.

#endif // !DC_GAUNTLET_CONFIG