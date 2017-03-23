//Generic one shot spawns (flash, dust, etc.).

#include "data/scripts/com/bind0008.h"
#include "data/scripts/com/draw0001.h"
#include "data/scripts/com/soun0005.h"	        //Sound functions.
#include "data/scripts/com/rnd0001.h"
#include "data/scripts/com/init0001.h"			//Entity records.
#include "data/scripts/com/vars0001.h"			//Clear variables.

void main(){

    void    vSelf   = getlocalvar("self");                                      //Caller.
    float	fSpd	= getentityproperty(vSelf, "speed");						//Get speed setting.
	int		iNoDrop	= getentityproperty(vSelf, "nodrop");						//Nodrop property.
	int		iFlMod	= getentityproperty(vSelf, "flash", 0);						//Get flash model index.
	int		iFlAtk	= getentityproperty(vSelf, "flash", 1);						//Get noatflash setting.
	int		iGP		= getentityproperty(vSelf, "guardpoints");					//Get guardpoints.
	int		iSnd	= VOIHI;													//Sound to play.
	char	cFlName;															//Flash model name.
	int		iAni;																//Animation placeholder.
	float	fZ;																	//Caller location.
	
	init0001(vSelf);																	//Entity records.
	vars0001(vSelf, 0, 0, 0, 0, 0);														//Clean variables.

	/*
	If entity has noatflash, then we want to spawn another entity. This is usually for additional
	visual effect, like a heavy impact spark to go with dust when someone is slammed.
	Flash parameter will provide model to spawn, and number taken from noatflash will determine
	which follow animation to make secondary entity play.
	*/
	if(iFlAtk)
	{
		cFlName = getmodelproperty(iFlMod, 1);											//Get flash model name.	

		if(iFlAtk == -1)																//-1? 														
		{
			iFlAtk = 0;																	//Set to 0 so no animation change at all will be made.
		}
		else
		{
			iAni	= openborconstant("ANI_FOLLOW"+iFlAtk);								//Assemble and get animation constant.
		}

		bind0008(cFlName, cFlName, 0, 1, 0, 0, 0, 0, iAni, 0, 1);						//Spawn secondary entity and apply animation.		
	}

	changeentityproperty(vSelf, "autokill", 1);											//Make sure autokill property is on.
	    
    setentityvar(vSelf, ADSCALEX, fSpd);												//Use speed to set X size adjustment.
    setentityvar(vSelf, ADSCALEY, fSpd);												//Use speed to set Y size adjustment.	
	setentityvar(vSelf, ADROTATE, rnd0001(0, iNoDrop,0,0,0,0));							//Set rotation (random 0 to <nodrop>).
    
	/*
	Guardpoints is used as a type (Dust, skid, etc.). This will determine how to handle any special cases,
	like changing ground impact to water splash and so on.	
	*/

	if(!iGP)																			//GP 0? Dust Type.
	{
		/*
		Checks for unique stage dusts will go here. 
		*/

		fZ = getentityproperty(vSelf, "z");												//Get Z location.

		if (fZ < openborvariant("PLAYER_MIN_Z") - 3)									//Background fatality?  
		{
			/*
			Checks for different background fatalities go here.
			*/
			iSnd	= SNDHITWAM;														//Set sound to play.
			changeentityproperty(vSelf, "setlayer",	-9);								//Set layer behind main panel.
			changeentityproperty(vSelf, "map", 1);										//Use first map.
			changeentityproperty(vSelf, "alpha", 0);									//Toggle transparency.
			changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW1"));
		}
		else if (fZ > openborvariant("PLAYER_MAX_Z"))									//Into the screen fatality?  
		{
			killentity(vSelf);
		}		
	}
	else if(iGP==1)																		//1? Regular flash. No animation changes needed.
	{	
	}
	
	if (!fSpd)																			//No size adjustment?
	{
		fSpd = 1;																		//100% normal size.
	}

	soun0005(vSelf, iSnd, -1, 1, 0, 0);													//Play sound.
	draw0001(vSelf);																	//Apply draw settings.
}