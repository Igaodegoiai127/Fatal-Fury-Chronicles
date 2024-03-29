//Blocked by obstacle.

#include "data/scripts/dc_damage/main.c"

void main()
{
	obstacle_block_main();
}

void obstacle_block_main()
{
	/*
	obst0001
	Damon Vaughn Caskey
	11/13/2009
	Primary obstacle function. Run for most entities when movement is blocked by an obstacle entity.
	*/

	void    vSelf = getlocalvar("self");															//Calling entity. 
	int     iFall = getentityproperty(vSelf, "aiflag", "falling");								//Falling flag.
	int     iDamage = 0;																			//Damage to apply on self.
	void    vOpp;																						//Last interaction.
	void    vObstacle;																					//Blocking entity.        
	int     iDir;																						//Facing setting.    
	int     iXDir;																						//Current X velocity.
	int     iXVel;																						//Set X velocity.    
	int     iOHeight;																					//Obstacle height.
	int     iY;																							//Self Y location.
	int		iDOL;																						//Damage on landing.
	int		iOHP;																						//Obstacle health.
	int		iRush;																						//Opponent rush count.		

	if (iFall)																							//Falling?
	{
		vObstacle = getlocalvar("obstacle");															//Get blocking entity.
		iOHeight = getentityproperty(vObstacle, "height");											//Get obstacle height.    
		iY = getentityproperty(vSelf, "a");													//Get self Y.        
		iOHP = getentityproperty(vObstacle, "health");											//Get obstacle health.

		if (iOHeight > iY)																				//Self lower then obstacle's top?
		{
			iXDir = getentityproperty(vSelf, "xdir");												//Get current X velocity.
			vOpp = getentityproperty(vSelf, "opponent");											//Get last interaction.
			iDOL = getentityproperty(vSelf, "damage_on_landing");								//Get damage on landing value.
			iOHP = getentityproperty(vObstacle, "health");										//Get obstacle health.
			iRush = getentityproperty(vOpp, "rush_count");										//Get last interaction's rush count.

			changeentityproperty(vOpp, "rush_count", iRush + 2);										//Add 2 hits to opponent's rush count (one for self, and another for obstacle).

			if (iXDir >= 0)																				//Moving Right?
			{
				iDir = 2;																			//Set facing right.
				iXVel = -1.5;																			//Set movement left.
				iDamage += (iXDir * 3);																	//Set damage (Velocity * 3).
			}
			else																						//Moving left.
			{
				iDir = -2;																			//Set facing left.
				iXVel = 1.5;																			//Set movement right.
				iDamage += ((-iXDir) * 3);																//Set damage (Resigned velocity * 3).
			}

			// bind0008("flash", "flash", 0, 1, 0, 0, 0, 0, 0, 0, 1);										//Spawn flash.

			// Damage self
			dc_damage_set_entity(vSelf);
			dc_damage_set_other(vOpp);
			dc_damage_set_damage(iDamage + iDOL);
			dc_damage_set_drop_force(100);
			dc_damage_set_attack_type(openborconstant("ATK_NORMAL"));
			dc_damage_set_direction_adjust(openborconstant("DIRECTION_ADJUST_OPPOSITE"));
			dc_damage_set_drop_velocity_x(0.0);
			dc_damage_set_drop_velocity_y(0.0);
			dc_damage_set_drop_velocity_z(0.0);

			dc_damage_apply_damage();

			// If obstacle will survive, bounce off.
			if (iOHP > iDamage)																			//Will obstacle survive damage?
			{
				changeentityproperty(vSelf, "animation", openborconstant("ANI_FALL"));					//Reset fall animation.
				tossentity(vSelf, 2.5, iXVel, 0);														//Apply toss values.
			}
			
			//  Now damage the obstacle.
			dc_damage_set_entity(vObstacle);
			dc_damage_set_other(vOpp);
			dc_damage_set_damage(iDamage);
			dc_damage_set_drop_force(100);
			dc_damage_set_attack_type(openborconstant("ATK_NORMAL"));
			dc_damage_set_direction_adjust(NULL());
			dc_damage_set_drop_velocity_x(0.0);
			dc_damage_set_drop_velocity_y(0.0);
			dc_damage_set_drop_velocity_z(0.0);

			dc_damage_apply_damage();
		}
	}
}