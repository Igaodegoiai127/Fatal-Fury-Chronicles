//flash spawn.

#include "data/scripts/com/draw0001.h"
#include "data/scripts/com/soun0001.h"	        //Sound functions.
#include "data/scripts/com/rnd0001.h"

void main(){

    void    vSelf   = getlocalvar("self");                                      //Caller.
    int     iMaxVar = openborvariant("maxentityvars");                          //Maximum vars in use.
    int     iList   = getindexedvar(0);                                         //Entity counter.
    int     iCount;                                                             //Loop counter.

    if (!iList)
    {    
        iList = 0;  //Count not initalized, set to 0.
    }
    else
    {
        iList += 1; //Count initalized, increment by 1.
    }
    
    setentityvar(vSelf, ENTID, iList);                                          //Set artificial handle.
    setindexedvar(0, iList);                                                    //Set entity counter.

    for (iCount = 0; iCount <= iMaxVar; iCount++)
    {
         setentityvar(vSelf, iCount, NULL());
    }
    
    setentityvar(vSelf, ADSCALEX, 0.5);											//Set half X size.
    setentityvar(vSelf, ADSCALEY, 0.5);											//Set half Y size.
    setentityvar(vSelf, ADBLEND, 1);                                            //Set alpha transparency.
    setentityvar(vSelf, ADROTATE, rnd0001(0, 359,0,0,0,0));                    //Set rotation (rando 0-359).
    dc_draw_z_position_autoscale(vSelf);                                                            //Apply draw settings.    
    
	soun0001(SNDHIT1);
}