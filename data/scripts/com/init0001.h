#include "data/scripts/vars/entity.h"	//Entity var indexes
#include "data/scripts/vars/index.h"	//Global var indexes.

void init0001(void vEnt){

	/*
	init0001
	Damon Vaughn Caskey
	12032010 (consolidated from code in spawn functions)

	Store an artifical handle and total count of entities spawned.
	*/
	    
    int     iMaxVar = openborvariant("maxentityvars");                          //Maximum vars in use.
    int     iList   = getindexedvar(ECOUNT);                                    //Entity counter.
    int     iCount;                                                             //Loop counter.

	if(!vEnt)
	{
		vEnt = getlocalvar("self");												//If no target passed use caller.
	}

    if (!iList)
    {    
        iList = 0;																//Count not initalized, set to 0.
    }
    else
    {
        iList++;																//Count initalized, increment by 1.
    }
    
    setentityvar(vEnt, ENTID, iList);											//Set artificial handle.
    setindexedvar(ECOUNT, iList);                                               //Set entity counter.    
}