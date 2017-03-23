#include	"data/scripts/vars/entity.h"
#include	"data/scripts/vars/anims.h"
#include	"data/scripts/com/ani0009.h"
#include	"data/scripts/com/spaw0006.h"

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
                
        fX     = getentityproperty(vSelf, "x") - openborvariant("xpos");    //Item X location.
        fY     = getentityproperty(vSelf, "a");                             //Item A location.
        fZ     = getentityproperty(vSelf, "z");                             //Item Z location.       
        
		vSpawn = spaw0006("musi0001", vAlias, fX, fY, fZ, 0, 0);			//Spawn entity.

		changeplayerproperty(iPlIndex, "score", iScore - 1);				//One point was given by item to activate score sound (health sound defaults otherwise). Take point back.
    }
	else if (vModel == "scro0001")											//Power up scroll.
	{
        if (getentityvar(vDefender, STATUS) != 1)
        {            
		    ani0009(vDefender, POWUP, 1);									//Set power up animation.
        }
	}
}
