void paus0001(int iToggle, int iTime){

    /*
    paus0001
    Damon Vaughn Caskey
    11022009
    Pause or unpause action for all entities except self.
    */

    void vSelf      = getlocalvar("self");                  //Caller    
    int  iETime     = openborvariant("elapsed_time");       //Current time.
    int  iMax       = openborvariant("ent_max");            //Entity count.
    int  iEntity;                                           //Loop counter.
    void vEntity;                                           //Target entity.

    for(iEntity=0; iEntity<iMax; iEntity++)
    {    
        vEntity = getentity(iEntity);                                       //Get target entity from current loop.        
        
        if (vEntity != vSelf)                                               //Not Self?
        {
            changeentityproperty(vEntity, "frozen", iToggle);               //Toggle frozen.
            changeentityproperty(vEntity, "freezetime", iETime + iTime);    //Toggle frozen time.
        }
    }    
}