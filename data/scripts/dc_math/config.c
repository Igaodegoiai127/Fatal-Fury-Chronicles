#include "data/scripts/dc_math/config.h"

// Which instance is in use?
int dc_math_get_instance()
{
	void result = getlocalvar(DC_MATH_VER_KEY_INSTANCE);

	if (!result)
	{
		result = DC_MATH_DEFAULT_INSTANCE;
	}

	return result;
}

void dc_math_set_instance(int value)
{
	setlocalvar(DC_MATH_VER_KEY_INSTANCE, value);
}