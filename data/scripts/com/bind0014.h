#include "data/scripts/com/targ0001.h"

void bind0014(void vTar, int iIndex, int a, int b, int c)
{
    /*
    bind0014
    Damon Vaughn Caskey
    12/31/2008
    Bind Target index initialization. Stores target entity inone of a 
    series of global indexs for use by binding and damage functions.
    
    vTar:   Target set. Can be an entity or numeric to get target from targ0001 function.
    iIndex: Index to place target.
    A+:     Expansion.
    */

    void vSelf      = getlocalvar("self");
    void vTarget    = targ0001(vTar, vSelf);

    setglobalvar(vSelf + ".bind." + iIndex, vTarget);

	return vTarget;
}
