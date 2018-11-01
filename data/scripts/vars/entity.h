#ifndef ENTITY_DEF

#define ENTITY_DEF 1

//*****Entity vars*****
#define ENTID        0									//ID number given during spawn script.
#define VITNAME      1									//Full Name.
#define VITRACE      2									//Race (Human, Elf, Dwarf, etc.).
#define VITGEND      3									//Gender (0  Male, 1  female)
#define VITHEIG      4									//Height (cm).
#define VITWEIG      5									//Weight (kg).
#define VITDOB       6									//Date of birth.
#define VITAGE       7									//Age.
#define VITPOB       8									//Place of birth.
#define VITALIG      9									//Alignment.
#define VITSTR       10									//Strength.
#define VITDEX       11									//Dexterity.
#define VITCON       12									//Constitution.
#define VITINT		 13									//#defineellegence.
#define VITWIS       14									//Wisdom.
#define VITCHR       15									//Charisma.
#define VITCLAS      16									//Class (Barbarian, Cleric, Fighter, etc.).
#define VITEXP       17									//Experience total.
#define STUNV        18									//Stun value built up by incoming attacks.
#define STUNT        19									//Gametime threshold to reduce/remove stun value.
#define BIND         20									//Primary bind for grappling moves.
#define NEXTANI      21									//Animation to be activated in future by another event or script.
#define NEXTANI2     22									//Animation to be activated in future by another event or script.
#define NEXTANI3     23									//Animation to be activated in future by another event or script.
#define NEXTANI4     24									//Animation to be activated in future by another event or script.
#define NEXTANI5     25									//Animation to be activated in future by another event or script.
#define NEXTSPW      26									//Model to be spawned in future by another event or script.
#define NEXTSPA      27									//Alias of NEXTSPW.
#define NEXTSPM      28									//Map of NEXTSPW.
#define NEXTSPB      29									//Blend setting of NEXTSPW.
#define NEXTSPX      30									//X location (or adjustment) of NEXTSPW.
#define NEXTSPY      31									//Y location (or adjustment) of NEXTSPW.
#define NEXTSPZ      32									//Z location (or adjustment) of NEXTSPW.
#define NEXTSPD      33									//Direction setting of NEXTSPW.
#define NEXTSPF      34									//Animation flag for binding NEXTSPW.
#define OGMAP        35									//Orginal map. This is the remap entity starts with so it may be restored later if needed.
#define SPAWN        36									//Entity var slot used to store new spawns.
#define ADSCALEX     37									//draw scale X adjustment.
#define ADSCALEY     38									//draw scale Y adjustment.
#define ADFLIPX      39									//draw flip X setting.
#define ADFLIPY      40									//draw flip Y setting.
#define ADSHIFTX     41									//draw shift X setting.
#define ADBLEND      42									//draw blend setting.
#define ADREMAP      43									//draw remap setting.
#define ADFILL       44									//draw fill setting.
#define ADROTATE     45									//draw static rotate setting.
#define ADAROTAT     46									//draw auto rotation setting.
#define ADSCALER     47									//draw, last scale ratio applied to sprite.
#define ADSKIP       48									//draw toggle flag.
#define SHFLAG       49									//Shadow toggle and mode flag.
#define SHMODEL      50									//Shadow trail model.
#define SHALIAS      51									//Shadow model alias.
#define SHDELAY      52									//Shadow, delay between individual shadow entity spawns.
#define SHETIME      53									//Shadow, elapsed game time next shadow trail entity will be spawned.
#define SHREMAP      54									//Shadow, remap applied to shadow trail.
#define SHBLEND      55									//Shadow, blend mode applied to shadow trail.
#define TOSSX        56									//X velocity for toss effect on attack.
#define TOSSY        57									//Y velocity for toss effect on attack.
#define TOSSZ        58									//Z velocity for toss effect on attack.
#define DTOSSX       59									//X velocity for toss effect.
#define DTOSSY       60									//Y velocity for toss effect.
#define DTOSSZ       61									//Z velocity for toss effect.
#define WARPX        62									//X location adjust for self to attacker when hit.
#define WARPY        63									//Y location adjust for self to attacker when hit.
#define WARPZ        64									//Z location adjust for self to attacker when hit.
#define WARPT        65									//Condition for location adjust self to attacker when hit (0/NULL  Any hit, 1  Pain or fall, 2  Fall only).
#define HITDMG       66									//Extra damage to apply to target during didhitscript.
#define HITFIN       67									//Extra damage lethal flag (1  damage cannot reduce HP to < 1).
#define HITTYP       68									//Extra damage attack type.
#define HITDRP       69									//Extra damage drop power.
#define HITNOR       70									//Extra damage no reset on hit flag.
#define HITWRX       71									//Extra damage X location force.
#define HITWRY       72									//Extra damage Y location force.
#define HITWRZ       73									//Extra damage Z location force.
#define HITWRT       74									//Extra damage location force condition (0  always, 1  pain/knockdown, 2  knockdown).
#define HITLVL       75									//Force hit level flag (0  Normal, 1  Middle, 2  Low, 3  High).
#define HITFLS       76									//Extra damage hitflash.
#define BINDHE       77									//Bound hit effect entity.
#define BINDE        78									//Bound special effect.
#define STATUS       81                                   //Special states (power up, etc.).

#endif // ENTITY_DEF
