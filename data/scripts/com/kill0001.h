#include "data/scripts/vars/colors.h"
#include "data/scripts/vars/entity.h"
#include "data/scripts/com/bind0008.h"
#include "data/scripts/com/draw0001.h"

void kill0001()
{
    /*
    kill0001
    Damon Vaughn Caskey
    05/13/2007
    Primary on kill function. Run for most entities when engine removes them from play.
    */

    void    vSelf   = getlocalvar("self");                      //Caller.
    void    vParent = getentityproperty(vSelf, "parent");       //Caller's parent.
    int     iAni    = getentityproperty(vSelf, "animationid");  //Current animation.
    int     iMaxVar = openborvariant("maxentityvars");          //Module entity var max.
    void    vBindhe;                                            //Bound hit effect entity.
    int     iCount;                                             //Loop counter.
    void    vSpawn;                                             //Spawn entity.

    if (iAni == openborconstant("ANI_BURNDIE"))                 //Self in burning death?
    {
        if (getentityproperty(vSelf, "model") != "effe0001")    //Self not the fatality or effect model?
        {
            vBindhe = getentityvar(vSelf, BINDHE);              //Get any bound effect.
            
            if (getentityproperty(vBindhe, "exists"))           //Bound effect exists?
            { 
                killentity(vBindhe);                            //Then kill it.
            }
            
            vSpawn = bind0008("effe0001", "effe0001", MAPBURN, 0, 0, 0, 0, 1, openborconstant("ANI_FOLLOW14"), 0, 0);   //Spawn fatality model.
            
            //Quick and dirty fix for burn fatality; default image size is too large.
            setentityvar(vSpawn, ADSCALEX, 0.75);               //Draw scale X adjustment.
            setentityvar(vSpawn, ADSCALEY, 0.75);               //Draw scale Y adjustment.
            draw0001(vSpawn);                                   //Apply draw settings.
        }
    }
    else if (iAni == openborconstant("ANI_SHOCKDIE"))
    {
    }    

    if (getentityproperty(vParent, "exists"))                   //Parent exists?
    {
         vBindhe = getentityvar(vParent, BINDHE);               //Get parent's bound effect variant.
         if (vBindhe == vSelf)                                  //Was bound effect same as self?
         {
            setentityvar(vParent, BINDHE, NULL());              //Clear parent's bound effect variant.
            setentityvar(vParent, ADREMAP, NULL());             //Clear parent's remap.
            draw0001(vParent);                                  //Update parent's draw.
         }         
    }    

    for (iCount = 0; iCount <= iMaxVar; iCount++)               //Loop through all indexed entity vars.
    {
         setentityvar(vSelf, iCount, NULL());                   //Clear variant.
    } 
}
