void run0001()
{
    /*
    run0001
    Damon Vaughn Caskey
    11/03/2007    
    Stop running. used to create dash step from running animation.
    */

    void vSelf = getlocalvar("self");

    changeentityproperty(vSelf, "aiflag", "running", 0);
    changeentityproperty(vSelf, "velocity", 0, 0, 0);
    changeentityproperty(vSelf, "animation", openborconstant("ANI_IDLE"));
}