#include "data/scripts/vars/entity.h"
#include "data/scripts/com/draw0001.h"

void effe0001(int iMap){

    /*
    effe0001
    Damon Vaughn Caskey
    09/15/2009
    Spawn and bind effect entity. It might seem like a good idea to run this as part of a takedamage script,
    but that won't work. At that point the engine has not set defender to appropriate reactive animation yet.
    Therefore an animation match bind will kill the effect spawn instantly.

    vName:      Model name of spawn.
    */

    void  vSelf     = getlocalvar("self");                  //Caller.
    void  vModel    = "effe0001";                           //Model.
    void  vBound    = getentityvar(vSelf, BINDHE);          //Previous effect entity.
    float fHeight   = getentityproperty(vSelf, "height");   //Caller's height.
    void  vSpawn;                                           //New spawn placeholder.
    float fRatio;                                           //Caller's current scale ratio.
    float fX;                                               //Caller X location.
    float fZ;                                               //Caller Z location.
    float fY;                                               //Caller Y location.
    int   iHt;                                              //Center height.

    if (vBound)                                             //Previous effect entity in place?
    {
        if (vModel == getentityproperty(vBound, "model"))   //Previous same as proposed?
        {
            return;                                         //Exit.
        }
        else
        {
            killentity(vBound);                             //Kill old effect.
        }
    }

    fRatio    = getentityvar(vSelf, ADSCALER);              //Get Parent current scale ratio.
    fHeight   = getentityproperty(vSelf, "height");         //Get Y height.
    fX        = getentityproperty(vSelf, "x");              //Get caller X location.
    fZ        = getentityproperty(vSelf, "z");              //Get caller Z location.
    fY        = getentityproperty(vSelf, "a");              //Get caller A location.

    clearspawnentry();                                      //Clear current spawn entry.
    setspawnentry("name",   vModel);                        //Aquire spawn entity by name.
    setspawnentry("coords", fX, fZ, fY);                    //Spawn location.
    setspawnentry("map", iMap);                             //Spawn map.
    vSpawn = spawn();                                       //Spawn entity.
    clearspawnentry();                                      //Clear current spawn entry.
    changeentityproperty(vSpawn, "parent", vSelf);          //Set caller as parent of spawn.
    setentityvar(vSelf, SPAWN, vSpawn);                     //Store spawn.

    bindentity(vSpawn, vSelf, 0, 1, fHeight * 0.4, 1, 4);   //Execute bind.
    setentityvar(vSelf, BINDHE, vSpawn);                    //Store bind.
    setentityvar(vSpawn, ADBLEND, 1);						//Apply alpha mode 1.
	dc_draw_z_position_autoscale(vSpawn);                                       //Apply draw.
}
