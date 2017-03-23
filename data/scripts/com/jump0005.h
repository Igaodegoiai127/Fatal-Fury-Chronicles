void jump0005(void vEnt){

	int		iType;																			//Entity type.
	int		iAni;																			//Animation.
	int		iIndex;																			//Player index.
	float	fTossV;  																		//Y velocity.
	float	fXDir;   																		//X velocity.
	float	fZDir;  																		//Z velocity.
	
	if(!vEnt){ vEnt = getlocalvar("self");	}
	
	iType	= getentityproperty(vEnt, "type");												//Get entity type.

	if (iType == openborconstant("TYPE_PLAYER"))											//Entity is player controlled?
	{
		iAni	= getentityproperty(vEnt, "animationID");									//Get current animation.
		iIndex	= getentityproperty(vEnt, "playerindex");									//Get controlling player.
		fTossV  = getentityproperty(vEnt, "tossv");											//Get Y velocity.
		fXDir   = getentityproperty(vEnt, "xdir");											//Get X velocity.
		fZDir   = getentityproperty(vEnt, "zdir");											//Get Z velocity.
				
		if (!playerkeys(iIndex, 0, "jump"))													//Not holding jump?
		{
			if(iAni == openborconstant("ANI_JUMP")											
				|| iAni == openborconstant("ANI_RUNJUMP")
				|| iAni == openborconstant("ANI_FORWARDJUMP"))								//In jump animation?
			{            
				if (fTossV > 0)																//Not falling already?
				{			
					fTossV *= 0.90;															//Cut Y velcoity by 10%. 
					changeentityproperty(vEnt, "velocity", fXDir, fZDir, fTossV);			//Apply velocity
				}
			}
		}
	}
}