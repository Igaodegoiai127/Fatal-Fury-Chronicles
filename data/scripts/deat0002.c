#include "data/scripts/vars/colors.h"
#include "data/scripts/com/bind0007.h"
#include "data/scripts/com/bind0008.h"

//Object death, spawns fire entity. Primarily for boats.

void main()
{
	void vSelf = getlocalvar("self");
	void vSpawn; 
	
    vSpawn = bind0007("effe0001", "effe0001", MAPBURN, 1, 0, 50, 3, 0, openborconstant("ANI_FOLLOW12"), 0, 0, 0);       //Spawn fire.
    changeentityproperty(vSpawn, "setlayer", -7);                                                                       //Set fire layer.

    vSpawn = bind0008("effe0001", "effe0001", 11, 1, 0, 40, 0, 0, openborconstant("ANI_FOLLOW2"), 0, 1);                //Spawn ball explosion.
	changeentityproperty(vSpawn, "setlayer", -7);                                                                       //Set ball explosion layer.

	vSpawn = bind0008("scro0001", "Scroll", -1, 0, 0, 40, 0, 0, 0, 0, 0);                                               //Spawn prize.
	tossentity(vSpawn, 3, 0, 0.2);                                                                                      //Toss prize back onto playfield.
	
}


     

