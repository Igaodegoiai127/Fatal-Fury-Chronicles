//flash spawn.

#include "data/scripts/dc_draw/main.c"
#include "data/scripts/dc_sound/main.c"	        //Sound functions.
#include "data/scripts/dc_d20/main.c"

void main(){

    void    vSelf   = getlocalvar("self");                                      //Caller.
    
	changedrawmethod(vSelf, "scalex", 0.5);
	changedrawmethod(vSelf, "scaley", 0.5);
	changedrawmethod(vSelf, "alpha", 1);

	int rotate;

	setlocalvar(DC_D20_VAR_KEY_RANGE_LOWER, 0);
	setlocalvar(DC_D20_VAR_KEY_RANGE_UPPER, 359);

	rotate = dc_d20_random_int();

	changedrawmethod(vSelf, "rotate", rotate);

	//Apply draw settings.  
    dc_draw_z_position_autoscale(vSelf);                                                              
    
	// stereo_sound_command_here(SNDHIT1);
}