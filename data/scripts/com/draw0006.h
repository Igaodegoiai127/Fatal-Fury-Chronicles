#include	"data/scripts/vars/entity.h"
#include	"data/scripts/com/draw0001.h"
#include	"data/scripts/com/draw0002.h"
#include	"data/scripts/com/ht0001.h"

void draw0006(void vEnt, void vMatch)
{
	/*
	draw0006
	Damon Vaughn Caskey
	12232010
	Scale matching. Adjust vEnt's scale adjustment so its visual size matches vMatch.
	Returns % of Ent's size vs. match.

	vEnt:	Entity to resize.
	vmatch:	Entity to match size with.
	*/

	float	fEntH	=	0.0 + ht0001(vEnt);		//Current height of vEnt.
	float	fMatchH	=	0.0 + ht0001(vMatch);	//Current height of vMatch.
	float	fDiff	=	0.0;					//Size difference.

	fDiff	=	fMatchH / fEntH;				//Get % of Ent's size vs. match.
		
	setentityvar(vEnt, ADSCALEX, fDiff);		//Set scale X adjustment.
    setentityvar(vEnt, ADSCALEY, fDiff);		//Set scale Y adjustment.

	draw0001(vEnt);								//Refresh draw.

	return fDiff;								//Return calculation results.
}

