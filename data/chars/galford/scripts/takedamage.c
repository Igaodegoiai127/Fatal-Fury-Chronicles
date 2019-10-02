#include "data/scripts/dc_grapple/main.c"  

#include "data/scripts/dc_math/main.c"

void main()
{
    
    void ent			= getlocalvar("self");                      //Calling entity.    
    

	// Dropping weapon?
	try_weapon_drop(ent);

	// Release any grappled entities.
	dc_grapple_release_all(ent);
}

#define GALFORD_SWORD 1
#define DROP_THRESHOLD 1
#define DAMAGE_THRESHOLD 15

// Galford loses his sword under certain conditions.
void try_weapon_drop(void ent)
{
	int  force_drop;                      // Incomming knockdown force.
	int  force_damage;                    // Incoming damage.
	int  health = getentityproperty(ent, "health");       //Current HP.
	float pos_y;
	float pos_base;

	void weapon_item;
	int weapon_number;

	// Have a weapon?
	weapon_item = get_entity_property(ent, "weapon_item");

	if (!weapon_item)
	{
		return 0;
	}

	// Is weapon the one we are looking for?
	weapon_number = getentityproperty(ent, "weapnum");

	if (weapon_number != GALFORD_SWORD)
	{
		return 0;
	}


	// Now let's look at conditions. 

	force_drop = getlocalvar("drop");                      

	if (force_drop < DROP_THRESHOLD)
	{
		return 0;
	}

	force_damage = getlocalvar("damage");

	pos_y = get_entity_property(ent, "position_y");
	pos_base = get_entity_property(ent, "position_base");

	// If the damage is less than our threshold AND we're
	// on the ground, then return false.
	if (force_damage < DAMAGE_THRESHOLD && dc_math_difference_float(pos_y, pos_base) <= 0.1)
	{
		return 0;
	}

	return 1;
}

#undef GALFORD_SWORD
#undef DROP_THRESHOLD
#undef DAMAGE_THRESHOLD
