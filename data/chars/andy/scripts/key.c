#include "data/scripts/vars/entity.h"

//Andy Bogard key key capture.

void main(){
   
    int  iPlIndex   = getlocalvar("player");                                            //Player index.
    void vSelf      = getlocalvar("self");                                              //Calling entity.
    int  iIndex     = getlocalvar("player");                                            //Calling Index.
    int  iAni       = getentityproperty(vSelf, "animationID");                          //Caller animation ID.
    int  iFlIdle    = getentityproperty(vSelf, "aiflag", "idling");                     //Self idling?
    int  iFlAttack  = getentityproperty(vSelf, "aiflag", "attacking");                  //Self attacking (freespecial, jumpattack, follow, or attack)?
    int  iFlJump    = getentityproperty(vSelf, "aiflag", "jumping");                    //Self jumping?
    int  iAttackR   = playerkeys(iPlIndex, 2, "attack");                                //Release attack?                              
    int  iLeftH     = playerkeys(iPlIndex, 0, "moveleft");                              //Hold  "Left".
    int  iRightH    = playerkeys(iPlIndex, 0, "moveright");                             //Hold  "Right".
    int  iFrame;  
    int  iUp;												                            //Press Up.
    int  iDown;												                            //Press Down.
    int  iAttack;											                            //Press Attack.
    int  iJump;												                            //Press Jump.     
    int	 iXDir;
	int	 iTossV;
    int  iETime;                                                                        //Elpased time.
    int  iCost;                                                                         //Energycost.
    int  iMP;                                                                           //Current MP.
    int  iSeal;                                                                         //Current seal flag.

    if (iAni == openborconstant("ANI_FREESPECIAL14"))									//Gen'ei Shiranui. 
	{                                
        iXDir	= getentityproperty(vSelf, "xdir");
		iTossV	= getentityproperty(vSelf, "tossv");
		iFrame	= getentityproperty(vSelf, "animpos");									//Animation frame.  
		
		if (iXDir)																		//Moving horizontal?
		{            
			iUp     = playerkeys(iIndex, 0, "moveup");									//Press Up.
			iDown   = playerkeys(iIndex, 0, "movedown");								//Press Down.
			
			if (iUp)
			{
                changeentityproperty(vSelf, "velocity", iXDir, -3.5, iTossV);			//Veer.
				changeplayerproperty(vSelf, "playkeys", 0);                             //Clear key event.
            }
			else if (iDown)
			{
                changeentityproperty(vSelf, "velocity", iXDir, 3.5, iTossV);			//Veer.
				changeplayerproperty(vSelf, "playkeys", 0);                             //Clear key event.
            }
        }
		
		if (iFrame >= getentityproperty(vSelf, "landframe", iAni))
		{
			iAttack = playerkeys(iIndex, 1, "attack");									//Press Attack.
			iJump   = playerkeys(iIndex, 1, "jump");									//Press Jump. 
			
			if (iAttack)
			{
				performattack(vSelf, openborconstant("ANI_FREESPECIAL15"),1);
				changeplayerproperty(vSelf, "playkeys", 0);                             //Clear key event.
			}
			else if (iJump)
			{
				performattack(vSelf, openborconstant("ANI_FREESPECIAL16"),1);			//Gen'ei Shiranui - Uwa Agito.
				changeplayerproperty(vSelf, "playkeys", 0);                             //Clear key event.
			}			
            
		}
    }
	else if (iAni == openborconstant("ANI_FREESPECIAL16"))
	{
		iXDir	= getentityproperty(vSelf, "xdir");
		iTossV	= getentityproperty(vSelf, "tossv");
		
		if (iXDir)                                                                      //Moving horizontal?
        {																		
            if (iUp)
            {
                changeentityproperty(vSelf, "velocity", iXDir, -1.5, iTossV);			//Veer.          
            }
            else if (iDown)
            {
                changeentityproperty(vSelf, "velocity", iXDir, 1.5, iTossV);			//Veer.
            }
        }
	}
}