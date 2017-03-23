#include "data/scripts/vars/entity.h" 
#include "data/scripts/vars/sounds.h"		//Sound group constants.
#include "data/scripts/com/bind0012.h"
#include "data/scripts/com/hit0001.h"
#include "data/scripts/com/jump0002.h"
#include "data/scripts/com/bloc0002.h"
#include "data/scripts/com/soun0005.h"

void hit0002(){
    
    //Primary didhit function; called by almost all entities when hitting another entity.

    void  vSelf         = getlocalvar("self");                  //Calling entity. 
    void  vDef			= getlocalvar("damagetaker");			//Defender.  
    int   iType         = getentityvar(vSelf, HITTYP);          //On hit flag (type).
    int   iReset        = getentityvar(vSelf, HITNOR);          //On hit flag (reset on hit).
    int   iEDamage;                                             //Extra damage flag.
    int   iELethal;                                             //Non leathal damage (damage cannot reduce HP below 1) flag.    
    int   iEDrop;                                               //Extra damage drop flag.
    int   iReset;                                               //No reset flag.
    float fTossX;                                               //Toss X.
    float fTossY;                                               //Toss Y.
    float fTossZ;                                               //Toss Z.
    int   iHeight;                                              //Tagret's height setting.
    int   iDefHP;                                               //Defender's health.    
    int   iDrop;                                                //Attaclk knockdown power.
    int   iKnock;                                               //Defender's kncodkown remaining.
	int		iBloc		= getlocalvar("blocked");	
	int		iProj;
	int		iAIDrop;
	int		iDrop;
	int		iKnock;	
	int		iType;
	int		iAni;

    if (iBloc)													//Attack blocked?
    {     
		bloc0002(vDef, 0.1);                                    //Run block function.

        if (iType && !iReset)                                   //Hit flag type present but reset flag not? 
        {                               
            hit0001(0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);    //Erase hit flags.
        }
    }
    else                                                        
    {
        if(iType)                                               //Extra damage type not null??
        {            
            //Get remaining hit flags and defender values.
            iEDamage    = getentityvar(vSelf, HITDMG);            
            iELethal    = getentityvar(vSelf, HITFIN);                    
            iEDrop      = getentityvar(vSelf, HITDRP);                        
            fTossX      = getentityvar(vSelf, TOSSX);             
            fTossY      = getentityvar(vSelf, TOSSY);             
            fTossZ      = getentityvar(vSelf, TOSSZ);
            iReset      = getentityvar(vSelf, HITNOR);
                        
            iDefHP      = getentityproperty(vDef, "health");						//Get Defender's health.

            if (iType == -1)                                                        //If -1 passed, use incoming attack type.
            { 
                iType = getlocalvar("attacktype");
            }

            if (!iEDamage)                          { iEDamage = 0;             }   //If NULL(), convert to 0.
            if (!iEDrop)                            { iEDrop   = 0;             }   //If NULL(), convert to 0.
            if (iELethal && (iEDamage >= iDefHP))   { iEDamage  = iDefHP - 1;   }   //If non lethal damage exceeds HP, reduce to remaining HP - 1.
            if (iEDamage >= iDefHP)                 { iEDrop    = 100;          }   //If final value will kill defender, make sure to drop them. Otherwise they will be left on screen in an idle state.
            
            damageentity(vDef, vSelf, iEDamage, iEDrop, iType);						//Apply final damage values to vDefender.           

            if (fTossX || fTossY || fTossZ)                                         //Toss effect added? Set variables on vDefender to apply in onfallscript.
            { 
                iKnock = getentityproperty(vDef, "knockdowncount");					//Get defender's remaining knockdown.
                iDrop  = getlocalvar("drop");

                if (iEDrop > iKnock || iDrop > iKnock)                              //Will defender be knocked down?
                {
                    if (getentityproperty(vDef, "direction"))						
                    { 
                        fTossX = -fTossX; 
                    }        
                    tossentity(vDef, fTossY, fTossX, fTossZ);							//Toss opponent.                    					
                }
            }               

            bind0012(vDef);															//Run hitwarp.             
        } 		

		iKnock = getentityproperty(vDef, "knockdowncount");							//Get defender's remaining knockdown.
		iDrop  = getlocalvar("drop");

		if (iEDrop > iKnock || iDrop > iKnock)										//Will defender be knocked down?
        {

			iType	= getentityproperty(vSelf, "type");								//Get type.
			iProj	= getentityproperty(vSelf, "projectile");						//Get projectile flag.
			iAIDrop = getentityproperty(vSelf, "aiflag", "drop");					//Get AI Drop flag.
			iAni	= getentityproperty(vSelf, "animationid");						//Get animation.
					
			if(!iAIDrop && !iProj && iAni != openborconstant("ANI_FOLLOW10"))		//Not falling, tossed or in grappled pose?
			{
				if (iType == openborconstant("TYPE_PLAYER"))						//Player type?
				{
					log("\n Test: " + soun0005(vSelf, VOIBTL, -1, 1, 0, 0));		//Battle cry (50%).
				}
				else
				{
					soun0005(vSelf, VOIBTL, -1, 1, 0, 0);							//Battle cry.
				}
			}
		}

        if (!iReset)                                                                //No reset flag?
        {
            hit0001(0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);                        //Erase hit flags.
        }
    }    
}