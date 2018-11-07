#include "data/scripts/dc_math/config.h"
#import "data/scripts/dc_math/config.c"

// What to do when incrementing and already at range lower.
void dc_math_spinner_set_range_bound_lower(int value)
{
	int instance;
	instance = dc_math_get_instance();

	setlocalvar(instance + DC_MATH_VER_KEY_SPINNER_RANGE_BOUND_LOWER, value);
}

int dc_math_spinner_get_range_bound_lower()
{
	int instance;
	instance = dc_math_get_instance();

	void result = getlocalvar(instance + DC_MATH_VER_KEY_SPINNER_RANGE_BOUND_LOWER);

	if (!result)
	{
		result = DC_MATH_DEFAULT_SPINNER_RANGE_BOUND_LOWER;
	}

	return result;
}

// What to do when incrementing and already at range upper.
void dc_math_spinner_set_range_bound_upper(int value)
{
	int instance;
	instance = dc_math_get_instance();

	setlocalvar(instance + DC_MATH_VER_KEY_SPINNER_RANGE_BOUND_UPPER, value);
}

int dc_math_spinner_get_range_bound_upper()
{
	int instance;
	instance = dc_math_get_instance();

	void result = getlocalvar(instance + DC_MATH_VER_KEY_SPINNER_RANGE_BOUND_UPPER);

	if (!result)
	{
		result = DC_MATH_DEFAULT_SPINNER_RANGE_BOUND_UPPER;
	}

	return result;
}

// Current incremented value.
void dc_math_spinner_set_value(int value)
{
	int instance;
	instance = dc_math_get_instance();

	setlocalvar(instance + DC_MATH_VER_KEY_SPINNER_VALUE, value);
}

int dc_math_spinner_get_value()
{
	int instance;
	instance = dc_math_get_instance();

	void result = getlocalvar(instance + DC_MATH_VER_KEY_SPINNER_VALUE);

	if (!result)
	{
		result = DC_MATH_DEFAULT_SPINNER_VALUE;
	}

	return result;
}

// Amount to increment.
void dc_math_spinner_set_increment(int value)
{
	int instance;
	instance = dc_math_get_instance();

	setlocalvar(instance + DC_MATH_VER_KEY_SPINNER_INCREMENT, value);
}

int dc_math_spinner_get_increment()
{
	int instance;
	instance = dc_math_get_instance();

	void result = getlocalvar(instance + DC_MATH_VER_KEY_SPINNER_INCREMENT);

	if (!result)
	{
		result = DC_MATH_DEFAULT_SPINNER_INCREMENT;
	}

	return result;
}

// Final value we want to reach when incrementing/decrementing.
void dc_math_spinner_set_range_upper(int value)
{
	int instance;
	instance = dc_math_get_instance();

	setlocalvar(instance + DC_MATH_VER_KEY_SPINNER_RANGE_UPPER, value);
}

int dc_math_spinner_get_range_upper()
{
	int instance;
	instance = dc_math_get_instance();

	void result = getlocalvar(instance + DC_MATH_VER_KEY_SPINNER_RANGE_UPPER);

	if (!result)
	{
		result = DC_MATH_DEFAULT_SPINNER_RANGE_UPPER;
	}

	return result;
}

// Value we start from before begining to increment toward final
// value.
void dc_math_spinner_set_range_lower(int value)
{
	int instance;
	instance = dc_math_get_instance();

	setlocalvar(instance + DC_MATH_VER_KEY_SPINNER_RANGE_LOWER, value);
}

int dc_math_spinner_get_range_lower()
{
	int instance;
	instance = dc_math_get_instance();

	void result = getlocalvar(instance + DC_MATH_VER_KEY_SPINNER_RANGE_LOWER);

	if (!result)
	{
		result = DC_MATH_DEFAULT_SPINNER_RANGE_LOWER;
	}

	return result;
}

// Number of steps want want to take when incrementing between
// original RGB value and final value.
void dc_math_spinner_set_steps(int value)
{
	int instance;
	instance = dc_math_get_instance();

	setlocalvar(instance + DC_MATH_VAR_KEY_SPINNER_STEPS, value);
}

int dc_math_spinner_get_steps()
{
	int instance;
	instance = dc_math_get_instance();

	void result = getlocalvar(instance + DC_MATH_VAR_KEY_SPINNER_STEPS);

	if (!result)
	{
		result = DC_MATH_DEFAULT_SPINNER_STEPS;
	}

	return result;
}

// Caskey, Damon V.
// 2018-11-07
//
// Calculates, stores, and returns the size of an increment 
// from the start point, end point, and number of incremental
// steps we want to take.
int dc_math_spinner_increment_buid()
{
	int result;
	int start;
	int end;
	int diff;
	int steps;
	
	// Get start and end points.
	start = dc_math_spinner_get_range_lower();
	end = dc_math_spinner_get_range_upper();

	// Get the number of increment steps we want.
	steps = dc_math_spinner_get_steps();

	// What is the difference between start and end?
	diff = end - start;

	// Divide difference between start and end by the
	// number of steps we want to take, and that
	// gets us our increment size.
	result = diff / steps;

	dc_math_spinner_set_increment(result);

	return result;
}

// Increment the spinner. Stores and returns resulting
// spinner value.
int dc_math_spinner_increment_run()
{
	void target;
	int current;
	int increment;
	int range_bound;
	int range_lower;
	int range_upper;


	// Get current and increment values.
	current		= dc_math_spinner_get_value();
	increment	= dc_math_spinner_get_increment();
	
	// Get our min/max ranges.
	range_lower = dc_math_spinner_get_range_lower();
	range_upper = dc_math_spinner_get_range_upper();

	// Apply increment.
	current += increment;

	// Has current gone out of bounds?
	if (current < range_lower)
	{
		// Get set action.
		range_bound = dc_math_spinner_get_range_bound_lower();

		// Cap the value? Loop back? 
		if (range_bound == DC_MATH_SPINNER_RANGE_BOUND_LOOP)
		{
			current = range_upper;
		}
		else if (range_bound == DC_MATH_SPINNER_RANGE_BOUND_CAP)
		{
			current = range_lower;
		}
	}
	else if (current > range_upper)
	{
		// Get set action.
		range_bound = dc_math_spinner_get_range_bound_upper();

		// Cap the value? Loop back? 
		if (range_bound == DC_MATH_SPINNER_RANGE_BOUND_LOOP)
		{
			current = range_upper;
		}
		else if (range_bound == DC_MATH_SPINNER_RANGE_BOUND_CAP)
		{
			current = range_lower;
		}
	}

	// Store and return the spinner value.
	dc_math_spinner_set_value(current);
	return current;
}