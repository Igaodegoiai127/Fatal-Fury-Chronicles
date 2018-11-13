#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_draw/main.c"
#include "data/scripts/dc_sound/main.c"

void main() {

	void ent;
	float pos_z;
	int aggression;	

	ent = getlocalvar("self");
	pos_z = getentityproperty(ent, "z");

	// Make sure autokill is on.
	changeentityproperty(ent, "autokill", 1);

	// Water fatality for sound beach. This needs to be moved
	// elsewhere.
	if (pos_z < openborvariant("PLAYER_MIN_Z") - 3)  
	{
		// stereo_sound_command_here(SNDWAT1);
		changeentityproperty(ent, "setlayer", -9);
		changeentityproperty(ent, "map", 1);
		//changeentityproperty(ent, "animation", openborconstant("ANI_FOLLOW1"));
	}
	else if (pos_z > openborvariant("PLAYER_MAX_Z"))   
	{
		killentity(ent);
	}
	else
	{
		changedrawmethod(ent, "scalex", 128);
		changedrawmethod(ent, "scaley", 128);

		//dc_draw_z_position_autoscale(ent);
	}
}