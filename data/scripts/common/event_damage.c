#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_fidelity/main.c"



void main()
{
	void ent = getlocalvar("self");

	common_take_damage();

	// Release any grappled entities.
	dc_elmers_set_target(ent);
	dc_elmers_disrupt_grapple();
}

#define DC_DAMAGE_HP_HIGH 0.75
#define DC_DAMAGE_HP_KO 0.0
#define DC_DAMAGE_HP_LOW 0.25
#define DC_DAMAGE_HP_MAX 1.0

#define DC_DAMAGE_TAKEDAMAGE_BURN_ADDITION			0 
#define DC_DAMAGE_TAKEDAMAGE_BURN_INITIAL			1
#define DC_DAMAGE_TAKEDAMAGE_HP_HIGH				2
#define DC_DAMAGE_TAKEDAMAGE_HP_MAX					4
#define DC_DAMAGE_TAKEDAMAGE_HP_KO					8
#define DC_DAMAGE_TAKEDAMAGE_HP_LOW					16
#define DC_DAMAGE_TAKEDAMAGE_KNOCKDOWN_ADDITION		32
#define DC_DAMAGE_TAKEDAMAGE_KNOCKDOWN_INITIAL		64
#define DC_DAMAGE_TAKEDAMAGE_LANDING				128	
#define DC_DAMAGE_TAKEDAMAGE_SHOCK_ADDITION			256
#define DC_DAMAGE_TAKEDAMAGE_SHOCK_INITIAL			512

// Caskey, Damon V.
// 2019-10-02
// 
// Compute result of damage taking.
// Knock us down, burn us, kill us, etc.
// That way we can decide what sounds to 
// play and possibly take other actions too.
void common_take_damage_result(void ent)
{
	int animation_id;
	int animation_frame;
	int landframe;
	int drop;
	int attack_type;
	float hp;
	float hp_max;
	float hp_ratio;
	int result = 0;


	// HP result. We get max and current HP, find the percentage
	// of current vs. high, and then set flag based on
	// preset thresholds.
	hp = 0.0 + get_entity_property(ent, "hp");
	hp_max = 0.0 + getentityproperty(ent, "maxhealth");

	hp_ratio = hp / hp_max;

	if (hp_ratio <= 0)
	{
		result += DC_DAMAGE_TAKEDAMAGE_HP_KO;
	}
	else if (hp_ratio <= DC_DAMAGE_HP_LOW)
	{
		result += DC_DAMAGE_TAKEDAMAGE_HP_LOW;
	}
	else if (hp_ratio < DC_DAMAGE_HP_MAX)
	{
		result += DC_DAMAGE_TAKEDAMAGE_HP_HIGH;
	}
	else
	{
		result += DC_DAMAGE_TAKEDAMAGE_HP_MAX;
	}

	// Is this landing damage?
	animation_frame = get_entity_property(ent, "animation_frame");
	landframe = getentityproperty(ent, "landframe", animation_id);

	if (animation_frame == landframe)
	{
		result += DC_DAMAGE_TAKEDAMAGE_LANDING;
	}

	// Knockdown hit?
	drop = get_entity_property(ent, "drop");



	// If the attack will KO us, we go right to
	// KO sound. Otherwise things get more complex.
	if (hp > 0)
	{
		animation_id = get_entity_property(ent, "animation_id");
		animation_frame = get_entity_property(ent, "animation_frame");
		drop = get_entity_property(ent, "drop");

		landframe = getentityproperty(ent, "landframe", animation_id);

		// Not landing?
		if (animation_frame != landframe)
		{
			// Knockdown hit?
			if (drop > 0)
			{
				attack_type = getlocalvar("attacktype");

				// We want to know if this is a burn or shock hit, in which
				// case we also want to know if we're not already in the burn
				// or shock animaiton. In those cases, we play the burn or shock
				// voice.
				//
				// Otherwise this is a standard knockdown, so we'll react accordingly.

				if (attack_type == openborconstant("ATK_BURN") && animation_id != openborconstant("ANI_BURN"))
				{
					dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN_BURN);
				}
				else if (attack_type == openborconstant("ATK_SHOCK") && animation_id != openborconstant("ANI_SHOCK"))
				{
					dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN_SHOCK);
				}
				else
				{
					// This is a normal knockdown, or a burn/shock but we're already 
					// in the burn/shock animation (we don't want to do the dramatic 
					// burn/shock scream over and over). Are our hitpoints low? Decide
					// if we'll play a normal pain grunt or the low health voice
					// accordingly.

					hp_max = 0.0 + getentityproperty(ent, "maxhealth");

					if ((hp / hp_max) <= DC_DAMAGE_HP_KO)
					{
						dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_NEAR_KO);
					}
					else
					{
						dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN_FALL);
					}
				}
			}
			else
			{
				// Non knockdown hit.
				dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN);
			}
		}
		else
		{
			// We're being damaged by landing on the ground. Are our hitpoints 
			// low? Decide if we'll play a normal pain grunt or the low health 
			// voice accordingly.

			hp_max = 0.0 + getentityproperty(ent, "maxhealth");

			if ((hp / hp_max) <= DC_DAMAGE_HP_KO)
			{
				// Play HP low voice.
			}
			else
			{
				// Standard pain voice.
			}
		}
	}
	else
	{
		// KO!
	}
}

