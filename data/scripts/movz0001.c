#include "data/scripts/com/draw0001.h"

void main()
{
    void vSelf      = getlocalvar("self");
    int  iZ         = getentityproperty(vSelf, "z");

    if (iZ < openborvariant("PLAYER_MIN_Z")){                       //Past min boundry?
        changeentityproperty(vSelf, "setlayer", -9);                //Layer behind floor panels and obstacles.
        changeentityproperty(getlocalvar("self"), "gfxshadow", 0);  //No shadow.

        draw0001(vSelf);                                                //Run draw function for Z zooming.
    }
	else
	{
		changeentityproperty(vSelf, "setlayer", 0);					//Normal layer.
        changeentityproperty(getlocalvar("self"), "gfxshadow", 1);  //Shadow.
	}

	if (iZ > openborvariant("PLAYER_MAX_Z"))
    {
        draw0001(vSelf);
    }

    //draw0001(vSelf);                                                //Run draw function for Z zooming.
}

