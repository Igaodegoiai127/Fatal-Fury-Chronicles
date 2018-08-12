//*****Entity vars*****
int ENTID       = 0;									//ID number given during spawn script.
int VITNAME     = 1;									//Full Name.
int VITRACE     = 2;									//Race (Human, Elf, Dwarf, etc.).
int VITGEND     = 3;									//Gender (0 = Male, 1 = female);
int VITHEIG     = 4;									//Height (cm).
int VITWEIG     = 5;									//Weight (kg).
int VITDOB      = 6;									//Date of birth.
int VITAGE      = 7;									//Age.
int VITPOB      = 8;									//Place of birth.
int VITALIG     = 9;									//Alignment.
int VITSTR      = 10;									//Strength.
int VITDEX      = 11;									//Dexterity.
int VITCON      = 12;									//Constitution.
int VITINT      = 13;									//Intellegence.
int VITWIS      = 14;									//Wisdom.
int VITCHR      = 15;									//Charisma.
int VITCLAS     = 16;									//Class (Barbarian, Cleric, Fighter, etc.).
int VITEXP      = 17;									//Experience total.
int STUNV       = 18;									//Stun value built up by incoming attacks.
int STUNT       = 19;									//Gametime threshold to reduce/remove stun value.
int BIND        = 20;									//Primary bind for grappling moves.
int NEXTANI     = 21;									//Animation to be activated in future by another event or script.
int NEXTANI2    = 22;									//Animation to be activated in future by another event or script.
int NEXTANI3    = 23;									//Animation to be activated in future by another event or script.
int NEXTANI4    = 24;									//Animation to be activated in future by another event or script.
int NEXTANI5    = 25;									//Animation to be activated in future by another event or script.
int NEXTSPW     = 26;									//Model to be spawned in future by another event or script.
int NEXTSPA     = 27;									//Alias of NEXTSPW.
int NEXTSPM     = 28;									//Map of NEXTSPW.
int NEXTSPB     = 29;									//Blend setting of NEXTSPW.
int NEXTSPX     = 30;									//X location (or adjustment) of NEXTSPW.
int NEXTSPY     = 31;									//Y location (or adjustment) of NEXTSPW.
int NEXTSPZ     = 32;									//Z location (or adjustment) of NEXTSPW.
int NEXTSPD     = 33;									//Direction setting of NEXTSPW.
int NEXTSPF     = 34;									//Animation flag for binding NEXTSPW.   
int OGMAP       = 35;									//Orginal map. This is the remap entity starts with so it may be restored later if needed.
int SPAWN       = 36;									//Entity var slot used to store new spawns.
int ADSCALEX    = 37;									//draw scale X adjustment.
int ADSCALEY    = 38;									//draw scale Y adjustment.
int ADFLIPX     = 39;									//draw flip X setting.
int ADFLIPY     = 40;									//draw flip Y setting.
int ADSHIFTX    = 41;									//draw shift X setting.
int ADBLEND     = 42;									//draw blend setting.
int ADREMAP     = 43;									//draw remap setting.
int ADFILL      = 44;									//draw fill setting.
int ADROTATE    = 45;									//draw static rotate setting.
int ADAROTAT    = 46;									//draw auto rotation setting.
int ADSCALER    = 47;									//draw, last scale ratio applied to sprite.
int ADSKIP      = 48;									//draw toggle flag.
int SHFLAG      = 49;									//Shadow toggle and mode flag.
int SHMODEL     = 50;									//Shadow trail model.
int SHALIAS     = 51;									//Shadow model alias.
int SHDELAY     = 52;									//Shadow, delay between individual shadow entity spawns.
int SHETIME     = 53;									//Shadow, elapsed game time next shadow trail entity will be spawned.
int SHREMAP     = 54;									//Shadow, remap applied to shadow trail.
int SHBLEND     = 55;									//Shadow, blend mode applied to shadow trail.
int TOSSX       = 56;									//X velocity for toss effect on attack.
int TOSSY       = 57;									//Y velocity for toss effect on attack.
int TOSSZ       = 58;									//Z velocity for toss effect on attack.
int DTOSSX      = 59;									//X velocity for toss effect.
int DTOSSY      = 60;									//Y velocity for toss effect.
int DTOSSZ      = 61;									//Z velocity for toss effect.
int WARPX       = 62;									//X location adjust for self to attacker when hit.
int WARPY       = 63;									//Y location adjust for self to attacker when hit.
int WARPZ       = 64;									//Z location adjust for self to attacker when hit.
int WARPT       = 65;									//Condition for location adjust self to attacker when hit (0/NULL = Any hit, 1 = Pain or fall, 2 = Fall only).  
int HITDMG      = 66;									//Extra damage to apply to target during didhitscript.
int HITFIN      = 67;									//Extra damage lethal flag (1 = damage cannot reduce HP to < 1).
int HITTYP      = 68;									//Extra damage attack type.
int HITDRP      = 69;									//Extra damage drop power.
int HITNOR      = 70;									//Extra damage no reset on hit flag.
int HITWRX      = 71;									//Extra damage X location force.
int HITWRY      = 72;									//Extra damage Y location force.
int HITWRZ      = 73;									//Extra damage Z location force.
int HITWRT      = 74;									//Extra damage location force condition (0 = always, 1 = pain/knockdown, 2 = knockdown).
int HITLVL      = 75;									//Force hit level flag (0 = Normal, 1 = Middle, 2 = Low, 3 = High).
int HITFLS      = 76;									//Extra damage hitflash.
int BINDHE      = 77;									//Bound hit effect entity.
int BINDE       = 78;									//Bound special effect.
int KEY1SP      = 79;                                   //Last time special key was pressed.
int KEY1AT      = 80;                                   //Last time attack key was pressed.
int STATUS      = 81;                                   //Special states (power up, etc.).

