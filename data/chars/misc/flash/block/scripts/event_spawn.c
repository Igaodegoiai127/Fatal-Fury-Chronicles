#include "data/scripts/dc_kanga/main.c"
#include "data/scripts/dc_fidelity/main.c"

void main() {

	void ent;
	int	rotate;

	ent = getlocalvar("self");

	changedrawmethod(ent, "scalex", 128);
	changedrawmethod(ent, "scaley", 128);
	changedrawmethod(ent, "alpha", 1);
	changedrawmethod(ent, "enabled", 1);

	// Apply draw settings.
	//dc_kanga_z_position_autoscale(ent);

	// stereo_sound_command_here(SNDHIT1);
}
