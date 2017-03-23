#include	"data/scripts/vars/index.h"
#include	"data/scripts/com/rema0002.h" 
#include	"data/scripts/com/rnd0001.h"
#include	"data/scripts/com/init0001.h"
#include	"data/scripts/com/name0001.h"
#include	"data/scripts/com/vars0001.h"

void spaw0002()
{
    void vSelf      = getlocalvar("self");											//Caller.
       
	init0001(vSelf);																//Entity records.
	vars0001(vSelf, 0, 0, 0, 0, 0);													//Clean variables.

    if (getentityproperty(vSelf, "map") == getentityproperty(vSelf, "komap", 0))	//Spawned with KO map?
    {                                   
        rema0002(vSelf, 0, 0, 0, 0, 0);												//Apply random remap.
    }
	
    name0001(vSelf);																//Assign random name.
}
