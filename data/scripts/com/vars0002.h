#include "data/scripts/vars/entity.h"

void vars0002(int iVar, int iVal)
{
    /*
    vars0002
	Damon Vaughn Caskey
	08/02/2007	
	sets entity var by index.
    */

    void vSelf = getlocalvar("self");

    setentityvar(vSelf, iVar, iVal);

}

