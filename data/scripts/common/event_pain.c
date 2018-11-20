#include "data/scripts/dc_kanga/main.c"

void main(){

	event_pain_main();
}

void event_pain_main() {

	void    ent;
	int     animation;
	int     lasthit_y;
	int     height;

	ent = getlocalvar("self");
	animation = getentityproperty(ent, "animationid");

	if (animation == openborconstant("ANI_BURNPAIN"))
	{
	}
	else if (animation == openborconstant("ANI_SHOCKPAIN"))
	{
	}
	else if (animation == openborconstant("ANI_GRABBED"))
	{
	}
	else
	{
		// Hit below 75% of height?

		lasthit_y = openborvariant("lasthita");
		height = getentityproperty(ent, "height");

		if (lasthit_y < height * 0.75)
		{
			changeentityproperty(ent, "animation", openborconstant("ANI_PAIN2"));
		}
	}
}