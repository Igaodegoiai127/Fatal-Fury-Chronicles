//Debug functions.

void debug(void vSelf){

    
    float   fRunspeed       = getentityproperty(vSelf,  "running",   "speed");
    float   fRunjumpY       = getentityproperty(vSelf,  "running",   "jumpY");
    float   fRunjumpX       = getentityproperty(vSelf,  "running",   "jumpX");
    float   fRunland        = getentityproperty(vSelf,  "running",   "land");
    float   fRunmoveZ       = getentityproperty(vSelf,  "running",   "moveZ");    
    float   fFactor         = getentityproperty(vSelf,  "defense",   openborconstant("ATK_NORMAL"), "factor");
    float   fBlockpower     = getentityproperty(vSelf,  "defense",   openborconstant("ATK_NORMAL"), "blockpower");
    float   fBlockratio     = getentityproperty(vSelf,  "defense",   openborconstant("ATK_NORMAL"), "blockratio");
    float   fBlockthreshold = getentityproperty(vSelf,  "defense",   openborconstant("ATK_NORMAL"), "blockthreshold");
    float   fBlocktype      = getentityproperty(vSelf,  "defense",   openborconstant("ATK_NORMAL"), "blocktype");
    float   fKnockdown      = getentityproperty(vSelf,  "defense",   openborconstant("ATK_NORMAL"), "knockdown");
    float   fPain           = getentityproperty(vSelf,  "defense",   openborconstant("ATK_NORMAL"), "pain");
    int     iEDelay         = getentityproperty(vSelf,  "edelay",    "delay");
    int     iEDMin          = getentityproperty(vSelf,  "edelay",    "min");
    int     iEDMax          = getentityproperty(vSelf,  "edelay",    "max");
    int     iDotTime        = getentityproperty(vSelf,  "dot",       2,  "time");
    int     iDotMode        = getentityproperty(vSelf,  "dot",       2,  "mode");
    int     iDotForce       = getentityproperty(vSelf,  "dot",       2,  "force");
    int     iDotRate        = getentityproperty(vSelf,  "dot",       2,  "rate");
    int     iDotType        = getentityproperty(vSelf,  "dot",       2,  "type");
    void    iDotOwne        = getentityproperty(vSelf,  "dot",       2,  "owner");
    int     iTime           = openborvariant("elapsed_time");
    int     iX              = getentityproperty(vSelf,  "x") - openborvariant("xpos");
    int     iY              = getentityproperty(vSelf,  "a");
    int     iZ              = getentityproperty(vSelf,  "z");

    //changeentityproperty(vSelf, "running", 3.5, 4.5, 2.5, 0, 0);
    //changeentityproperty(vSelf, "defense", openborconstant("ATK_NORMAL"), 1.5, 2, 0.5, 20, 1, 0.5, 10);
    //changeentityproperty(vSelf, "dot", iTime + 10000, 1, 5, 200, openborconstant("ATK_NORMAL"), vSelf); 

    //settextobj(0, 100, 20, 1, -1, "X: " + iX);
    //settextobj(1, 100, 30, 1, -1, "Y: " + iY);
    //settextobj(2, 100, 40, 1, -1, "Z: " + iZ);

    //settextobj(0, 100, 20, 1, -1, "Speed: " + fRunspeed);
    //settextobj(1, 100, 30, 1, -1, "JumpX: " + fRunjumpY);
    //settextobj(2, 100, 40, 1, -1, "JumpY: " + fRunjumpX);
    //settextobj(3, 100, 50, 1, -1, "Land : " + fRunland);
    //settextobj(4, 100, 60, 1, -1, "MoveZ: " + fRunmoveZ);

    //settextobj(0, 100, 20, 1, -1, "Factor: "            + fFactor);
    //settextobj(1, 100, 30, 1, -1, "Blockpower: "        + fBlockpower);
    //settextobj(2, 100, 40, 1, -1, "Blockratio: "        + fBlockratio);
    //settextobj(3, 100, 50, 1, -1, "Blockthreshold : "   + fBlockthreshold);
    //settextobj(4, 100, 60, 1, -1, "Blocktype: "         + fBlocktype);
    //settextobj(5, 100, 70, 1, -1, "Knockdown : "        + fKnockdown);
    //settextobj(6, 100, 80, 1, -1, "Pain: "              + fPain);

    //settextobj(0, 100, 20, 1, -1, "Delay: "             + iEDelay);
    //settextobj(1, 100, 30, 1, -1, "D. Min: "            + iEDMin);
    //settextobj(2, 100, 40, 1, -1, "D. Max: "            + iEDMax);

    //settextobj(0, 100, 10, 1, -1, "Elp Time: "            + iTime);   
    //settextobj(1, 100, 20, 1, -1, "Dot Time: "            + iDotTime);
    //settextobj(2, 100, 30, 1, -1, "Dot Mode: "            + iDotMode);
    //settextobj(3, 100, 40, 1, -1, "Dot Forc: "            + iDotForce);
    //settextobj(4, 100, 50, 1, -1, "Dot Rate: "            + iDotRate);
    //settextobj(5, 100, 60, 1, -1, "Dot Type: "            + iDotType);
    //settextobj(6, 100, 70, 1, -1, "Dot Owne: "            + iDotOwne);
    //settextobj(7, 100, 80, 1, -1, "Self____: "            + vSelf);    
}