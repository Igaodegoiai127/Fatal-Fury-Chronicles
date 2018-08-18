#include "data/scripts/vars/trails.h"
#include "data/scripts/vars/entity.h"

void trai0002(void target)
{

    /*
    trai0002
    Utunnels
    Unknown Date (Converted to Hungarian Notation by Damon Vaughn Caskey 10262009)
    Sets current sprite, location, and draw settings into artifical array (see trai0001) to
    be displayed as a shadow trail.
    */

	int     iSlot;                                                      //Trailer slot.
	void    vSprite;                                                    //Current sprite.
	int     iDir;                                                       //Current facing.
	float   fY, fZ, fX;                                                 //Current location.
	float   fRatio;                                                     //Current scale ratio.
    void    vMap;                                                       //Current remap.
    int     iETime;
    int     iTimer;// = getentityvar(self, "SHDELAY");

    iTimer = getentityvar(target, "SHDELAY");

    if (!iTimer) iTimer = 0;
    if (iTimer < 1)
    {
        setentityvar(target, "SHDELAY", ++iTimer);
        return;
    }

    setentityvar(target, "SHDELAY", NULL());
    iETime = openborvariant("elapsed_time");

	if(iETime%TRAILDLY==0)                                              //Modulo of elapsed time and trailer expire time 0?
	{

		vSprite = getentityproperty(target, "sprite");                   //Get current sprite.
		fX      = getentityproperty(target, "x");                        //Get X location.
		fZ      = getentityproperty(target, "z");                        //Get Z location.
		fY      = getentityproperty(target, "a");                        //Get Y location.
		iDir    = !getentityproperty(target, "direction");               //Get facing.
        vMap    = getentityproperty(target, "colourmap");                //Get current map.
        fRatio  = getentityvar(target, ADSCALER);                        //Get current scale ratio.



        for(iSlot=1; iSlot<=TRAILMAX; iSlot++)                          //Loop through trailer slots.
		{
			if(getglobalvar("trailer"+iSlot+".s")==NULL())              //Slot empty?
			{
                setglobalvar("trailer"+iSlot+".r", fRatio);             //Current draw ratio.
				setglobalvar("trailer"+iSlot+".s", vSprite);            //Store sprite
                setglobalvar("trailer"+iSlot+".m", vMap);               //Store map.
				setglobalvar("trailer"+iSlot+".x", fX);                 //Store X
				setglobalvar("trailer"+iSlot+".z", fZ);                 //Store Z
				setglobalvar("trailer"+iSlot+".a", fY);                 //Store Y
				setglobalvar("trailer"+iSlot+".f", iDir);               //Store facing
				setglobalvar("trailer"+iSlot+".c", TRAILCNT*TRAILDLY);  //Store total * delay as expire time.
				break;
			}
		}
	}
}
