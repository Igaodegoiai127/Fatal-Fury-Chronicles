/*
On hit for Andy Bogard.
*/

void main()
{
    
    void vSelf      = getlocalvar("self");                                                  //Calling entity.  
    int  iAni       = getentityproperty(vSelf, "animationid");                              //Caller animation.
    void vDefender;                                                                         //Defender (entity taking hit).
    int  iDBase;                                                                            //Defender base.
    int  iDY;                                                                               //Defender Y.
    int  iX;                                                                                //Caller X.
    int  iZ;                                                                                //Caller Z.
    int  iDType;                                                                            //Defender type.
    int  iBlock     = getlocalvar("blocked");                                               //Attack blocked?
    int  istatus    = getentityvar(vSelf, "entity_status");                                          //Power up status.

    if (iAni == openborconstant("ANI_FREESPECIAL19") 
        || iAni == openborconstant("ANI_FREESPECIAL21"))                                    //Bakushin or Ku Bakushin freespecial?
    {
        vDefender   = getlocalvar("damagetaker");                                           //Get defender.
        iDType      = getentityproperty(vDefender, "type");                                 //Get defender type.                
        
        if (iDType != openborconstant("TYPE_OBSTACLE"))
        {
            iDBase      = getentityproperty(vDefender, "base");                             //Get defender's base.
            iDY         = getentityproperty(vDefender, "a");                                //Get defender's height.
            
            if (iDY == iDBase)                                                              //Defender not airborne?
            {
                iX  = getentityproperty(vSelf, "x");                                        //Get self X.
                iZ  = getentityproperty(vSelf, "z");                                        //Get self Z.
                changeentityproperty(vDefender, "velocity", 0, 0, 0);                       //Stop defender movement.
                changeentityproperty(vSelf, "velocity", 0, 0, 0);                           //Stop caller movement.
                changeentityproperty(vSelf, "position", iX, iZ, iDY);                       //Sync caller position to defender.
                changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW5"));   //Ground followup.
            }
            else
            {
                changeentityproperty(vDefender, "velocity", 0, 0, 0);                       //Stop defender movement.              
                changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW6"));   //Air follow up.
            }
        }        
    }

    if (!iBlock && istatus == 1) //Attack not blocked and in power up mode?
    {
		// Shadow hit function.
    } 
}




