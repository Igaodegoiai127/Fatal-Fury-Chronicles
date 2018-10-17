#include "data/scripts/dc_initialize/main.c" 

void main()
{
	void ent;

	ent = getlocalvar("self");

	initialize_level_spawn(ent);
}


