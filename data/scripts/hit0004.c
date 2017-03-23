#include "data/scripts/vars/entity.h"
#include "data/scripts/com/ani0011.h"
#include "data/scripts/com/hit0002.h"
#include "data/scripts/com/host0001.h"
#include "data/scripts/com/summ0002.h"

/*
Projectile didhit script.
Damon V. Caskey
08/28/2009
Simulates projectile systems from various fighting systems.
*/

void main()
{

    void    vSelf       = getlocalvar("self");                  //Caller
    void    vDef        = getlocalvar("damagetaker");           //Get defender.
    void    vParent     = getentityproperty(vSelf, "parent");   //Parent.
    void    vTParent    = getentityproperty(vDef, "parent");    //Target Parent.
    int		iTTD		= getentityproperty(vDef, "throwdamage");	//Throwdamage setting.
	int     iMP;                                                //Caller MP.
    int     iDMP;                                               //Defender MP.
    int     iHP;                                                //Caller HP.
    int     iDHP;                                               //Defender HP.    
    int     iAgg;                                               //Aggression setting.
    int     iX, iY, iZ;                                         //Locations.
    int     iRush;                                              //Rush count.

    /*
    First, let's see if the entity we just hit is a legitamite target.
    If not, we exit and turn off OpenBOR's default hit handling. The projectile
	will pass through target without any effect at all.
    */
    if (vParent == vDef)																	//Defender is parent?
    {
		changeopenborvariant("lasthitc", 0);												//Turn off OpenBOR's hit handling.
        return;																				//Exit. This is where a boomerang "catch" can go.
    }
    
    if (vTParent)																			//Target has a parent?
    {
        if(!host0001(vParent, vTParent))													//Are the target's and caller's parents non hostile?                       
        {
            changeopenborvariant("lasthitc", 0);											//Turn off OpenBOR's hit handling.
			return;																			//Exit.			
        }
    }
    
    iMP     = getentityproperty(vSelf, "mp");                                               //Get MP.
    iHP     = getentityproperty(vSelf, "health");                                           //Get HP.
    iDMP    = getentityproperty(vDef, "mp");                                                //Get defender's MP.
    
	/*
    To simulate projectile priority, we'll use MP as a free variable.
    When two projectiles collide, both must have 2 or more MP, else they will
    both be unaffected. Otherwise the one with lower MP looses 1HP for each point 
    of difference. If MP is equal, both take the equal MP amount as HP damage. 
                
	0 MP = Intangible and has no effect/does not affect other projectiles.
    1+MP = Compare. If equal, both take the full MP as HP damage. Otherwise, looser
	takes the difference.        
    */  
    if (iTTD == 4)																			//Target is a projectile?
    {
		iDHP    = getentityproperty(vDef, "health");                                        //Get defender's HP.       
        
        changeentityproperty(vParent, "opponent", vTParent);                                //Set parent's opponent to target's parent.
        changeentityproperty(vTParent, "opponent", vParent);                                //Set target's parent opponent to caller's parent.
		changeopenborvariant("lasthitc", 0);												//Turn off OpenBOR's hit handling.
        
		if (!iMP || !iDMP)																	//Either lacking MP? 
        {
            return;                                                                         //One or the other cannot be hit by a projectile at all. Exit entire script.
        }
        else																				//Both have MP >= 1?
        {
            if (iMP == iDMP)                                                                //MP equal?
            {
                iHP = iHP - iDMP;                                                           //Caller looses MP amount from HP.
                iDHP = iDHP - iMP;                                                          //Target looses MP amount from HP.
            }
            else if (iMP > iDMP)                                                            //Caller MP higher?
            {
				damageentity(vTarget, vSelf, iMP - iDMP, 0, openborconstant("ATK_NORMAL")); //Target takes difference as damage.
            }
            else if (iMP < iDMP)                                                            //Target MP higher?
            {                
				damageentity(vSelf, vTarget, iDMP - iMP, 0, openborconstant("ATK_NORMAL")); //Caller takes difference as damage.
            }
        }		
    }
    else
    {
        /*
        The entity we just hit wasn't a projectile. So instead we need to know how much penetration 
        projectile will have (how many times it can hit before stopping). Since a projectile 
        does not actively attack, we'll use aggression setting as a "free" entity variable.    
        
        -1  = Projectile never stops until offscreen (or destroyed by outside action).
        0   = Standard setting. Projectile can hit one time.
        1+  = Number of extra hits projectile can perform before negating itself.       
        */
        
        iAgg = getentityproperty(vSelf, "aggression");
        changeentityproperty(vDef, "opponent", vParent);                                    //Set Defender's opponent to parent.
        changeentityproperty(vParent, "opponent", vDef);                                    //Set Parent's opponent to Defender.

        if (iAgg == 0)                                                                      //Aggression 0?
        {
			damageentity(vSelf, vSelf, iHP, 0, openborconstant("ATK_NORMAL"));				//Damage self to death.            
        }
        else if (iAgg > 0)                                                                  //Agression 1+?
        {
            changeentityproperty(vSelf, "aggression", --iAgg);                              //Decrement aggression.
        }        
    }    
}
