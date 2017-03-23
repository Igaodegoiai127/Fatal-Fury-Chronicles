#include	"data/scripts/vars/anims.h"
#include	"data/scripts/vars/colors.h"
#include	"data/scripts/vars/entity.h"
#include	"data/scripts/com/ani0009.h"
#include	"data/scripts/com/bind0005.h"
#include	"data/scripts/com/draw0001.h"   
#include	"data/scripts/com/effe0001.h"
#include	"data/scripts/com/jump0001.h"
#include	"data/scripts/com/ht0001.h"

void fall0001(){
    
    //Primary falling function.

    void    vSelf       = getlocalvar("self");                                      //Calling entity.
    int     iType       = getlocalvar("attacktype");                                //Incoming attack type.
    float   fTossX      = getentityvar(vSelf, TOSSX);								//Toss X 
    float   fTossY      = getentityvar(vSelf, TOSSY);								//Toss Y
    float   fTossZ      = getentityvar(vSelf, TOSSZ);								//Toss Z 
    int     iAni        = getentityvar(vSelf, NEXTANI);                             //Animation.
    float	fY			= getentityproperty(vSelf, "a");							//Caller Y position.
	int     iBase;																	//Caller base (platform height).
    int     iHeight;																//Caller height.
	int     iHitY;                                                                  //Last hit height.   
	
    if (iType == openborconstant("ATK_BURN"))                                       //Burn attack?
    {        
        effe0001(MAPBURN);                                                          //Set effect.
    }
    else if (iType == openborconstant("ATK_SHOCK"))                                 //Shock attack?
    { 
		effe0001(MAPSHOCK);                                                         //Set effect.
    }
    else if (iType == openborconstant("ATK_NORMAL2"))                               //Attack Type 2?
    {
		iBase	=	getentityproperty(vSelf, "base");								//Caller base (platform height).	

        if ((fY - iBase)<=1)														//Caller 1 or less from the ground?
        {
            changeentityproperty(vSelf, "velocity", 0,0,0);                         //Stop moving (Fall2 is collapse in place)
        }
        else
        {
			ani0009(vSelf, openborconstant("ANI_FALL"), -1);						//Fall normally since caller was in the air.
		}
    }
    else
    {
        iHitY   =	openborvariant("lasthita");                                     //Get last hit height.        
		iHeight	=	fY + ht0001(vSelf);												//Calculate head Y positon.	

        if (iHitY)																	//Valid Hit Y? Knockdown was from low and and self not being thrown?
        {
			if(iHitY < iHeight * 0.3)												//Low hit?
			{
				if(iAni != DEFPOSE)													//Not in throw pose?
				{					
					ani0009(vSelf, SWEPT, -1);										//Set sweep animation.					
				}
			}
        }
    }

    ///////////
    if (iAni)                                                                       //Animation switch request? 
    {                     
		ani0009(vSelf, iAni, -1);													//Switch animation (if available).
        setentityvar(vSelf, NEXTANI, NULL());                                       //Clear animation switch variable.
    }  
    
    bind0005(getentityproperty(vSelf, "opponent"), 2);                              //Run bind0005. 
    
    //////////
    
    if (fTossX || fTossY || fTossZ)                                                 //Any toss values?
    {       
        if(!fTossX) fTossX = 0;                                                     //If null, set 0.
        if(!fTossY) fTossY = 0;                                                     //If null, set 0.
        if(!fTossZ) fTossZ = 0;                                                     //If null, set 0.      

        jump0001(fTossY, fTossX, fTossZ);                                           //Toss caller.
        setentityvar(vSelf, TOSSX, NULL());											//Clear toss value.
        setentityvar(vSelf, TOSSY, NULL());											//Clear toss value.     
        setentityvar(vSelf, TOSSZ, NULL());											//Clear toss value.
    }    
}