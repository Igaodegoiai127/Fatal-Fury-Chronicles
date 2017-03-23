
void main(){
   
    void vSelf  = getlocalvar("self");                     //Calling entity.
    int  iIndex = getlocalvar("player");                   //Calling Index.
    int  iAni   = getentityproperty(vSelf, "animationID"); //Caller animation ID.
    int  iXPos  = openborvariant("xpos");                  //Screen position.
    int  iX     = getentityproperty(vSelf, "x");           //Caller X location.
    int  iKey   = getplayerproperty(iIndex, "playkeys");   //keyset (for deleting keys).
    int  iJump  = playerkeys(iIndex, 1, "jump");           //Press Jump.    
    int  iHDown = playerkeys(iIndex, 0, "down");           //Hold Down.
    int  iHSpec = playerkeys(iIndex, 0, "special");        //Hold Special
    int  iSpec  = playerkeys(iIndex, 1, "special");        //Press Special.
    int  iRSpec = playerkeys(iIndex, 2, "special");        //Release Special.
    void vModel = getentityproperty(vSelf, "model");       //Current model name.
    
    //If attack flag turned off by block script, key is not special release, and still in parry animation,
    //cancel parry ito idle so incomming key will perform normal action.
    if (iAni == openborconstant("ANI_SPECIAL2") && !getentityproperty(vSelf, "aiflag", "attacking") && !iRSpec)
    {
        changeentityproperty(vSelf, "aiflag", "idling", 1);
        return;
    }
    
    //Jump key press?
    if (iJump)
    {   
        //Default model?
        if (vModel == "Ryo_")
        {

            //Jumping?
            if(iAni == openborconstant("ANI_JUMP") || iAni == openborconstant("ANI_FORWARDJUMP"))
            {   
                //Left edge?           
                if (iX <= iXPos + 15)
                {                 
                    changeentityproperty(vSelf, "direction", 0);
                    changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW11"));      //Triangle Jump.
                
                //Right edge?                    
                }else if (iX >=  iXPos + 465)
                {           
                    changeentityproperty(vSelf, "direction", 1);
                    changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW11"));      //Triangle jump.
                }                              
            }

        //Crouching model?
        }else if(vModel == "Ryod")
        {
            performattack(vSelf, openborconstant("ANI_FOLLOW18"));                                  //Stand up from crouching.
            changeplayerproperty(iIndex, "playkeys", iKey - openborconstant("FLAG_JUMP"));          //Nullify jump key.
        }
    }
}
