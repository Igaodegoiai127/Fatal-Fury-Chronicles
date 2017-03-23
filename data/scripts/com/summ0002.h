#include "data/scripts/com/summ0001.h"

void summ0002(void vEnt, char cModel, char cAlias, int iMap, int iBlend, int iX, int iY, int iZ, int iDir, int iAni, int iFrame, int iKill){

	/*
     summ0002
     Damon Vaughn Caskey
     12092010
     Run summ0001, but adding a target model to extract custom flash from (if any) as the spawned model. 
	 Main use is for scripted hits where the engine does not add a flash automaticaly or the default
	 flash behavior is undesireable.
     
     vEnt:       Model to extract custom flash (if any) from. Otherwise passed model string will be used.
     See summ0001 for other parameters.
     */

	void    vSelf   = getlocalvar("self");												//Calling entity.	
	int		iFlNo;																		//Get target flash property.
	int		iFlMod;																		//Get target noatflash property.

	if(vEnt)																			//Valid target?
	{
		iFlNo	= getentityproperty(vEnt, "flash", 1);									//Get target flash property.
		iFlMod	= getentityproperty(vEnt, "flash", 0);									//Get target noatflash property.

		if(iFlMod)																		//Noatflash property?
		{
			cModel	= getmodelproperty(iFlMod, 1);										//Override flash request with target's custom flash
		}		
	}

	summ0001(cModel, cAlias, iMap, iBlend, iX, iY, iZ, iDir, iAni, iFrame, iKill);		//Run summ0001.
}
