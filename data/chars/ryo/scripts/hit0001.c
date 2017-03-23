#include "data/scripts/com0001.c"

void main(){
    
    void  vSelf    = getlocalvar("self");                     //Calling entity. 
    int   iMaxHP   = getentityproperty(vSelf, "maxhealth");   //Caller max HP.
	int   iHP      = getentityproperty(vSelf, "health");      //Caller current HP.    
    void  vTarget  = getlocalvar("damagetaker");              //Hit entity.
    int   iTarType = getentityproperty(vTarget, "type");      //Target's entity type.
    int   iBlock   = getlocalvar("blocked");                  //If target blocked attack.    
    int   iTarHP   = getentityproperty(vTarget, "health");    //Target's HP.
    int   iDir     = getentityproperty(vSelf, "direction");   //caller's facing.
    int   iAni     = getentityproperty(vSelf, "animationid"); //Caller's animation.    
    int   iFrame   = getentityproperty(vSelf, "animpos");     //Caller's animation frame.    
    float fX       = getentityproperty(vSelf, "x");           //Caller's X location.
    float fZ       = getentityproperty(vSelf, "z");           //Caller's Z location.
    float fY       = getentityproperty(vSelf, "a");           //Caller's Y location.
    
    //Renbu or Max renbu startup.
    if (iAni == openborconstant("ANI_FREESPECIAL12") || iAni == openborconstant("ANI_FOLLOW17"))
    {   
        changeentityproperty(vSelf, "velocity", 0 ,0 ,0);                   //Stop caller movement.
                
        //Wasn't blocked and is a valid target? Set up target for the autocombo.
        if (!iBlock && (iTarType == openborconstant("TYPE_ENEMY") || iTarType == openborconstant("TYPE_NPC") || iTarType == openborconstant("TYPE_PLAYER")))
        {
                        
            ryobind0001(vSelf, vTarget);                                    //Force target to be right in front of caller.
            changeentityproperty(vTarget, "aiflag", "falling", 0);          //Set target fall flag to FALSE.
            changeentityproperty(vTarget, "velocity", 0, 0, 0);             //Stop target movement.
        
            if (iTarHP >= 7) { changeentityproperty(vTarget, "health", iTarHP - 6); } //Apply damage if target can withstand it.
        
        }      
    
    //Renbu or Max Renbu followup.
    }
    else if (iAni == openborconstant("ANI_FOLLOW13") || iAni == openborconstant("ANI_FOLLOW15"))
    {            
        
        if (iTarHP >= 7) { changeentityproperty(vTarget, "health", iTarHP - 6); } //apply damage if target can withstand it.
        
        ryobind0001(vSelf, vTarget);                                        //Force target to be right in front of caller.
          
        //Last attack hit.
        if (iFrame >= 52 && iFrame <= 60)
        {
            setentityvar(vSelf, 3, "ANI_FOLLOW14");                   //Normal Kohou finish. 
        }
        else if(iFrame >= 70)
        {
            setentityvar(vSelf, 3, "ANI_FOLLOW16");                   //Max Kohou finish.
        }

    //Renbu or Max renbu kohou finisher.
    }
    else if (iAni == openborconstant("ANI_FOLLOW14") || iAni == openborconstant("ANI_FOLLOW16"))    
    {
        if (iTarHP >= 9) { changeentityproperty(vTarget, "health", iTarHP - 8); }        
    
    //Heaven Glaze Punch
    }
    else if (iAni == openborconstant("ANI_FREESPECIAL11"))
    {
        if (!iBlock){ 
            setentityvar(vSelf, 3, "ANI_FOLLOW12");                     //Strike a pose.
            setentityvar(vTarget, 1, 1000);                             //Jack up opponent's stun value. Dizzy time!
        }

    //Mr. Karate Special.
    }
    else if (iAni == openborconstant("ANI_FOLLOW28"))
    {
        if (!iBlock){ 
            setentityvar(vSelf, 3, "ANI_FOLLOW12");                     //Strike a pose.            
        }
    
    //Mr. Karate Ranbu followup.
    }
    else if (iAni == openborconstant("ANI_FOLLOW29"))
    {
        performattack(vTarget, openborconstant("ANI_FOLLOW20"));        //Make opponent dizzy.
    
        //HP less then 25% of Max?
	    if(iHP <= iMaxHP * 0.25)
	    {	     
            setentityvar(vSelf, 3, "ANI_FOLLOW31");	                    //Hop back and hoahshokoken them 3 times. >:D     
	    }
        else
        {
            setentityvar(vSelf, 3, "ANI_FOLLOW30");                     //Hop back and hoahshokoken them once.     
        }
    
    //Mr. Karate MAX ranbu finish.
    }
    else if (iAni == openborconstant("ANI_FOLLOW31"))
    {
        if (iTarHP >= 13) { changeentityproperty(vTarget, "health", iTarHP - 12); }
    
    //Mr. Karate Special2.
    }
    else if (iAni == openborconstant("ANI_FOLLOW33"))
    {
        if (!getentityproperty(vTarget, "aiflag", "falling"))
        {
            changeentityproperty(vSelf, "velocity", 0, 0, 0);         //Stop movement.
            setentityvar(vSelf, 3, "ANI_FOLLOW34");                   //Max Kohou finish.    
        }
    //Mr. Karate Special2 follow up.
    }
    else if (iAni == openborconstant("ANI_FOLLOW34"))
    {
        if (iTarHP >= 3) { changeentityproperty(vTarget, "health", iTarHP - 2); }
    }
    //Zanretsuken finish?
    else if (iAni == openborconstant("ANI_FOLLOW9"))
    {
        if (iFrame <= 40){
            ryobind0002(vSelf, vTarget);                                        //Force target to be right in front of caller.
        }
    } 

}

void ryobind0001(void vSelf, void vTarget){

    float fX     = getentityproperty(vSelf, "x");         //Caller's X location.
    float fZ     = getentityproperty(vSelf, "z");         //Caller's Z location.
    float fY     = getentityproperty(vSelf, "a");         //Caller's Y location.
    int   iDir   = getentityproperty(vSelf, "direction"); //caller's facing.
    float fRatio = getentityvar(vSelf, 14);               //Caller current scale ratio.
    float fAdj;

    if (!fRatio){
        fAdj = 60;
    }else{
        fAdj = 60 * fRatio; 
    }

    if (iDir)
    {
        changeentityproperty(vTarget, "position", fX + fAdj, fZ, 0);  //Set target position.
    }else{
        changeentityproperty(vTarget, "position", fX - fAdj, fZ, 0);  //Set target position.
    }
    performattack(vTarget, openborconstant("ANI_PAIN"), 1);         //Set target animation to pain (in case caught in the air).            
}

void ryobind0002(void vSelf, void vTarget){

    float fX     = getentityproperty(vSelf, "x");         //Caller's X location.
    float fZ     = getentityproperty(vSelf, "z");         //Caller's Z location.
    float fY     = getentityproperty(vSelf, "a");         //Caller's Y location.
    float fTY    = getentityproperty(vTarget, "a");       //Caller's Y location.
    int   iDir   = getentityproperty(vSelf, "direction"); //caller's facing.
    float fRatio = getentityvar(vSelf, 14);               //Caller current scale ratio.
    float fAdj;

    if (!fRatio){
        fAdj = 50;
    }else{
        fAdj = 50 * fRatio; 
    }

    if (iDir)
    {
        changeentityproperty(vTarget, "position", fX + fAdj, fZ + 1, fTY);  //Set target position.
    }else{
        changeentityproperty(vTarget, "position", fX - fAdj, fZ + 1, fTY);  //Set target position.
    }
}
