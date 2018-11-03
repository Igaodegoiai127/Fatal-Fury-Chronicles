#include "data/scripts/vars/entity.h"
#include "data/scripts/vars/anims.h"

void main(){
    
    //Item aquisition script.
    
    void  vSelf     = getlocalvar("self");                                  //Calling entity. 
    void  vDefender = getlocalvar("damagetaker");                           //Defending entity.
    void  vModel    = getentityproperty(vSelf, "model");                    //Item model
    void  vAlias    = getentityproperty(vSelf, "name");                     //Item Alias.
    int   iPlIndex  = getlocalvar("player");                                //Player index.
    int   iScore    = getplayerproperty(iPlIndex, "score");                 //Current score.    
    void  vSpawn;                                                           //Spawn placeholder.
    float fX;                                                               //Spawn X location.
    float fY;                                                               //Spawn Y location.
    float fZ;                                                               //Spawn Z location.
    
    if (vModel == "musi0001")												//Music switch item.
	{         
        playmusic("data/music/" + vAlias + ".bor", 1);                      //Change the music track.
        
        //Spawn next selection item.
        if      (vAlias == "Estrada"){ vAlias = "Sound_B";  }               //Sound Beach Alt 1.
        else if (vAlias == "Sound_B"){ vAlias = "Estrada";  }               //Sound Beach default.        
        
        changeentityproperty(vSelf, "name", vAlias);

        /*
        fX     = getentityproperty(vSelf, "x") - openborvariant("xpos");    //Item X location.
        fY     = getentityproperty(vSelf, "a");                             //Item A location.
        fZ     = 210;                                                       //Quick and dirty fix. Get Z location is not working on items. 
                    
        clearspawnentry();                                                  //Clear current spawn entry.
        setspawnentry("name",   "musi0001");                                //Aquire spawn entity by name.
        setspawnentry("alias",  vAlias);                                    //Set alias.
        setspawnentry("coords", fX, fZ, fY);                                //Spawn location.
        vSpawn = spawn();                                                   //Spawn entity.
        clearspawnentry();                                                  //Clear current spawn entry.
        */

    }
	else if (vModel == "scro0001")											//Power up scroll.
	{
        if (getentityvar(vDefender, STATUS) != 1)
        {
			if (getentityproperty(vDefender, "animvalid", POWUP))
			{
				changeentityproperty(vDefender, "animation", POWUP);
			}
        }
	}
}
