void main(){
    
    void vSelf   = getlocalvar("self");                     //Calling entity. 
    int  iDamage = getlocalvar("damage");                   //Incomming damage.
    int  iMP     = getentityproperty(vSelf, "mp");          //Caller's MP.
    int  iAni    = getentityproperty(vSelf, "animationid"); //Caller's animation.    
    int  iFrame  = getentityproperty(vSelf, "animpos");     //Caller's animation frame.    
    
    //Joudan uke?
    if (iAni == openborconstant("ANI_SPECIAL2")){
    
       changeentityproperty(vSelf, "mp", iMP + (iDamage * 2)); //Reward a spirit bonus if attack is parried.
       changeentityproperty(vSelf, "aiflag", "attacking", 0);  //Set attack flag to 0 (character key script will check for this and allow canceling.
              
    }

}



