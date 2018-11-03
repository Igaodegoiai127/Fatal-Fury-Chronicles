//flash spawn.

#include "data/scripts/dc_draw/main.c"
#include "data/scripts/dc_sound/main.c"	        //Sound functions.
#include "data/scripts/com/rnd0001.h"

void main(){

    void    vSelf   = getlocalvar("self");                                      //Caller.
    
	changedrawmethod(vSelf, "scalex", 0.5);
	changedrawmethod(vSelf, "scaley", 0.5);
	changedrawmethod(vSelf, "alpha", 1);
	changedrawmethod(vSelf, "rotate", rnd0001(0, 359, 0, 0, 0, 0));

	//Apply draw settings.  
    dc_draw_z_position_autoscale(vSelf);                                                              
    
	// stereo_sound_command_here(SNDHIT1);
}