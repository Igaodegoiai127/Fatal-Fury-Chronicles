#include "data/scripts/com/spaw0001.h"

//Directed (non arc) projectile spawns.

void main()
{    

    void vSelf = getlocalvar("self");
    
    spaw0001();

    changeentityproperty(vSelf, "velocity", 0, 0, 0);
}