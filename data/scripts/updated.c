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