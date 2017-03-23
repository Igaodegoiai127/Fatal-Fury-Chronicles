#include "data/scripts/vars/entity.h"
#include "data/scripts/com/trai0002.h"
#include "data/scripts/com/trai0003.h"
#include "data/scripts/com/debu0002.h"

//Andy Bogard's update.

void main()
{
	void vSelf;      
    int  iAni;       
    int  iStatus; 	
	
	debu0002(vSelf);

    if (iStatus == 1)											//Power up?										
    {
        trai0002();												//Shadow trails.
        trai0003();												//After hits.
        return;
    }
	else if (iAni == openborconstant("ANI_FREESPECIAL12")		//Zaneiken?
        || iAni == openborconstant("ANI_FREESPECIAL14")			//Genei Shiranui?
        || iAni == openborconstant("ANI_FREESPECIAL9")			//Zan'ei Ryuusei Ken?
        || iAni == openborconstant("ANI_FOLLOW8"))				//Zan'ei Ryuusei Ken SDM?
    {
        if (getentityproperty(vSelf, "xdir"))					//Moving horizontally? 
        {            
            trai0002();											//Shadow trails.
        }
    }    
}

