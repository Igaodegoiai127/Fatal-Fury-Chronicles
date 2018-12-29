#include "data/scripts/dc_kanga/main.c"
#include "data/scripts/dc_fidelity/main.c"
#include "data/scripts/dc_d20/main.c"

void main() {

	void ent;
	int	rotate;

	ent = getlocalvar("self");

	changedrawmethod(ent, "scalex", 128);
	changedrawmethod(ent, "scaley", 128);
	changedrawmethod(ent, "alpha", 1);
	changedrawmethod(ent, "enabled", 1);

	dc_d20_set_range_lower(0);
	dc_d20_set_range_upper(359);

	rotate = dc_d20_random_int();

	changedrawmethod(ent, "rotate", rotate);

	// Apply draw settings.
	//dc_kanga_z_position_autoscale(ent);

	// stereo_sound_command_here(SNDHIT1);
}
