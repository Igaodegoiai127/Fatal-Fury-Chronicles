//Wall functions.

#include "data/scripts/com/wall0001.h"

void main()
{
	void wall_blocking_main();
}

void wall_blocking_main()
{
	/*
	void wall_blocking_main()

	Damon Vaughn Caskey
	10102009
	Primary wall function. Damages and bounces self in opposite direction of current
	X velocity when falling and obstructed by wall/platform.
	*/

	void vSelf = getlocalvar("self");														//Calling entity.
	int iFall = getentityproperty(vSelf, "aiflag", "falling");							//Falling flag.
	int iDamage = 0;																		//Damage to apply on self.
	void vOpponent;																				//Last interaction.
	int iDir;																					//Facing setting.
	int iXDir;																					//Current X velocity.
	int iXVel;																					//Set X velocity.

	if (iFall)																					//Falling?
	{
		iXDir = getentityproperty(vSelf, "xdir");											//Get current X velocity.
		vOpponent = getentityproperty(vSelf, "opponent");										//Get last interaction.

		if (iXDir >= 0)																			//Moving Right?
		{
			iDir = 2;																		//Set facing right.
			iXVel = -1.5;																		//Set movement left.
			iDamage += (iXDir * 3);																//Set damage (Velocity * 3).
		}
		else																					//Moving left.
		{
			iDir = -2;																		//Set facing left.
			iXVel = 1.5;																		//Set movement right.
			iDamage += ((-iXDir) * 3);															//Set damage (Resigned velocity * 3).
		}

		damageentity(vSelf, vSelf, iDamage, 100, openborconstant("ATK_NORMAL"));                //Apply damage.
		changeentityproperty(vSelf, "animation", openborconstant("ANI_FALL"));					//Reset fall.
		tossentity(vSelf, 2.5, iXVel, 0);														//Toss self.
	}
}
