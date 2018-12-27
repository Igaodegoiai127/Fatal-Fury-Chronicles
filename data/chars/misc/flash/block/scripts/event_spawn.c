#include "data/scripts/dc_kanga/main.c"
#include "data/scripts/dc_fidelity/main.c"

void main() {

	void ent;
	int	rotate;

	ent = getlocalvar("self");

	changedrawmethod(ent, "scalex", 0.5);
	changedrawmethod(ent, "scaley", 0.5);
	changedrawmethod(ent, "alpha", 1);

	// Apply draw settings.
	dc_kanga_z_position_autoscale(ent);

	// stereo_sound_command_here(SNDHIT1);
}
