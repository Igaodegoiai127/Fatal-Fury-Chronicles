#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/colors.h"
#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_kanga/main.c"   
#include "data/scripts/com/effe0001.h"

void main()
{
    void vSelf = getlocalvar("self");

    setentityvar(vSelf, STATUS, NULL());    //Take away power up.

	onfall_main();
}


void onfall_main() 
{

	//Primary falling function.

	void    vSelf = getlocalvar("self");                                      //Calling entity.
	int     iType = getlocalvar("attacktype");                                //Incoming attack type.
	int     iHeight = getentityproperty(vSelf, "height");                       //Caller height.     
	int     iBase = getentityproperty(vSelf, "base");                         //Caller base (platform height).
	int     iHitY;                                                                  //Last hit height.   

	if (iType == openborconstant("ATK_BURN"))                                       //Burn attack?
	{
		effe0001(MAPBURN);                                                          //Set effect.
		dc_kanga_z_position_autoscale(vSelf);                                                            //Update draw   
	}
	else if (iType == openborconstant("ATK_SHOCK"))                                 //Shock attack?
	{
	}
	else if (iType == openborconstant("ATK_NORMAL2"))                               //Attack Type 2?
	{
		if ((iHeight - iBase) <= 1)                                                   //Caller 1 or less from the ground?
		{
			changeentityproperty(vSelf, "velocity", 0, 0, 0);                         //Stop moving (Fall2 is collapse in place)
		}
		else
		{
			changeentityproperty(vSelf, "animation", openborconstant("ANI_FALL"));  //Fall normally since caller was in the air.
		}
	}
	else
	{
		iHitY = openborvariant("lasthita");                                       //Get last hit height.        

		if (iHitY && iHitY < iHeight * 0.3)                      //Knockdown was from low and and self not being thrown?
		{
			changeentityproperty(vSelf, "animation", SWEPT);                        //Put into sweep animation.
		}
	}
}