#include "data/scripts/com0001.c"

void alt0001(int iMP, void vAni){

    /*
    alt0001
    Damon Vaughn Caskey
    05/13/2007
    Control use of MAX Attacks. Run on startup.
    */

	void  vSelf  = getlocalvar("self");                             //Caller.
	int   iMaxHP = getentityproperty(vSelf, "maxhealth");           //Caller max HP.
	int   iHP    = getentityproperty(vSelf, "health");              //Caller current HP.
	int   iCMP   = getentityproperty(vSelf, "mp");                  //Caller current MP.

    
	if (vAni == "SAME"){

        //HP at or less then 25% of Max?
        if (iHP <= iMaxHP * 0.25) { 
            
            //Enough mp?
            if (iCMP < iMP){ 
                performattack(vSelf, openborconstant("ANI_CANT"));	        //Switch animation.
            }
            else
            {
                changeentityproperty(vSelf, "mp", iCMP - iMP);              //Subtract MP cost.
            }
            return;                    
        }
        
        changeentityproperty(vSelf, "aiflag", "idling", 1);                 //Go back to idle (do nothing).
    }
    else
    {
     
        //HP at or less then 25% of Max.
        if (iHP <= iMaxHP * 0.25) { 

            //Enough mp?
            if (iCMP < iMP){ 
                performattack(vSelf, openborconstant("ANI_CANT"));	    //Switch animation.
            }else{
                changeentityproperty(vSelf, "mp", iCMP - iMP);          //Subtract MP cost.
                performattack(vSelf, openborconstant(vAni));	        //Switch animation.
            }                    
        }
        else
        {
            //Enough mp?
            if (iCMP < iMP){ 
                performattack(vSelf, openborconstant("ANI_CANT"));	        //Switch animation.
            }else{
                changeentityproperty(vSelf, "mp", iCMP - iMP);              //Subtract MP cost.
            }            
        }
    }
}

void mrka0001(void vAni, int iFrame){

    /*
    alt0001
    Damon Vaughn Caskey
    03/13/2007
    If using Mr. Karate color map, switch to alternate animation.
    */

    void  vSelf  = getlocalvar("self");         //Caller.
    int iMap = getentityvar(vSelf, 4);          //Caller's selected map.    

    if (iMap >= 10 && iMap <= 14)
    {
        changeentityproperty(vSelf, "animation", openborconstant(vAni));
    }

}

void mrka0002(){

    void  vSelf  = getlocalvar("self");                   //Caller.
    int   iMap   = getentityvar(vSelf, 4);                //Caller's selected map.    
    int   iDir   = getentityproperty(vSelf, "direction"); //Caller's direction.
    int   fX     = 0.3;
    
    if (!(iMap >= 10 && iMap <= 14))
    {
        if (!iDir){ fX = -fX; }        
        changeentityproperty(vSelf, "velocity", fX, 0, 0);                   //Stop caller movement.
    }
}
