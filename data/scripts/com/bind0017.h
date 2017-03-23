#include "data/scripts/com/ani0009.h" //Verify and switch animation.

void bind0017(void vEnt, int iAni, int iType, int iRem, int A, int B, int C, int D, int E, int F)
{    
    /*
    bind0017
    Damon Vaughn Caskey
    05202010
    Find pre existing ent with same default name, and warp to location. Primarly
    for spawning in location of corpse.
    
    vEnt:   Entity.
    iAni:   Animation.
    iType:  Animation set type (See ani0009).
    iRem:   Remove previous entity?
    A-F:    Expansion.    
    */

    void    vSelf   = getlocalvar("self");                              //Caller.
    int     iMax    = openborvariant("ent_max");		                //Current # of entities.
	int		i;                                                          //Counter.	
	int		iD;												            //Direction.
    float	fX, fY, fZ;										            //Location coords.    

	for(i=0; i<iMax; i++)												//Loop entity collection.	
	{        
		vEnt = getentity(i);											//Get entity.
        
        if(vEnt															//Valid handle?
			&& getentityproperty(vEnt, "exists")						//Valid entity?
			&& getentityproperty(vEnt, "health") < 1					//Dead?
			&& getentityproperty(vEnt, "defaultname") 
			== getentityproperty(vSelf, "defaultname"))					//Same name as self?
		{
			fX = getentityproperty(vEnt, "x");							//Get X.
			fY = getentityproperty(vEnt, "a");							//Get Y.
			fZ = getentityproperty(vEnt, "z");							//Get Z.
			iD = getentityproperty(vEnt, "direction");				    //Get direction.

            if(!checkhole(fX, fZ) && !checkwall(fX, fZ))                //Ent isn't in a hole or wall?
            {
			    changeentityproperty(vSelf, "direction", iD);			//Set direction to self.
			    changeentityproperty(vSelf, "position", fX, fZ, fY);    //Set location to self.
			    ani0009(vSelf, iAni, iType);                            //Set animation.
                
                if(iRem)
                {
                    killentity(vEnt);                                   //Remove previous.
                }
            }
		}
	}	    
}