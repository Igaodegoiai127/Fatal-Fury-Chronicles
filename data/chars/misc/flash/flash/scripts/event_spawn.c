#include "data/scripts/dc_kanga/main.c"
#include "data/scripts/dc_fidelity/main.c"
#include "data/scripts/dc_d20/main.c"

void main() {

	void ent;
	int	rotate;

	ent = getlocalvar("self");

	
	changedrawmethod(ent, "alpha", 1);
	changedrawmethod(ent, "enabled", 1);

	dc_d20_set_range_lower(0);
	dc_d20_set_range_upper(359);

	rotate = dc_d20_random_int();

	changedrawmethod(ent, "rotate", rotate);

	// Apply draw settings.
	//dc_kanga_z_position_autoscale(ent);

	int force = get_attack_property(openborvariant("lasthit_attack"), openborconstant("ATTACK_PROP_DAMAGE_FORCE"));

	int speed = 100 - ((force - 10) * 4);

	int size = 200 - speed;

	changedrawmethod(ent, "scalex", size);
	changedrawmethod(ent, "scaley", size);

	if (speed > 130)
	{
		speed = 130;
	}
	else if (speed < 70)
	{
		speed = 70;
	}	

	dc_fidelity_set_sound_speed(speed);

	dc_fidelity_quick_play(DC_FIDELITY_TYPE_SPAWN_A);

	//log("\n force: " + force);

	/*
	t = 100 - (noslowfx ? 0 : (force - 5));
	if (t > 100)
	{
		t = 100;
	}
	else if (t < 60)
	{
		t = 60;
	}
	sound_play_sample(attack->hitsound, 0, savedata.effectvol, savedata.effectvol, t);
	*/
}
