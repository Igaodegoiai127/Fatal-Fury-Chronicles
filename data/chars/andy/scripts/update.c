#include "data/scripts/vars/entity.h"
#include "data/scripts/dc_afterimage/main.c"
#include "data/scripts/com/trai0003.h"

//Andy Bogard's update.

void main()
{
    void vSelf      = getlocalvar("self");
    int  iAni       = getentityproperty(vSelf, "animationid");
    int  iStatus    = getentityvar(vSelf, STATUS);

    if (iStatus == 1)
    {
        trai0002(vSelf); //Shadow trails.
        trai0003(); //After hits.
        return;
    }

    if (iAni == openborconstant("ANI_FREESPECIAL12")        //Zaneiken?
        || iAni == openborconstant("ANI_FREESPECIAL14")     //Genei Shiranui?
        || iAni == openborconstant("ANI_FREESPECIAL9")      //Zan'ei Ryuusei Ken?
        || iAni == openborconstant("ANI_FOLLOW8"))          //Zan'ei Ryuusei Ken SDM?
    {
        if (getentityproperty(vSelf, "xdir"))               //Moving horizontally?
        {
            trai0002(vSelf);                                     //Run shadow function.
        }
    }
}

