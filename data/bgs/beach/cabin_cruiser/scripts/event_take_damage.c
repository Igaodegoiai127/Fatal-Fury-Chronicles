#import "data/bgs/beach/cabin_cruiser/scripts/dc_richochet.c"

void oncreate()
{}

void ondestroy()
{}

void main()
{

	void ent;
	void attacker;

	ent = getlocalvar("self");
	attacker = getlocalvar("attacker");
	
	dc_richochet(ent, attacker);

}

