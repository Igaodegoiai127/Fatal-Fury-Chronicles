#include "data/scripts/dc_sound/config.h"

// User config. These functions allow a module author to 
// temporarily override the default configuration as 
// needed. We use localvars, so any override is local 
// to the event that runs it and reset when the event
// is destroyed.

// Unless otherwise noted, any setting that does not 
// have a user value will fall back to its default 
// as defined in config.h

// Chance determines likelihood of sound function actually
// playing anything.
//
// 0.0 = Never
// 0.5 = 50%
// 1.0 = Always.
void dc_sound_set_chance(float value)
{
	setlocalvar(DC_SOUND_VAR_KEY_SOUND_CHANCE, value);
}

void dc_sound_get_chance()
{
	void result = getlocalvar(DC_SOUND_VAR_KEY_SOUND_CHANCE);

	if (!result)
	{
		result = DC_SOUND_DEFAULT_CHANCE;
	}

	return result;
}

// Entity is the target entity when searching for
// a model to play sounds, an on screen location
// for stereo effects, and anything else that 
// requires a target entity reference. Defaults
// to the calling entity.
void dc_sound_set_entity(void value)
{
	setlocalvar(DC_SOUND_VAR_KEY_SOUND_ENTITY, value);
}

void dc_sound_get_entity()
{
	void result = getlocalvar(DC_SOUND_VAR_KEY_SOUND_ENTITY);

	if (!result)
	{
		result = getlocalvar("self");
	}

	return result;
}

// Element is the target item in sound indexes array. 
// Defaults to random, which causes a random element
// to be selected from all indexes available for
// a selected sound type.
void dc_sound_set_sound_element(int value)
{
	setlocalvar(DC_SOUND_VAR_KEY_SOUND_SPEED, value);
}

int dc_sound_get_sound_element()
{
	int result = getlocalvar(DC_SOUND_VAR_KEY_SOUND_ELEMENT);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_SOUND_INDEX_RANDOM;
	}

	return result;
}

// Sound looping on playback.
void dc_sound_set_loop(int value)
{
	setlocalvar(DC_SOUND_VAR_KEY_SOUND_LOOP, value);
}

int dc_sound_get_loop()
{
	int result = getlocalvar(DC_SOUND_VAR_KEY_SOUND_LOOP);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_SOUND_DEFAULT_LOOP;
	}

	return result;
}

// Priority of sound when played on same channel.
void dc_sound_set_priority(int value)
{
	setlocalvar(DC_SOUND_VAR_KEY_SOUND_PRIORITY, value);
}

int dc_sound_get_priority()
{
	int result = getlocalvar(DC_SOUND_VAR_KEY_SOUND_PRIORITY);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_SOUND_DEFAULT_PRIORITY;
	}

	return result;
}

// Speed is the playback speed for sounds before any auto
// adjustments are made. Generally, slower playback speeds
// result in a lower pitch. As an example of this effect, 
// OpenBOR’s native sound effect system plays hit impact 
// sounds at lower speeds as greater damage is inflicted. 
void dc_sound_set_speed(int value)
{
	setlocalvar(DC_SOUND_VAR_KEY_SOUND_SPEED, value);
}

// Get specified speed, or default if not available.
int dc_sound_get_speed()
{
	int result = getlocalvar(DC_SOUND_VAR_KEY_SOUND_SPEED);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_SOUND_DEFAULT_SPEED;
	}

	return result;
}

// Volume is the intitial left and right channel 
// playback volume before any auto adjustments
// are made. 
void dc_sound_set_volume_left(int value)
{
	setlocalvar(DC_SOUND_VAR_KEY_SOUND_VOLUME_LEFT, value);
}

int dc_sound_get_volume_left()
{
	int result = getlocalvar(DC_SOUND_VAR_KEY_SOUND_VOLUME_LEFT);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_SOUND_DEFAULT_VOLUME_LEFT;
	}

	return result;
}

void dc_sound_set_volume_right(int value)
{
	setlocalvar(DC_SOUND_VAR_KEY_SOUND_VOLUME_RIGHT, value);
}

int dc_sound_get_volume_right()
{
	int result = getlocalvar(DC_SOUND_VAR_KEY_SOUND_VOLUME_RIGHT);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_SOUND_DEFAULT_VOLUME_RIGHT;
	}

	return result;
}

