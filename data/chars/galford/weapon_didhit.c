void main()
{
	void ent = getlocalvar("self");
	void target = getlocalvar("damagetaker");

	char name;

	name = get_entity_property(target, "name");

	if (name == "Galford_Weller")
	{
		set_entity_property(target, "animation_id", openborconstant("ANI_FOLLOW20"));
	}

}