#include "data/scripts/dc_initialize/main.c" 

void main()
{
	void ent;

	ent = getlocalvar("self");

	initialize_level_spawn(ent);
}

void initialize_level_spawn(void ent)
{
    void alias; // Caller's alias.
	int map;	// Caller's map.

	// If entity is spawned into play with its KO map,
	// then will randomly select one of its other
	// regular maps here.
	map = getentityproperty(ent, "map");

    if (map == 1)
    {   
		map = dc_random_color_set(ent);

		changeentityproperty(ent, "map", map);
    }

    // If the spawned entity is named "random", then we will
	// generate and assign a random alias here.
	alias = getentityproperty(ent, "name");

	if (alias == "Random")
	{
		alias = dc_random_alias(ent);
		
		changeentityproperty(ent, "name", alias);
	}
}
