void main()
{
	void target = getlocalvar("damagetaker");

	// If not already powered up, and has powered up animation,
	// then set the power up animation.
	if (getentityvar(target, "entity_status") != 1)
	{
		if (getentityproperty(target, "animvalid", openborconstant("ANI_FOLLOW92")))
		{
			changeentityproperty(target, "animation", openborconstant("ANI_FOLLOW92"));
		}
	}
}