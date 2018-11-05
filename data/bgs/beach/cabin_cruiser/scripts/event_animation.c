void oncreate()
{}

void ondestroy()
{}

// Caskey, Damon V.
// 2018-11-05
//
// Decrement base. If already at a specified point,
// kill self instead.
void sink_and_suicide()
{
	void ent;
	int base;

	ent = getlocalvar("self");

	base = 0.0 + getentityproperty(ent, "base");

	if (base < -180)
	{
		killentity(ent);
	}
	else
	{
		base--;

		changeentityproperty(ent, "base", base);
		changeentityproperty(ent, "velocity", 0, 0, 0);
	}
}