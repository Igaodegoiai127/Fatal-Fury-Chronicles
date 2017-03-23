#include	"data/scripts/vars/entity.h"
#include	"data/scripts/com/key0003.h"

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
    int  iKey1AT;                                                                       //Time of last key 1 press.
    int  iCost;                                                                         //Energycost.
    int  iMP;                                                                           //Current MP.
    int  iSeal;                                                                         //Current seal flag.	
		
    if (iAttackR && iFlIdle && !iFlJump)                                                //Release attack while idle and not jumping?
    {
        if (key0003(vSelf, iLeftH, iRightH))                                            //Holding forward?
        {
            iETime  = openborvariant("elapsed_time");                                   //Get elapsed time.
            iKey1AT = getentityvar(vSelf, KEY1AT) + 500;                                //Get last Attack press.

            if (iKey1AT < iETime)                                                       //Enough time passed?
            {				
                iAni    = openborconstant("ANI_FREESPECIAL12");                         //Set ani to Zaneiken.
                iCost   = getentityproperty(vSelf, "energycost", iAni, 0);              //Get energy cost.
                iMP     = getentityproperty(vSelf, "mp");                               //Get current mp.
                iSeal   = getentityproperty(vSelf, "seal");                             //Get seal flag.
                
                if (iCost <= iMP && (!iSeal || iCost < iSeal))                          //Have enough MP and not sealed?
                {
                    performattack(vSelf, iAni, 0);                                      //Perform Zaneiken.                    
                    changeentityproperty(vSelf, "mp", iMP - iCost);                     //Apply energycost.
                    changeplayerproperty(vSelf, "playkeys", 0);                         //Clear key event.
                    return;                                                             //Exit.
                }
            }
        }
    }

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
	else if (iAni == openborconstant("ANI_FREESPECIAL16"))								//In gen'ei Shiranui - Uwa Agito?
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