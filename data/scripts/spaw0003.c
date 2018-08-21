/*Dust spawn.

Manipulate default "dust" entity to produce falling visual and sound effects.

iType:	
     0 = Jump.
     1 = Land.
     2 = Sudden start.
     3 = Sudden stop.
     4 = Skid.
     5 = Impact.
     6 = Heavy Impact.
     7 = Jump (no sound in normal enviroment).
     8 = Fall.
*/

#include "data/scripts/vars/entity.h"
#include "data/scripts/vars/sounds.h"
#include "data/scripts/dc_draw/main.c"
#include "data/scripts/com/soun0001.h"

void main(){

    void    vSelf   = getlocalvar("self");    
    int     iZ      = getentityproperty(vSelf, "z");    
    int     iCount;
    int     iMaxVar = openborvariant("maxentityvars");
    int     iMap;    
	int	    iBlend;   

    for (iCount = 0; iCount <= iMaxVar; iCount++)
    {
         setentityvar(vSelf, iCount, NULL());
    }
       
    changeentityproperty(vSelf, "autokill", 1);                                     //Make sure autokill property is on.
    
    if (iZ < openborvariant("PLAYER_MIN_Z") - 3)                                //Water fatality?  
    {
        soun0001(SNDWAT1);
        changeentityproperty(vSelf, "setlayer",	-9);
        changeentityproperty(vSelf, "map", 1); 
        changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW1"));
    }
    else if (iZ > openborvariant("PLAYER_MAX_Z"))                               //Into the screen fatality?  
    {
        killentity(vSelf);
    }
    else
    {
        soun0001(SNDFALL);
        setentityvar(vSelf, ADBLEND, 1);
        dc_draw_z_position_autoscale(vSelf);
    }        
        
}


