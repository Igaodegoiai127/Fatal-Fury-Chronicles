//playsample(id, 0, 120, 120, 100, 0);

#include "data/scripts/vars/sounds.h"        

void soun0001(void vSample)
{
    /*
    soun0001
    09112009
    Damon Vaughn Caskey
    Sound effect wrapper. Plays desired sound with location based stereo. Made to be
	simple as possible since it will be called pretty much any time we want a sound.
    */
    
    void  vSelf     = getlocalvar("self");    
    float fSourceX  = getentityproperty(vSelf, "x") - openborvariant("xpos");
    int   iLVol     = 200;
    int   iRVol     = 200;
	int   iSample;

	iSample = loadsample("data/sounds/" + vSample);

    fSourceX /= (openborvariant("hResolution") * 0.5);
    
    iLVol -= (iLVol / 2) * fSourceX;
    iRVol = (iRVol / 2) * fSourceX;        
    
    playsample(iSample, 0, iLVol, iRVol, 100, 0);
}


