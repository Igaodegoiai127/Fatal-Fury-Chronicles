#include "data/scripts/vars/anims.h"
#include "data/scripts/vars/colors.h"
#include "data/scripts/vars/entity.h"
#include "data/scripts/com/draw0004.h"

void deat0001(){

    //Primary on death function; called by most entities when killed by damage.

    void    vSelf      = getlocalvar("self");                   //Calling entity.
    void    vAttacker  = getlocalvar("attacker");               //Damaging entity.
    int     iDType     = getlocalvar("attacktype");             //Damage type.
    int     iSet       = openborvariant("current_set");
    int     iStage     = openborvariant("current_level");
    int     iLevel     = openborvariant("current_stage");
    int     iSet       = openborvariant("current_set");
    int     iStage     = openborvariant("current_level");
    int     iLevel     = openborvariant("current_stage");
    void    vModel     = getentityproperty(vSelf, "model");     //Model name.
    void    vAlias     = getentityproperty(vSelf, "name");      //Model alias.
    int     iMap       = getentityproperty(vSelf, "map");
    int     iX         = getentityproperty(vSelf, "x");
    int     iY         = getentityproperty(vSelf, "a");
    int     iZ         = getentityproperty(vSelf, "z");
    float   iYToss     = 6;

    if (iDType == openborconstant("ATK_BURN"))
    {
		changeentityproperty(vSelf, "komap", getentityproperty(vSelf, "hmapl")+1, 1);				//Fix KOMAP
		changeentityproperty(vSelf, "nodieblink", 2);                   //Disapear as soon as last animation is finished.
    }
    else if (iDType == openborconstant("ATK_SHOCK"))
    {
		changeentityproperty(vSelf, "komap", getentityproperty(vSelf, "hmapl")+2, 1);				//Fix KOMAP
		changeentityproperty(vSelf, "nodieblink", 2);                   //Disapear as soon as last animation is finished.
    }
    else
    {
        if (vModel = "Ray"      ||
            vModel = "Ray_"     ||
            vModel = "Ray__")
        {

            if (iSet == 0 && iDType == openborconstant("ATK_NORMAL6"))  //Attack6?
            {
                //Water fatality.
                iYToss *= iZ / (openborvariant("PLAYER_MAX_Z") + 1);    //Calculate Y toss in proportion to distance from min Z.
                changeentityproperty(vSelf, "subject_to_minz", 0);      //Remove min Z limitation.
                changeentityproperty(vSelf, "falldie", 3);              //Do not play death animation.
                changeentityproperty(vSelf, "nodieblink", 2);           //Disapear as soon as last animation is finished.
                setentityvar(vSelf, NEXTANI, FWATER);                   //Play water fatality fall.
                setentityvar(vSelf, TOSSX, -1);                         //Set falling X velocity.
                setentityvar(vSelf, TOSSY, iYToss);                     //Set falling Y velocity.
                setentityvar(vSelf, TOSSZ, -0.5);                       //Set falling Z velocity.
				changeentityproperty(vSelf, "projectile", 1);			//Turn on projectile property.
            }
            else if (iDType == openborconstant("ATK_NORMAL7"))
            {
                changeentityproperty(vSelf, "falldie", 0);
                changeentityproperty(vSelf, "nodieblink", 2);
                changeentityproperty(vSelf, "subject_to_maxz", 0);
                changeentityproperty(vSelf, "position", iX, iZ, iY + 50);
                changeentityproperty(vSelf, "gfxshadow", 0);
                setentityvar(vSelf, NEXTANI, FFORE);
                setentityvar(vSelf, TOSSX, -0.5);
                setentityvar(vSelf, TOSSY, 15);
                setentityvar(vSelf, TOSSZ, 8);
				changeentityproperty(vSelf, "projectile", 1);			//Turn on projectile property.
                draw0004(0, 0, 0, 0, 0, 0, 0, 0, 0, 5);
            }
        }
    }
}
