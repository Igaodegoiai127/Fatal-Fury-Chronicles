#include "data/scripts/dc_grapple/main.c"  

#include "data/scripts/dc_math/main.c"

#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/common/takedamage_main.c"

#include "data/chars/galford/scripts/model_main.c"

void main()
{
	void ent = getlocalvar("self");
	int take_damage_result;

	// Compute result of take damage (knockdown, KO, etc.) so we
	// don't need to do it over and over again for different
	// action logic.
	take_damage_result = common_take_damage_result(ent);

	// Play appropriate sound effect.
	common_take_damage_sound(take_damage_result);

	// Release any grappled entities.
	dc_elmers_set_target(ent);
	dc_elmers_disrupt_grapple();

	// Try weapon drop.
	try_weapon_drop(ent, take_damage_result);
}
