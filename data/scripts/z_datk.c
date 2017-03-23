#include	"data/scripts/com/parr0001.h"

void main()
{
	void    vSelf		= getlocalvar("self");
    int		iAtkID		= getlocalvar("attackid");
	void	vOther		= getlocalvar("other");

	log("\n z_datk ~ Cuurent ID: " + iAtkID);
	log("\n z_datk ~ Attack ID: " + getentityproperty(vSelf, "attackid"));
	log("\n z_datk ~ Hit By ID: " + getentityproperty(vSelf, "hitbyid"));
	
	if(!getlocalvar("which") && (getentityproperty(vSelf, "hitbyid") != iAtkID))
	{
		if (parr0001(vSelf, vOther))
		{		
			changeopenborvariant("lasthitc", 0);
		}		
	}
		
	changeentityproperty(vSelf, "hitbyid", iAtkID);

	log("\n z_datk ~ Hit By ID (after): " + getentityproperty(vSelf, "hitbyid"));
}
