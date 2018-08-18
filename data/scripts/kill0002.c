#include "data/scripts/vars/entity.h"
#include "data/scripts/com/dust0001.h"
#include "data/scripts/com/kill0001.h"

void main()
{
	dust0001("dust0001");	                           
	void vSelf = getlocalvar("self");
	void vBinde = getentityvar(vSelf, BINDE);		   //Get any bound effect.
            
    if (getentityproperty(vBinde, "exists"))           //Bound effect exists?
    { 
        killentity(vBinde);                            //Then kill it.
    }

    kill0001();    
}