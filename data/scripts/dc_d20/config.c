#include "data/scripts/dc_d20/config.h"

// Lowest number random generator can return.
void dc_d20_set_range_lower(int value)
{
	setlocalvar(DC_D20_VAR_KEY_RANGE_LOWER, value);
}

int dc_d20_get_range_lower()
{
	void result = getlocalvar(DC_D20_VAR_KEY_RANGE_LOWER);

	if (!result)
	{
		result = DC_D20_DEFAULT_RANGE_LOWER;
	}

	return result;
}

// Highest number random generator can return.
void dc_d20_set_range_upper(int value)
{
	setlocalvar(DC_D20_VAR_KEY_RANGE_UPPER, value);
}

int dc_d20_get_range_upper()
{
	void result = getlocalvar(DC_D20_VAR_KEY_RANGE_UPPER);

	if (!result)
	{
		result = DC_D20_DEFAULT_RANGE_UPPER;
	}

	return result;
}