#include "data/scripts/dc_draw/config.h"

// Caskey, Damon V.
// 2018-08-22
//
// Get a decimal value of target's current
// scale vs. default (presumably full size)
// scale. NULL target means global drawmethod.
float dc_draw_get_scale_x_ratio(void target)
{
	float	scale_current;
	float	scale_default;
	float	result = 0.0;

	// If the divisor and dividend are integers, 
	// then OpenBOR script treats the quotient as 
	// an integer too. Since we want a float result
	// let's force our values to be flating type
	// here.
	scale_current = getdrawmethod(target, "scalex") + 0.0;
	scale_default = DC_DRAW_DEFAULT_SCALE + 0.0;

	// If either is 0, then result must be 0.
	if (!scale_current || !scale_default)
	{
		return result;
	}

	result = scale_current / scale_default;

	return result;
}

// Caskey, Damon V.
// 2018-08-22
//
// Get a decimal value of target's current
// scale vs. default (presumably full size)
// scale. NULL target means global drawmethod.
float dc_draw_get_scale_y_ratio(void target)
{
	float	scale_current;
	float	scale_default;
	float	result = 0.0;

	// If the divisor and dividend are integers, 
	// then OpenBOR script treats the quotient as 
	// an integer too. Since we want a float result
	// let's force our values to be flating type
	// here.
	scale_current = getdrawmethod(target, "scaley") + 0.0;
	scale_default = DC_DRAW_DEFAULT_SCALE + 0.0;

	// If either is 0, then result must be 0.
	if (!scale_current || !scale_default)
	{
		return result;
	}

	result = scale_current / scale_default;

	return result;
}