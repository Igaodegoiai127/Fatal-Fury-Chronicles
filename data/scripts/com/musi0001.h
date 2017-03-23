#include	"data/scripts/vars/index.h"
#include	"data/scripts/com/file0001.h"
#include	"data/scripts/com/soun0005.h"

void musi0001(void vEnt, int iNotch){

	/*
    musi0001
    Damon Vaughn Caskey
    12292010
	Cycle music tracks using passed entity's guard and juggle points value.

	vEnt: Target entity.  	
    */

	int		iMH, iND, iAG;									//Target entity's max guardpoints, nodrop, and aggression settings.
	char	cTrack;											//Music track name.

	if(!vEnt){	vEnt = getlocalvar("self");	}				//If no entity passed use caller.
		
	iAG	=	getentityproperty(vEnt, "aggression");			//Get aggression (row).
	iND	=	getentityproperty(vEnt, "nodrop");				//Get nodrop (colmun).
	iMH	=	getentityproperty(vEnt, "maxhealth");			//Get health (sound).

	if(iND < 1){	iND = 1;	}							//Failsafe column to 1.

	cTrack = file0001(8, "music", ""+iAG+"", iND);			//open music file and get argument.
	
	if(!cTrack)												//Argument null or invalid?
	{		
		iND = 1;											//Reset column.
		cTrack = file0001(8, "music", ""+iAG+"", iND);		//Try getting track again.
	}

	if(cTrack)												//Track found?
	{
		if(iMH)
		{
			soun0005(vEnt, iMH, -1, 1, 0, 0);				//Play sound effect.
		}
		playmusic("data/music/" + cTrack + ".bor", 1);		//Apply the track.
	}
	
	changeentityproperty(vEnt, "nodrop", iND+iNotch);		//Increment or decrement jugglepoints for next call.
}
