#include	"data/scripts/vars/colors.h"       //Color constants.
#include	"data/scripts/vars/entity.h"
#include	"data/scripts/com/bind0008.h"
#include	"data/scripts/com/draw0001.h"
#include	"data/scripts/com/draw0006.h"
#include	"data/scripts/com/vars0001.h"

void kill0001()
{
    /*
    kill0001
    Damon Vaughn Caskey
    05/13/2007
    Primary on kill function. Run for most entities when engine removes them from play.
    */

    void    vSelf   = getlocalvar("self");													//Caller.
    void    vParent = getentityproperty(vSelf, "parent");									//Caller's parent.
    int     iAni    = getentityproperty(vSelf, "animationid");								//Current animation.
    void    vBindhe;																		//Bound hit effect entity.
    void    vSpawn;																			//Spawn entity.

    if (iAni == openborconstant("ANI_BURNDIE"))												//Self in burning death?
    {
        if (getentityproperty(vSelf, "model") != "effe0001")								//Self not the fatality or effect model?
        {
            vBindhe = getentityvar(vSelf, BINDHE);											//Get any bound effect.
            
            if (getentityproperty(vBindhe, "exists"))										//Bound effect exists?
            { 
                killentity(vBindhe);														//Then kill it.
            }
            
			vSpawn = bind0008("effe0001", "effe0001", 11,      1, 0, 60, 2, 2, openborconstant("ANI_FOLLOW2"), 0, 1);	//Spawn ball explosion.
            draw0006(vSpawn, vSelf);

			vSpawn = bind0008("effe0001", "effe0001", MAPBURN, 0, 0, 0, 0, 1, openborconstant("ANI_FOLLOW14"), 0, 0);   //Spawn fatality model.
            draw0006(vSpawn, vSelf);																					//Match fatality model size to self.
        }
    }
    else if (iAni == openborconstant("ANI_SHOCKDIE"))
    {
		if (getentityproperty(vSelf, "model") != "effe0001")								//Self not the fatality or effect model?
        {
            vBindhe = getentityvar(vSelf, BINDHE);											//Get any bound effect.
            
            if (getentityproperty(vBindhe, "exists"))										//Bound effect exists?
            { 
                killentity(vBindhe);														//Then kill it.
            }
            
			vSpawn = bind0008("effe0001", "effe0001", 11,      1, 0, 60, 2, 2, openborconstant("ANI_FOLLOW2"), 0, 1);	//Spawn ball explosion.
            draw0006(vSpawn, vSelf);

			vSpawn = bind0008("effe0001", "effe0001", MAPBURN, 0, 0, 0, 0, 1, openborconstant("ANI_FOLLOW14"), 0, 0);   //Spawn fatality model.
            draw0006(vSpawn, vSelf);																					//Match fatality model size to self.
        }
    }
	else																					//Normal. 							
	{	
		vBindhe = getentityvar(vSelf, BINDHE);												//Get any bound effect.
            
        if (getentityproperty(vBindhe, "exists"))											//Bound effect exists?
        { 
            killentity(vBindhe);															//Then kill it.
        }
	}

	/*
	If self was an effect model (body burn flames, shocked, etc.) let's get parent
	back to normal.
	*/
    if (getentityproperty(vParent, "exists"))												//Parent exists?
    {
         vBindhe = getentityvar(vParent, BINDHE);											//Get parent's bound effect variant.
         if (vBindhe == vSelf)																//Was bound effect same as self?
         {
            setentityvar(vParent, BINDHE, NULL());											//Clear parent's bound effect variant.                       
            changeentityproperty(vParent, "map", getentityproperty(vParent, "mapdefault"));	//Clear parent's remap.
         }         
    }

    vars0001(vSelf, 0, 0, 0, 0, 0);															//Clean variables.
}