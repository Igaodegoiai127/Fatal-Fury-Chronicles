#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_fidelity/main.c"

#define HP_LOW 0.25

void main()
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

	// Release any grappled entities.
	dc_elmers_set_target(ent);
	dc_elmers_disrupt_grapple();

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

					if ((hp / hp_max) <= HP_LOW)
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

			if ((hp / hp_max) <= HP_LOW)
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