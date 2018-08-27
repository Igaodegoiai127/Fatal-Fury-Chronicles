#include "data/scripts/vars/entity.h" 
#include "data/scripts/dc_grapple/main.c"
#include "data/scripts/com/hit0001.h"
#include "data/scripts/com/parr0001.h"

void dama0002(){
    
    //Main take damage function; called by almost all entities when they take damage.

    void    vSelf       = getlocalvar("self");                              //Calling entity. 
    void    vAttacker   = getlocalvar("attacker");                          //Damaging entity.
    int     iAType      = getlocalvar("attacktype");                        //Incomming attack type.
    int     iDrop       = getlocalvar("drop");                              //Incomming attack drop power.
    int     iAni        = getentityproperty(vSelf, "animationid");          //Current animation.
    int     iDam        = getlocalvar("damage");                            //Incoming damage.
    void    vBound      = getentityvar(vSelf, BIND);                        //Bound entity.
    void    vSample;                                                        //Sound sample. 

    
    //If attacker is a projectile, set opponent to the attacker's parent.    
    if(getentityproperty(vAttacker, "type") == openborconstant("TYPE_OBSTACLE"))
    {
        if(getentityproperty(vAttacker, "mp"))
        {
            changeentityproperty(vSelf, "opponent", getentityproperty(vAttacker, "parent"));
        }
    }
    

    hit0001(0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);                        //Erase hit flags.                                                                //Remove special hit flags. This is in case caller is hit out of an attack with flags.

    if (parr0001(vAttacker, iDam)) { return; }                              //Parry for unblockable attack. See parr0001 for details.    

    // Release any grappled entities.
	dc_grapple_release_all(vSelf);

    if (iDrop > 0)
    {
        if (iAType == openborconstant("ATK_BURN"))
        {
            
            if (getentityvar(vSelf, VITGEND) != 1)    //Male.
            {
                vSample = "data/sounds/voim0003.wav";
            }
            else                                        //Female.
            {                                      
            }
            playsample(loadsample(vSample), 0, 120, 120, 100, 0);
        }
    }    
} 
