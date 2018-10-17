#include "data/scripts/dc_initialize/main.c"

void oncreate()
{
	dc_alias_quick_add("Ray");
	dc_alias_quick_add("Aussie");
	dc_alias_quick_add("Baxter");
	dc_alias_quick_add("Bloundie");
	dc_alias_quick_add("Brush");
	dc_alias_quick_add("Bryl");
	dc_alias_quick_add("Dapper");
	dc_alias_quick_add("Dep");
	dc_alias_quick_add("Fop");
	dc_alias_quick_add("Gel");
	dc_alias_quick_add("Mesh");
	dc_alias_quick_add("Moouse");
	dc_alias_quick_add("Mug");
	dc_alias_quick_add("Silky");
	dc_alias_quick_add("Slick");
	dc_alias_quick_add("Spike");
	dc_alias_quick_add("Woody");
}

void main()
{
	void ent;
	
	ent = getlocalvar("self");

	initialize_level_spawn(ent);
}