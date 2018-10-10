// Import functions.
#include "data/scripts/dc_afterimage/main.c"
#include "data/scripts/dc_draw/main.c"

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
		dc_draw_auto_tint(ent);
				
	}

	// Draw after images
	trai0001();
}

void dc_draw_position(void ent, int box, int box_y)
{
	void position = get_entity_property(ent, "position_coordinates");

	float x = get_axis_principal_float_property(position, "x");
	float y = get_axis_principal_float_property(position, "y");
	float z = get_axis_principal_float_property(position, "z");

	settextobj(box, 50, box_y, 0, -1, "X: " + x + ", Y: " + y + ", Z: " + z, openborvariant("elapsed_time") + 200);
}