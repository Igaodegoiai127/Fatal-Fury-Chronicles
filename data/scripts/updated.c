// Import functions.
#include "data/scripts/dc_afterimage/main.c"
#include "data/scripts/dc_kanga/main.c"

void oncreate()
{
	log("\n");
	log("updated.c");
	log("\t");
	log("- oncreate().");
	log("\n");
}

void ondestroy()
{
	log("\n");
	log("update.c");
	log("\t");
	log("- ondestroy().");
	log("\n");
}

void main() {

	void    ent = NULL();   // Target entity pointer.
	int     ent_count = 0;        // Entity count.
	int     i = 0;        // Loop counter.

	
	// Get entity count.
	ent_count = openborvariant("count_entities");

	// Loop over each entity index.
	for (i = 0; i < ent_count; i++)
	{
		// Get entity pointer.
		ent = getentity(i);

		// Execute tint effect on entity.
		dc_kanga_auto_tint(ent);

		//char model = getentityproperty(ent, "model");
		
		//if (model == "Galford")
		//{			
		//}
	}
	

	// Draw after images
	trai0001();
}



void dc_kanga_position(void ent, int box, int box_y, int i)
{
	void position = get_entity_property(ent, "position_coordinates");
	int animation = getentityproperty(ent, "animationid");
	int frame = getentityproperty(ent, "animpos");

	float x = get_axis_principal_float_property(position, "x");
	float y = get_axis_principal_float_property(position, "y");
	float z = get_axis_principal_float_property(position, "z");

	settextobj(box, 50, box_y, 0, -1, "ent: " + i + ", Ani: " + animation + "(" + frame + "), X: " + x + ", Y: " + y + ", Z: " + z, openborvariant("elapsed_time") + 200);
}

