#include "data/scripts/dc_d20/main.c"
#include "data/scripts/dc_fidelity/main.c"

void oncreate()
{
	log("\n");
	log("loaded.c");
	log("\t");
	log("- oncreate().");
	log("\n");

	// Global sounds.
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_LIGHT, "data/sounds/custom/golden_axe_whiff_light_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_LIGHT, "data/sounds/custom/rb-whiff-light-0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM, "data/sounds/custom/rb-whiff-med-0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM_BLADE, "data/sounds/custom/samurai_shodown_whiff_light_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM_BLADE, "data/sounds/custom/samurai_shodown_whiff_light_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY, "data/sounds/custom/rb-whiff-heavy-0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY, "data/sounds/custom/rb-whiff-heavy-1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY_BLADE, "data/sounds/custom/samurai_shodown_whiff_heavy_0.wav");	

	// Global voices.
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/avp_soldier_ko_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/avp_soldier_ko_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/fatal_fury_rebout_ko.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/fighters_history_2_ray_ko.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/mortal_kombat_pain_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/ninja_spirit_ko.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/punisher_ko_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/punisher_ko_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/punisher_ko_2.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/sor2_ko_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/sor2_ko_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/sor3_ko_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/unknown_ko.wav");

	// Jump and hop liftoff.
	dc_fidelity_setup("hop_liftoff", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_jump.wav");
	dc_fidelity_setup("jump_liftoff", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_jump.wav");

	// Jump land.
	dc_fidelity_setup("jump_land", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_land.wav");

	// Fall Land.
	dc_fidelity_setup("fall_land", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/unknown_fall_land.wav");

	// Block flash.
	dc_fidelity_setup("block", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/cvs_block.wav");

	//  Hit flash
	dc_fidelity_setup("Flash", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/double_dragon_2_hit_0.wav");
	dc_fidelity_setup("flash_fatal_fury", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_hit.wav");

	// Galford
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/galford/sounds/voice-atk-3.wav");
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/galford/sounds/voice-atk-4.wav");
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/galford/sounds/voice-atk-5.wav");
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/galford/sounds/voice-atk-6.wav");
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/galford/sounds/voice-atk-7.wav");
	
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/galford/sounds/voice-atk-0.wav");
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/galford/sounds/voice-atk-1.wav");
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/galford/sounds/voice-atk-8.wav");

	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/galford/sounds/voice-atk-0.wav");
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/galford/sounds/voice-atk-1.wav");
	dc_fidelity_setup("Galford_Weller", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/galford/sounds/voice-atk-2.wav");	

	//  Ryu
	dc_fidelity_setup("Ryu", "Hadouken", "data/chars/ryu/sounds/voice-hadouken-0c.wav");

	// Terry
	dc_fidelity_setup("Terry_Bogard", "power_wave", "data/chars/terry/sounds/rb-terry-power-wave-0.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/terry/sounds/rb_terry_voice_attack_light_0.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/terry/sounds/rb_terry_voice_attack_light_1.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/terry/sounds/rb_terry_voice_attack_light_2.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/terry/sounds/rb_terry_voice_attack_light_0.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/terry/sounds/rb_terry_voice_attack_light_1.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/terry/sounds/rb_terry_voice_attack_light_2.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/terry/sounds/rb_terry_voice_attack_heavy_0.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/terry/sounds/rb_terry_voice_attack_light_1.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/terry/sounds/rb_terry_voice_attack_heavy_0.wav");
	dc_fidelity_setup("Terry_Bogard", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/terry/sounds/rb_terry_voice_attack_heavy_1.wav");

	dc_instance_dump();
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




