#include "data/scripts/vars/entity.h"
#include "data/scripts/com/kill0001.h"

//Killed script for sound beach boat.

void main()
{
	//dust0001("dust0001");								//(function removed 12262010) Spawn dust effect.	                           
	void vSelf = getlocalvar("self");
	void vBinde = getentityvar(vSelf, BINDE);			//Get any bound effect.
            
    if (getentityproperty(vBinde, "exists"))			//Bound effect exists?
    { 
        killentity(vBinde);								//Then kill it.
    }

    kill0001();											//Run generic death function.											   
}
