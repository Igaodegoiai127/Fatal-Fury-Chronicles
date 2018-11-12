#include "data/scripts/vars/entity.h" 

void hit0002(){
    
    //Primary didhit function; called by almost all entities when hitting another entity.

    void  vSelf         = getlocalvar("self");                  //Calling entity. 
    void  vDefender;                                            //Defender.  
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

    if (getlocalvar("blocked"))                                 //Attack blocked?
    {       
    }
    else                                                        
    {        
        vDefender   = getlocalvar("damagetaker");               //Get defender.        

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
                        
            iDefHP      = getentityproperty(vDefender, "health");                   //Get Defender's health.

            if (iType == -1)                                                        //If -1 passed, use incoming attack type.
            { 
                iType = getlocalvar("attacktype");
            }

            if (!iEDamage)                          { iEDamage = 0;             }   //If NULL(), convert to 0.
            if (!iEDrop)                            { iEDrop   = 0;             }   //If NULL(), convert to 0.
            if (iELethal && (iEDamage >= iDefHP))   { iEDamage  = iDefHP - 1;   }   //If non lethal damage exceeds HP, reduce to remaining HP - 1.
            if (iEDamage >= iDefHP)                 { iEDrop    = 100;          }   //If final value will kill defender, make sure to drop them. Otherwise they will be left on screen in an idle state.
            
            damageentity(vDefender, vSelf, iEDamage, iEDrop, iType);                //Apply final damage values to vDefender.           

            if (fTossX || fTossY || fTossZ)                                         //Toss effect added? Set variables on vDefender to apply in onfallscript.
            { 
                iKnock = getentityproperty(vDefender, "knockdowncount");            //Get defender's remaining knockdown.
                iDrop  = getlocalvar("drop");

                if (iEDrop > iKnock || iDrop > iKnock)                              //Will defender be knocked down?
                {
                    if (getentityproperty(vDefender, "direction"))
                    { 
                        fTossX = -fTossX; 
                    }        
                    tossentity(vDefender, fTossY, fTossX, fTossZ);                  //Toss opponent. 
                    //setentityvar(vDefender, TOSSX, fTossX);
                    //setentityvar(vDefender, TOSSY, fTossY);
                    //setentityvar(vDefender, TOSSZ, fTossZ);
                }
            }                         
        }         
    }    
}
