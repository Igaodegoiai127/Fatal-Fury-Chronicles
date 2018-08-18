/*
Update script:

Terry Bogard
*/
/*
#include "data/scripts/vars/entity.h"

void main(){

    void    vSelf   = getlocalvar("self");
    float   fX      = getentityproperty(vSelf, "x");
    float   fY      = getentityproperty(vSelf, "a");
    float   fZ      = getentityproperty(vSelf, "z");
    float   fScale  = 256 * getentityvar(vSelf, ADSCALER);                                  //Get current scale ratio.
    void    vSprite = getentityproperty(vSelf, "sprite");
    int     iDir    = !getentityproperty(vSelf, "direction");
    int     iAni    = getentityproperty(vSelf, "animationid");

    if (!openborvariant("in_selectscreen"))
    {
        setdrawmethod(NULL(), 1, fScale, fScale, iDir, 0, 0, 6, 0, 255, 0, 0, 0);                 //Set global draw method.
        drawsprite(vSprite, fX-openborvariant("xpos"), fZ-fY-openborvariant("ypos"), fZ, 0);  //Draw stored sprite.
        setdrawmethod(NULL(), 0, 256, 256, 0, 0, 0, 0, 0, 0);                                   //Clear global drawmethod.
    }
}
