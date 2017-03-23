#include "data/scripts/com/spaw0001.h"

void main()
{
	void vSelf = getlocalvar("self");

	if (getentityproperty(vSelf, "model") == "Rayp")
	{
		changeentityproperty(vSelf, "model", "ray");
	}
    spaw0001();
}


	
