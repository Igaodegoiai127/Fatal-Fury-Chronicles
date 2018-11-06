#include "data/scripts/dc_d20/config.h"

// Lowest number random generator can return.
void dc_d20_set_range_lower(int value)
{
	setlocalvar(DC_D20_KEY_LOWER, value);
}

int dc_d20_get_range_lower()
{
	void result = getlocalvar(DC_D20_KEY_LOWER);

	if (!result)
	{
		result = DC_D20_DEFAULT_LOWER;
	}

	return result;
}

// Highest number random generator can return.
void dc_d20_set_range_upper(int value)
{
	setlocalvar(DC_D20_KEY_UPPER, value);
}

int dc_d20_get_range_upper()
{
	void result = getlocalvar(DC_D20_KEY_UPPER);

	if (!result)
	{
		result = DC_D20_DEFAULT_UPPER;
	}

	return result;
}