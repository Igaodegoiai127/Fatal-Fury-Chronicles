#include "data/scripts/vars/trails.h"      
#include "data/scripts/vars/entity.h"

void trai0002()
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
    void    vSelf = getlocalvar("self");
	int     iETime; 
    int     iTimer = getentityvar(vSelf, SHDELAY);

    if (!iTimer) iTimer = 0;
    if (iTimer < 1)
    {        
        setentityvar(vSelf, SHDELAY, ++iTimer);
        return;
    }    

    setentityvar(vSelf, SHDELAY, NULL());
    iETime = openborvariant("elapsed_time");

	if(iETime%TRAILDLY==0)                                              //Modulo of elapsed time and trailer expire time 0?
	{
        
		vSprite = getentityproperty(vSelf, "sprite");                   //Get current sprite.
		fX      = getentityproperty(vSelf, "x");                        //Get X location.
		fZ      = getentityproperty(vSelf, "z");                        //Get Z location.
		fY      = getentityproperty(vSelf, "a");                        //Get Y location.
		iDir    = !getentityproperty(vSelf, "direction");               //Get facing.
        vMap    = getentityproperty(vSelf, "colourmap");                //Get current map.
        fRatio  = getentityvar(vSelf, ADSCALER);                        //Get current scale ratio.
        
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
