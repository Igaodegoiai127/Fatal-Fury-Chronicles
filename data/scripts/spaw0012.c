#include "data/scripts/vars/sounds.h"		//Sound group constants.
#include "data/scripts/com/soun0005.h"        

/*
    Use name as basis for sound effect when spawned.
*/

void main(){

    void	vSelf	= getlocalvar("self");
    char	cAlias	= getentityproperty(vSelf, "name");
	float	fSpd	= 256 * getentityproperty(vSelf, "speed");
	int     iAlpha	= getentityproperty(vSelf, "alpha");
	int		iSnd;

    if (!fSpd) { fSpd = 1; }

	setdrawmethod(vSelf, 1, fSpd, fSpd, 0, 0, 0, iAlpha, -1, 0, 0);  //Set values to drawmethod.    
	
	if (cAlias != "mute")
	{		
		/*Was using alias as name for sounds with legacy sound system. 
		To be consistent, we'll call constants instead.
		An if list is really lame, but will work for now.
		*/

		if(cAlias == "Flash")			{	iSnd = SNDHITM;		}		
		 
		soun0005(vSelf, iSnd, -1, 1, 0, 0);
	}

}