void common_take_damage()
{
	void ent;
	int animation_id;
	int animation_frame;
	int landframe;
	int drop;
	int attack_type;
	float hp;
	float hp_max;

	ent = getlocalvar("self");

	hp = 0.0 + get_entity_property(ent, "hp");

	// If the attack will KO us, we go right to
	// KO sound. Otherwise things get more complex.
	if (hp > 0)
	{
		animation_id = get_entity_property(ent, "animation_id");
		animation_frame = get_entity_property(ent, "animation_frame");
		drop = get_entity_property(ent, "drop");

		landframe = getentityproperty(ent, "landframe", animation_id);

		// Not landing?
		if (animation_frame != landframe)
		{
			// Knockdown hit?
			if (drop > 0)
			{
				attack_type = getlocalvar("attacktype");

				// We want to know if this is a burn or shock hit, in which
				// case we also want to know if we're not already in the burn
				// or shock animaiton. In those cases, we play the burn or shock
				// voice.
				//
				// Otherwise this is a standard knockdown, so we'll react accordingly.

				if (attack_type == openborconstant("ATK_BURN") && animation_id != openborconstant("ANI_BURN"))
				{
					dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN_BURN);
				}
				else if	(attack_type == openborconstant("ATK_SHOCK") && animation_id != openborconstant("ANI_SHOCK"))
				{
					dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN_SHOCK);
				}
				else
				{
					// This is a normal knockdown, or a burn/shock but we're already 
					// in the burn/shock animation (we don't want to do the dramatic 
					// burn/shock scream over and over). Are our hitpoints low? Decide
					// if we'll play a normal pain grunt or the low health voice
					// accordingly.

					hp_max = 0.0 + getentityproperty(ent, "maxhealth");

					if ((hp / hp_max) <= DC_DAMAGE_HP_KO)
					{
						dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_NEAR_KO);
					}
					else
					{
						dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN_FALL);
					}
				}
			}
			else
			{
				// Non knockdown hit.
				dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN);				
			}
		}
		else
		{
			// We're being damaged by landing on the ground. Are our hitpoints 
			// low? Decide if we'll play a normal pain grunt or the low health 
			// voice accordingly.
			
			hp_max = 0.0 + getentityproperty(ent, "maxhealth");

			if ((hp / hp_max) <= DC_DAMAGE_HP_KO)
			{
				// Play HP low voice.
				dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_NEAR_KO);
			}
			else
			{
				// Standard pain voice.
				dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN);
			}
		}
	}
	else
	{
		// KO!

		dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_KO);
	}
}

#undef HP_LOW