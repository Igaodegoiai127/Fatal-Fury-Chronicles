#include "data/scripts/dc_initialize/main.c" 

#import "data/scripts/common/initialize_level_spawn.c" 

void main()
{
	void ent;

	ent = getlocalvar("self");

	initialize_level_spawn(ent);
}


