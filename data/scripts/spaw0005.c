#include "data/scripts/vars/entity.h"
#include "data/scripts/com/init0001.h"			//Entity records.
#include "data/scripts/com/vars0001.h"			//Clear variables.

//Non moving, non draw entity spawn.

void main(){

    void    vSelf   = getlocalvar("self");    

    init0001(vSelf);															//Entity records.
	vars0001(vSelf, 0, 0, 0, 0, 0);												//Clean variables.
    
	setentityvar(vSelf, ADSCALER, 1);											//Set scale ratio (bind functions need this even if item won't use draw).    
}