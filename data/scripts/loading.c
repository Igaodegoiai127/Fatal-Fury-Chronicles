#include "data/scripts/dc_d20/main.c"
#include "data/scripts/dc_sound/main.c"

void oncreate()
{
	log("\n");
	log("loaded.c");
	log("\t");
	log("- oncreate().");
	log("\n");

	
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-2.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-3.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-4.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-5.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-6.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-7.wav");

	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_LIGHT_A, "data/chars/galford/sounds/voice-atk-0.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_LIGHT_A, "data/chars/galford/sounds/voice-atk-1.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_LIGHT_A, "data/chars/galford/sounds/voice-atk-8.wav");

	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_MEDIUM_A, "data/chars/galford/sounds/voice-atk-0.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_MEDIUM_A, "data/chars/galford/sounds/voice-atk-1.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_VOICE_MEDIUM_A, "data/chars/galford/sounds/voice-atk-2.wav");
	

	dc_sounds_setup("Galford", DC_SOUND_TYPE_WHIFF_HEAVY_B, "data/sounds/custom/samurai_shodown_whiff_heavy_0.wav");

	dc_sounds_setup("Galford", DC_SOUND_TYPE_WHIFF_LIGHT_A, "data/sounds/custom/golden_axe_whiff_light_0.wav");

	dc_sounds_setup("Galford", DC_SOUND_TYPE_WHIFF_MEDIUM_B, "data/sounds/custom/samurai_shodown_whiff_light_0.wav");
	dc_sounds_setup("Galford", DC_SOUND_TYPE_WHIFF_MEDIUM_B, "data/sounds/custom/samurai_shodown_whiff_light_1.wav");

}

void ondestroy()
{
	log("\n");
	log("loaded.c");
	log("\t");
	log("- ondestroy().");
	log("\n");
}

void main()
{
	void	s;
	void	value	=	getlocalvar("value");
	void	max		=	getlocalvar("max");
	if(max==1){
		return;
	}else{}

	void percent=value*100/max;
	percent%=++percent;

	void dot=percent%3;
	if(dot==0)
		s=".";
	else if(dot==1)
		s="..";
	else
		s="...";

	drawstring(194,60,2,"WARNING");
	drawstring(36,100,2,"THIS GAME IS NOT PRODUCED UNDER LICENCE OF");
	drawstring(162,140,2,"CAPCOM AND SNK");
	drawstring(143,242,0,"Loading Models..."+percent);
	drawstring(259,242,0,"% Complete"+s);
	drawbox(0,260,480,2,11,rgbcolor(0,122,133),0);
	drawbox(0,260,percent*480*0.01,2,15,rgbcolor(0,233,233),0);

	if (value == max)
	{
	}

}




