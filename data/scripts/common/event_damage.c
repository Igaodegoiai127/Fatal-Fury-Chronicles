#include "data/scripts/dc_grapple/main.c"

void main()
{
	void ent;

	ent = getlocalvar("self");

	// Release any grappled entities.
	dc_grapple_release_all(ent);
}

