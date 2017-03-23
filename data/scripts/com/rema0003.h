#include "data/scripts/vars/colors.h"          
#include "data/scripts/com/targ0001.h"

void rema0003(void vTar, int iTime, void vMap){

    /*
    mapko
    Damon Vaughn Caskey
    08/23/2008
    Map designated target from list of constants.

    vTar: Target. See targ0001 function.
    */

    void vSelf      = getlocalvar("self");  //Caller.
    void vTarget    = targ0001(vTar, vSelf); //target.

    if      (vMap == "MAPKO")       { vMap = MAPKO;       }   //KO.
    else if (vMap == "MAPBURN")     { vMap = MAPBURN;     }   //Burn.
    else if (vMap == "MAPSHOCK")    { vMap = MAPSHOCK;    }   //Shock.
    else if (vMap == "MAPFREEZ")    { vMap = MAPFREEZ;    }   //Freeze.
    else if (vMap == "MAPPOIS")     { vMap = MAPPOIS;     }   //Poison.

    if (iTime)
    {                                                                                       //Time provided? If so, map will be temporary.
        changeentityproperty(vTarget, "colourmap", vMap);                                   //Set temporary map.
        changeentityproperty(vTarget, "maptime", openborvariant("elapsed_time") + iTime);   //Set temporary maptime.
    }
    else
    {                                                                                       //No time provided. Map will be permenant.
        changeentityproperty(vTarget, "map", vMap);                                         //Set map.
    }
}
