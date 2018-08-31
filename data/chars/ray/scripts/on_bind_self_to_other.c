void oncreate()
{
	void self = getlocalvar("self");
	char name = getentityproperty(self, "name");

	setlocalvar("name", name);

	log("\n Ray (" + name + ") create self to other.");
}

void ondestroy()
{
	log("\n Ray (" + getlocalvar("name") + ") destroy self to other.");
}

void main()
{
	log("\n Ray (" + getlocalvar("name") + ") self to other run.");
}
