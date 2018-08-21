#include "data/scripts/com/spaw0002.h"
#include "data/scripts/com/draw0001.h"

void spaw0001()
{
    void vSelf      = getlocalvar("self");                                  //Caller.

    spaw0002();         //Run spawn function.
    //dc_draw_z_position_autoscale(vSelf);    //Apply draw settings.

}
