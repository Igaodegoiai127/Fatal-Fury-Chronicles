#include "data/scripts/vars/entity.h"

void hit0001(int iDamage, int iFinish, void vType, float fTossX, float fTossY, float fTossZ, int iDrop, int iReset, int iWarpX, int iWarpY, int iWarpZ, int iWarpT, int M){

    /*
    hit0001
    Damon Vaughn Caskey
    11292007
    Sets up damage and other effects to be applied during didhitscript.
    */

    void vSelf = getlocalvar("self");    

    if(vType == -2)                               //If attack type = -2, delete all hit flags.
    {
        setentityvar(vSelf, HITDMG,   NULL());    //Damage.
        setentityvar(vSelf, HITFIN,   NULL());    //Leathal/non leathal damage.
        setentityvar(vSelf, HITTYP,   NULL());    //Attack type.
        setentityvar(vSelf, HITDRP,   NULL());    //Drop.
        setentityvar(vSelf, TOSSX,    NULL());    //Toss X
        setentityvar(vSelf, TOSSY,    NULL());    //Toss Y
        setentityvar(vSelf, TOSSZ,    NULL());    //Toss Z
        setentityvar(vSelf, HITNOR,   NULL());    //Remove flags on hit toggle.
        setentityvar(vSelf, HITWRX,   NULL());    //Move defender to attacker with X adjust.
        setentityvar(vSelf, HITWRY,   NULL());    //Move defender to attacker with Y adjust.
        setentityvar(vSelf, HITWRZ,   NULL());    //Move defender to attacker with Z adjust.
        setentityvar(vSelf, HITWRT,   NULL());    //Only move if in pain or fall.
    }
    else
    {
        setentityvar(vSelf, HITDMG,   iDamage);   //Damage.
        setentityvar(vSelf, HITFIN,   iFinish);   //Leathal/non leathal damage.
        setentityvar(vSelf, HITTYP,   vType);     //Attack type.
        setentityvar(vSelf, HITDRP,   iDrop);     //Drop.
        setentityvar(vSelf, TOSSX,    fTossX);    //Toss X
        setentityvar(vSelf, TOSSY,    fTossY);    //Toss Y
        setentityvar(vSelf, TOSSZ,    fTossZ);    //Toss Z
        setentityvar(vSelf, HITNOR,   iReset);    //Remove flags on hit toggle.
        setentityvar(vSelf, HITWRX,   iWarpX);    //Move defender to attacker with X adjust.
        setentityvar(vSelf, HITWRY,   iWarpY);    //Move defender to attacker with Y adjust.
        setentityvar(vSelf, HITWRZ,   iWarpZ);    //Move defender to attacker with Z adjust.
        setentityvar(vSelf, HITWRT,   iWarpT);    //Only move if in pain or fall.
    }
}