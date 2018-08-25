#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_draw/main.c"

void dust0002(void vType, float offset_x, float offset_y, int offset_z, int A, int B, int C, int D, int E, int F){

    /*
     dust0002
     Damon Vaughn Caskey
     02/25/2008
     Spawn effect for jump, land, slide and skid. This is a duplicate of dust001 with some adjustment options added.

	 iType:
     0 = Jump.
     1 = Land.
     2 = Sudden start.
     3 = Sudden stop.
     4 = Skid.
     5 = Impact.
     6 = Heavy Impact.
     7 = Jump (no sound in normal enviroment).
     8 = Fall.
     */

    void  vSpawn;
    void  vSelf		= getlocalvar("self");										//Caller.
    float fRatio	= getentityvar(vSelf, ADSCALER);							//Caller's current scale ratio.
    int   iX		= getentityproperty(vSelf, "x") - openborvariant("xpos");	//Caller X location.
    int   iZ		= getentityproperty(vSelf, "z");							//Caller Z location.
    int   iY		= getentityproperty(vSelf, "y");							//Caller Y location.
	int	  iDir		= getentityproperty(vSelf, "direction");					//Caller direction.
	void  vModel    = "flash_fall_land";											    //Dust model.

	// If caller's drawmethod is on, then
	// adjust offsets to caller's current scale.
	if (getdrawmethod(vSelf, "enabled") == 1)
	{
		offset_x = dc_draw_adjust_to_scale_x(vSelf, offset_x);
		offset_y = dc_draw_adjust_to_scale_y(vSelf, offset_y);
	}

	// Reverse horizontal adjustment if facing left.
    if (iDir == openborconstant("DIRECTION_LEFT"))
	{ 
		offset_x = -offset_x;   
	}                                                 

    clearspawnentry();															//Clear current spawn entry.
    setspawnentry("name",   vModel);											//Aquire spawn entity by name.
    setspawnentry("alias",  "" + vType + "");                                   //Set alias (this will be used to set type of "dust").
	setspawnentry("coords", iX + offset_x, iZ + offset_z, iY + offset_y);						//Spawn location.
    vSpawn = spawn();															//Spawn entity.
    clearspawnentry();															//Clear current spawn entry.

    setentityvar(vSelf, SPAWN, vSpawn);											//Store spawn into last spawn variant.
    changeentityproperty(vSpawn, "direction", iDir);							//Set spawn direction.

    return vSpawn;
}

