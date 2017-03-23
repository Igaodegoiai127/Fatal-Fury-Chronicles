#include "data/scripts/com/spaw0002.h"
#include "data/scripts/com/draw0001.h"

void spaw0001()
{
    void vSelf      = getlocalvar("self");                                  //Caller.
    
    spaw0002();         //Run spawn function.
    draw0001(vSelf);    //Apply draw settings.

}
