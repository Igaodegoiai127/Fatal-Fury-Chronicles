void spaw0006(char cModel, char cAlias, float fX, float fY, float fZ, int iMap, int iAggro){

	/*
	spaw0006
	12262010
	Damon Vaughn Caskey
	Wrapper for basic spawning. Spawns and returns an entity by model name.
	
	cModel:		Model name to spawn.
	cAlias:		Alias to assign.
	fX, fY, fZ:	Location.
	iMap:		Color map to assign.
	iAggro:		Aggression setting.
	*/

	void vSpawn;							//Spawn placeholder.

	clearspawnentry();						//Clear current spawn entry.
	setspawnentry("name",   cModel);		//Aquire spawn entity by name.
    setspawnentry("alias",  cAlias);		//Set alias.
    setspawnentry("map", iMap);				//Spawn map.
	setspawnentry("aggression", iAggro);	//Spawn aggression.
	setspawnentry("coords", fX, fZ, fY);	//Spawn location.
	vSpawn = spawn();						//Spawn entity.
    clearspawnentry();						//Clear current spawn entry.

	return vSpawn;							//Return spawned entity.
}