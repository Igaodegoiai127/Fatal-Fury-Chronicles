void ani0012(void vEnt, int iT, int iFrame)
{
    /*
    ani0012
    Damon Vaughn Caskey
    12162010
    Switch Ent to new animation and or frame if current altitude does not meet iA. 
	Main use is to make low jumps skip complex sequences (somersaults, spins, etc.)
   
    vEnt:	Target entity.
	iT:		Height threshold.	
	iFrame:	Frame set.
    */

	int		iB;																//Current base.		
	float	fY;																//Current Y location.
	
    if (!vEnt)																//No ent passed?
	{
		vEnt = getlocalvar("self");											//Use caller.
	}

	iB	=	getentityproperty(vEnt, "base");								//Get current base.
	fY	=	getentityproperty(vEnt, "a");		

	if((fY - iB) < iT)
	{		
		updateframe(vEnt, iFrame);
	}	    
}
