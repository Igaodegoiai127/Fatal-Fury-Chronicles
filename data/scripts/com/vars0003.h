#include "data/scripts/vars/entity.h"

void vars0003(int iIndex, void vValue){

     //Sets passed parameter to caller's entity var.
     
     void vSelf = getlocalvar("self");          //Caller.
     setentityvar(vSelf, iIndex, vValue);       //Set entityvar adjustment.
    
}
