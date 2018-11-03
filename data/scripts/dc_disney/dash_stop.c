#include "data/scripts/dc_disney/config.h"

// Caskey, Damon V.
// 2018-11-03
// 
// Stop running - used to create dash effect.
void dc_disney_dash_stop()
{
	void ent = getlocalvar("self");

	changeentityproperty(ent, "aiflag", "running", 0);
	changeentityproperty(ent, "velocity", 0, 0, 0);
	changeentityproperty(ent, "animation", openborconstant("ANI_IDLE"));
}