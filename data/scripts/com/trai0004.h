#include "data/scripts/vars/trails.h"

void trai0004()
{
    
    /*
    trai0004
    Damon Caskey
    11152009
    Populates hit array to be applied by trai0003.
    */

    //hit.c: Expire (Clear) time.
    //hit.t: Type
    //hit.d: Damage
    //hit.k: Drop (knockdown)
    //hit.o: Opponent (target)
    //hit.a: Attacker.

    int     i;                                                          //Counter.
	int     iSlot;                                                      //Trailer slot.
	void    iType   = getlocalvar("attacktype");                        //Current sprite.
	int     iDamage = getlocalvar("damage");                            //Current facing.
	int     iDrop   = getlocalvar("drop");                              //Current location.  
	void    vOpp    = getlocalvar("damagetaker");                       //Target.   
    void    vSelf   = getlocalvar("self");                              //Self.	
            
    for (i=1; i<=5; i++)
    {
        for(iSlot=1; iSlot<=10; iSlot++)                                //Loop through trailer slots.
		{
			if(getglobalvar("hit"+iSlot+".t")==NULL())                  //Slot empty?
			{                
                setglobalvar("hit"+iSlot+".c", TRAILCNT*(i * 5));       //Store total * delay as expire time.
				setglobalvar("hit"+iSlot+".t", iType);                  //Store attackk type
                setglobalvar("hit"+iSlot+".d", iDamage);                //Store damage.
				setglobalvar("hit"+iSlot+".k", iDrop);                  //Store drop.
				setglobalvar("hit"+iSlot+".o", vOpp);                   //Store target.
				setglobalvar("hit"+iSlot+".a", vSelf);                  //Store attacker.			
				break;
			}
		}
	}    
}
