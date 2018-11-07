#include "data/scripts/dc_math/main.c"

#ifndef DC_DRAW_CONFIG
#define DC_DRAW_CONFIG					1

#define DC_DRAW_FLAG_OFF                0
#define DC_DRAW_FLAG_ON                 1

#define DC_DRAW_VAR_KEY_DEBUG_FLAG      "dc_draw_0"
#define DC_DRAW_VAR_KEY_DEBUG_RGB_BLUE  "dc_draw_1"
#define DC_DRAW_VAR_KEY_DEBUG_RGB_GREEN "dc_draw_2"
#define DC_DRAW_VAR_KEY_DEBUG_RGB_RED	"dc_draw_3"
#define DC_DRAW_VAR_KEY_DEBUG_TINT_MODE	"dc_draw_4"
#define DC_DRAW_VAR_KEY_TIME_INITIAL      "dc_draw_5"

// Transpareny mode presets.
#define DC_DRAW_TRANSPARENCY_OFF        0
#define DC_DRAW_TRANSPARENCY_ALPHA      1
#define DC_DRAW_TRANSPARENCY_NEGATIVE   2
#define DC_DRAW_TRANSPARENCY_OVERLAY    3
#define DC_DRAW_TRANSPARENCY_HARDLIGHT	4
#define DC_DRAW_TRANSPARENCY_DODGE      5
#define DC_DRAW_TRANSPARENCY_AVERAGE    6

// Colors
#define DC_DRAW_RGB_MIN                 0
#define DC_DRAW_RGB_MAX                 255

#define DC_DRAW_BURN_RGB_R              DC_DRAW_RGB_MAX					// Burn color Red RGB setting.
#define DC_DRAW_BURN_RGB_G              102								// Burn color Green RGB setting.
#define DC_DRAW_BURN_RGB_B              DC_DRAW_RGB_MIN					// Burn color Blue RGB setting.
#define DC_DRAW_BURN_MODE               DC_DRAW_TRANSPARENCY_ALPHA		// Burn tint alpha mode

#define DC_DRAW_FREEZE                  DC_DRAW_RGB_MAX                 // Starting blue intensity when frozen.
#define DC_DRAW_FREEZE_MODE             DC_DRAW_TRANSPARENCY_ALPHA		// Freeze tint alpha mode.

#define DC_DRAW_KO_RGB_R                128                             // KO color RGB Red setting.
#define DC_DRAW_KO_RGB_G                128                             // KO color RGB Green setting.
#define DC_DRAW_KO_RGB_B                128                             // KO color RGB Blue setting.
#define DC_DRAW_KO_MODE                 DC_DRAW_TRANSPARENCY_ALPHA		// KO tint alpha mode.
#define DC_DRAW_KO_STEPS                64								// Number of increments between no tint and KO tint.

// Scaling and sizing.
#define DC_DRAW_DEFAULT_SCALE			256								// Value used by drawmethod scale values for 100% size.

#define DC_DRAW_MIN_Z_ADJUST			1.1								// Adjustment from actual min Z position before calculations.
#define DC_DRAW_MIN_Z_SIZE				0.9								// Scale ratio when target is at MIN_Z position.

#define DC_DRAW_AUTOSCALE_SCALE_X		DC_DRAW_DEFAULT_SCALE			// Starting scale of target.
#define DC_DRAW_AUTOSCALE_SCALE_Y		DC_DRAW_DEFAULT_SCALE			// "

// Function macros.
#define dc_draw_set_enabled(entity, value)		changedrawmethod(entity, "enabled", value)
#define dc_draw_set_tint_mode(entity, value)	changedrawmethod(entity, "tintmode", value)
#define dc_draw_set_map(entity, value)			changedrawmethod(entity, "remap", value)

#endif // !DC_DRAW_CONFIG