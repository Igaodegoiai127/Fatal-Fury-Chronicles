	
void targ0002(void vEnt, int iAni, int iType, int iSType, int iTD){

	/*
	targ0002
	Damon Vaughn Caskey
	12262010
	Search entities and return first found within range of iAni.

	vEnt:	Base entity. If not passed caller is used.
	iAni:	Animation range to verify.
	iType:	Type match. No match check if -1.
	iSType:	Subtype match. No match check if -1.
	iTD:	Throwdamage match (Throwdamage is used for secondary typing. See http://www.caskeys.com/dc/?p=1016). No match check if -1.
	*/

	void    vTar;																	//Target entity.
    int     iMax    = openborvariant("ent_max");									//Current # of entities.
	int		i;																		//Counter.	
	
	if(getentityproperty(vEnt, "animvalid", iAni))									//Animation valid?
	{
		for(i=0; i<iMax; i++)														//Loop entity collection.	
		{        
			vTar = getentity(i);													//Get entity.
        
			if(vTar																	//Valid handle?
				&& getentityproperty(vTar, "exists")								//Valid entity?
				&& checkrange(vEnt, vTar, iAni)										//In range of iAni?	
				&& (getentityproperty(vTar, "type") == iType || iType == -1)		//Type match or iType -1?
				&& (getentityproperty(vTar, "subtype") == iSType || iSType == -1)	//Subtype match or iSType -1?
				&& (getentityproperty(vTar, "throwdamage") == iTD || iTD == -1))	//Throwdamage match or iTD -1?
			{
				return vTar;														//Return target.
			}
		}
	}

	return	NULL();																	//Return null.
}