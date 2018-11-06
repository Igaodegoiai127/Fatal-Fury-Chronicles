#include "data/scripts/dc_disney/config.h"

// Entity is the primary entity that performs actions.
void dc_disney_set_entity(void value)
{
	setlocalvar(DC_DISNEY_VAR_KEY_ENT, value);
}

void dc_disney_get_entity()
{
	void result = getlocalvar(DC_DISNEY_VAR_KEY_ENT);

	if (!result)
	{
		result = getlocalvar("self");
	}

	return result;
}