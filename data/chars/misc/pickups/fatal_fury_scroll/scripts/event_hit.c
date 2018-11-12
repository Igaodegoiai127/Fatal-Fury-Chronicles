#include "data/scripts/vars/entity.h"
#include "data/scripts/vars/anims.h"

void main()
{
	void target = getlocalvar("damagetaker");

	// If not already powered up, and has powered up animation,
	// then set the power up animation.
	if (getentityvar(target, STATUS) != 1)
	{
		if (getentityproperty(target, "animvalid", POWUP))
		{
			changeentityproperty(target, "animation", POWUP);
		}
	}
}