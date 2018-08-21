#include "data/scripts/com/draw0001.h"

void main(){

    void vSelf      = getlocalvar("self");    
    void other      = getlocalvar("obstacle");    

    dc_draw_z_position_autoscale(vSelf);                          //Run draw function.    
    
}

