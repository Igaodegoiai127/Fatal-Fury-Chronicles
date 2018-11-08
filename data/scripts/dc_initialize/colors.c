#include "data/scripts/dc_initialize/config.h"

char dc_random_color_set(void ent)
{
	int hidden_map_lower;
	int hidden_map_upper;
	int mapcount;

	int random_index;

	hidden_map_lower = getentityproperty(ent, "hmapl");
	hidden_map_upper = getentityproperty(ent, "hmapu");

	mapcount = getentityproperty(ent, "mapcount");

	// use the number of color sts available as maximum random number.
	setlocalvar(DC_D20_VAR_KEY_RANGE_UPPER, mapcount);

	// Generate a random map index that falls outside of hidden map range.
	do
	{
		// Generate random number.
		random_index = dc_d20_random_int();

	} while (hidden_map_lower && (random_index >= hidden_map_lower && random_index <= hidden_map_upper));

	// Return th random color.
	return random_index;
}