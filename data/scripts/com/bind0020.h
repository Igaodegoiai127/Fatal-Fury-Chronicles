#include	"data/scripts/vars/entity.h"
#include	"data/scripts/com/bind0010.h"	//Grapple binding.    

void bind0020(void vEnt){

	/*
	bind0020
	Damon Vaughn Caskey
	09182010
	Rebind to anchor and restablish bound animation. OpenBOR overides animation bind
	when bound entity takes damage. This causes serious animation flaws during grapple
	moves. Runing this function when an entity is put into pain or fall ensures any
	existing grapple binds are restablished. Will not work during takedamagescript 
	event as Engine sets pain animations afterward.

	vEnt:	Target entity.
    */

	void	vAnch;																//Anchor entity (entity target is bound to).
	int		iFrame;																//Bind frame.
	float	fOX, fOY, fOZ;														//Bind offset.
	int		iDir;																//Bind direction.
	int		iIDX;																//Bind index.

	if (!vEnt){ vEnt = getlocalvar("self");	}									//Target not available? Use caller.

	vAnch = getentityvar(vEnt, BOUNDA);											//Target have an anchor entity?											

	if(vAnch)
	{
		iIDX	=	getentityvar(vEnt, BOUNDI);									//Get bind index.
		fOX		=	getentityvar(vEnt, BOUNDX);									//Get bind offset X.
		fOY		=	getentityvar(vEnt, BOUNDY);									//Get bind offset Y.
		fOZ		=	getentityvar(vEnt, BOUNDZ);									//Get bind offset Z.
		iDir	=	getentityvar(vEnt, BOUNDD);									//Get bind direction.
		iFrame	=	getentityvar(vEnt, BOUNDF);									//Get bind frame.

		bind0010(0, vAnch, iIDX, fOX, fOY, fOZ, iDir, iFrame, 0);					//Reestablish bind.
	}

	return vAnch;
}

