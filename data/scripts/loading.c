#include "data/scripts/dc_d20/main.c"
#include "data/scripts/dc_sound/main.c"

void oncreate()
{
	log("\n");
	log("loaded.c");
	log("\t");
	log("- oncreate().");
	log("\n");

	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_LIGHT_A, "data/chars/galford/sounds/voice-atk-0.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_LIGHT_A, "data/chars/galford/sounds/voice-atk-1.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_LIGHT_A, "data/chars/galford/sounds/voice-atk-8.wav");

	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_MEDIUM_A, "data/chars/galford/sounds/voice-atk-0.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_MEDIUM_A, "data/chars/galford/sounds/voice-atk-1.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_MEDIUM_A, "data/chars/galford/sounds/voice-atk-2.wav");

	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-2.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-3.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-4.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-5.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-6.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_VOICE_HEAVY_A, "data/chars/galford/sounds/voice-atk-7.wav");

	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_WHIFF_LIGHT_A, "data/sounds/custom/golden_axe_whiff_light_0.wav");

	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_WHIFF_MEDIUM_B, "data/sounds/custom/samurai_shodown_whiff_light_0.wav");
	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_WHIFF_MEDIUM_B, "data/sounds/custom/samurai_shodown_whiff_light_1.wav");

	dc_sounds_setup_ip("Galford", DC_SOUND_TYPE_WHIFF_HEAVY_B, "data/sounds/custom/samurai_shodown_whiff_heavy_0-b.wav");
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
		list_models_cached();

		

		dc_sounds_loaded_test("Galford", DC_SOUND_TYPE_WHIFF_LIGHT_A, 0);
	}

}

// Caskey, Damon V.
// 2018-10-12
//
// Experimental function. Just seeing if we
// can get the path of all models that
// are known/loaded.
void list_models_cached()
{
	int i;
	int max;
	char path;
	int loaded;

	max = openborvariant("models_cached");

	log("\n\n");
	log("Models List: ");
	log(max + " found.");
	log("\n");

	for (i = 0; i < max; i++)
	{
		path = getmodelproperty(i, 3);

		//path = dc_string_crop_right(path, "/");

		log("\t");
		log("Index: " + i);
		log(", ");
		log("path: " + path);
		log("\n");
	}

	log("\n\n");
}

// Caskey, Damon V.
// 2010-06-18
//
// Crop the right side of a string (haystack) 
// starting with last occurence of needle.

// Example: 
// - haystack:	"data/scripts/hello.c"
// - needle:	"/"
// - output:	"data/scripts"
char dc_string_crop_right(char haystack, char needle)
{
	char    temp_string;
	int     index;
		
	// Get string length, minus 1
	// to account for zero indexing.
	index = strlength(haystack);
	
	// The strinlast function doesn't work, so we'll just build
	// our own naive search algorithm here. 
	//
	// We create a temporary string from haystack, starting
	// at the far right character. We then use stringinfirst 
	// to see if our needle is in the temp_string, and if it
	// is we now have an index to use for strleft. 
	//
	// If the result is invalid (-1), then we build the
	// tempstring from haystack, now one character back, and
	// continue until our strinfirst gets a good result.
	do
	{
		index--;

		// Get the right end of haystack, starting
		// from index.
		temp_string	= strright(haystack, index);
		
	} while (strinfirst(temp_string, needle) == -1);

	// Now that we have our index pointing to the last
	// occurence of needle in haystack, we can use strleft 
	// to return the preceeding characters.
	return strleft(haystack, index);
}


