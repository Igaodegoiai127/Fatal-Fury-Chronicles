#include "data/scripts/dc_draw/main.c"

void main(){

    void vSelf      = getlocalvar("self");    
    void other      = getlocalvar("obstacle");    

    dc_draw_z_position_autoscale(vSelf);                          //Run draw function.    
    
}

