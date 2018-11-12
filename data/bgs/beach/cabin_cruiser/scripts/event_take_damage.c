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

// Caskey, Damon V.
// 2018-11-12
//
// Bounce a falling attacker off and continuetheir fall.
void dc_richochet(void ent, void attacker)
{
	#define DAMAGE_FORCE 0
	#define DAMAGE_DROP 100
	#define DAMAGE_TOSS_Y 2.5

	int falling;
	int direction;
	float vel_x;
	float vel_z;	

	// Is attacker falling? If so, we'll figure out which
	// way to bounce them and then damage/toss them accordingly.

	falling = getentityproperty(attacker, "aiflag", "falling");

	if (falling)
	{
		// Get current X velocity.
		vel_x = getentityproperty(ent, "xdir");			

		// Moving right?
		if (vel_x >= 0)	
		{
			direction = openborconstant("DIRECTION_RIGHT");
			vel_x = -1.5;
			vel_z = -0.1;
		}
		else
		{
			direction = openborconstant("DIRECTION_LEFT");
			vel_x = 1.5;
			vel_z = -0.1;
		}

		// Apply attack/damage.  
		damageentity(attacker, ent, DAMAGE_FORCE, DAMAGE_DROP, openborconstant("ATK_NORMAL"));    

		// Apply direction.
		changeentityproperty(attacker, "direction", direction);

		// Reset fall animation and toss velocity.				                    
		tossentity(attacker, DAMAGE_TOSS_Y, vel_x, vel_z);			       
	}

	#undef DAMAGE_FORCE
	#undef DAMAGE_DROP
	#undef DAMAGE_TOSS_Y
}