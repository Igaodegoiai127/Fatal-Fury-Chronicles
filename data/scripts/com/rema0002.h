#include "data/scripts/dc_d20/main.c"  
#include "data/scripts/com/targ0001.h"

void rema0002(void vTar, int A, int B, int C, int D, int E){
     
     /*
     rema0002
     Damon Vaughn Caskey
     01262009
     Set's target map randomly, avoiding hmap range.
     */
     
	
     void vSelf   = getlocalvar("self");                        //Caller.
     void vTarget = targ0001(vTar, vSelf);                      //Target.
     int iMapCount = getentityproperty(vSelf, "mapcount");      //Number of maps loaded.  
     int iHMapU    = getentityproperty(vSelf, "hmapu");         //Upper range of hmaps. 
	 int selection;

	 setlocalvar(DC_D20_KEY_LOWER, iHMapU);
	 setlocalvar(DC_D20_KEY_UPPER, iMapCount);

	 selection = dc_d20_random_int();
	         
     if (selection <= iHMapU)
	 { 
		 selection = 0; 
	 }                           //If random number matches upper hmap, use map 0 (default colors for model).

     changeentityproperty(vTarget, "map", selection);                //Apply map choice.
     
}
