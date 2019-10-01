#include "data/scripts/dc_grapple/main.c"  

/*
Take damage for Andy Bogard.

-Ensure lingering special effects from "C4 in UR Face" throw disappear.

-Always fall down and take 50% extra damage if hit out of "C4 in UR Face", 
"Gourin Kai" (grabforward), "Shiranaui Spider Clutch (grabdown), or 
"Gekiheki Haisui Shou" (grab up). Extra damage is non lethal.

-Run normal take damage functions.

*/

void main()
{
    
    void ent			= getlocalvar("self");                      //Calling entity.    
    int  force_drop		= getlocalvar("drop");                      //Incomming attack a knockdown?
    int  iAni			= getentityproperty(ent, "animationid");  //Current animation.
    int  force_damage	= getlocalvar("damage");                    //Incoming damage.
    int  health			= getentityproperty(ent, "health");       //Current HP.

	void weapon_item;
	char weapon_name = "none.";

	weapon_item = get_entity_property(ent, "weapon_item");

	if (weapon_item)
	{
		weapon_name = get_entity_property(weapon_item, "name");

		
	}
	
	log("\n weapon_name: " + weapon_name);

	// Release any grappled entities.
	dc_grapple_release_all(ent);
}



