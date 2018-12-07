#include "data/scripts/dc_terrain/main.c"

void main()
{
	//dc_terrain_set_animation(openborconstant("ANI_JUMP"));
	log("\n Wall: " + dc_terrain_distance_to_wall_left_edge_x(0));

	//dc_hansburg_execute();
}