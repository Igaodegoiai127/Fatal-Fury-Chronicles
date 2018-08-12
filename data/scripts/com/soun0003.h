#include "data/scripts/vars/sounds.h"
#include "data/scripts/com/rnd0001.h"
#include "data/scripts/com/soun0001.h"

void soun0003(){
     
    int     iRnd     = rnd0001(0, 13, 0, 0, 0, 0); //Random number.
    void    vSample;                                //Sound sample placeholder.
    
    if      (iRnd==0){   vSample = "voim0001.wav";   }	//FF Rebout KO I.
    else if (iRnd==1){   vSample = "voim0002.wav";   }	//FF Rebout KO II
    else if (iRnd==2){   vSample = "voim0007.wav";   }	//Ninja Spirit PC KO.
    else if (iRnd==3){   vSample = "voim0004.wav";   }	//SOR3 male KO.
    else if (iRnd==4){   vSample = "voim0005.wav";   }	//SOR2 male KO I.
    else if (iRnd==5){   vSample = "voim0006.wav";   }	//SOR2 male KO II.
    else if (iRnd==6){   vSample = "voim0007.wav";   }	//Ninja Spirit PC KO.
    else if (iRnd==7){   vSample = "voim0011.wav";   }	//Punisher male KO I.
    else if (iRnd==8){   vSample = "voim0012.wav";   }	//Punisher male KO II.
    else if (iRnd==9){   vSample = "voim0013.wav";   }	//Punisher male KO III.
    else if (iRnd==10){  vSample = "voim0014.wav";   }	//AVP soldier KO I.
    else if (iRnd==11){  vSample = "voim0015.wav";   }	//AVP soldier KO II.
    else if (iRnd==12){  vSample = "vray0002.wav";   }	//Ray McDougal KO.
    else if (iRnd==13){  vSample = "voim0017.wav";   }	//MK Pain 1.
    
    if (vSample){ soun0001(vSample); }   //Load and play sound sample.
}