void file0001(int iVar, char cFile, char cRow, int iColumn){

    /*
    file0001
    Damon Vaughn Caskey
    12272010
	Get value from a text file by Row name + column number.

	iVar:		Indexed var used to open and store filestream.
	cFile:		Name of text file to open.
	cRow:		Row id to search for.
	iColumn:	Column number from row find and to return.    	
    */

    char	cArg;																//Argument to return.
    int		iCount     = 0;														//Column count.
    int		iCheck     = 0;														//Valid value flag.
    int		iRndName   = 0;														//Random name flag.
    int		iIndex;																//Names text file index.
    char	cRowM;																//First comun argument in current row (when searching for cRow)
	
    iIndex = getindexedvar(iVar);												//Get text file index.
        
    if(!iIndex && iIndex != 0)													//File index empty and not a 0?
    {                                         
        iIndex = openfilestream("data/bin/"+cFile+".txt");						//Open file stream.
        setindexedvar(iVar, iIndex);											//Store value for next check.
    }

	/*
	Check the first comlmun of every row until a value matching cRow is found.
	*/
    setfilestreamposition(iIndex, 0);											//Go to begining of filestream.
    cRowM = getfilestreamargument(iIndex, 0, "string");							//Get first column argument.                
		
    do																			//Start conditional action loop. 
    {        
        filestreamnextline(iIndex);												//Go to next row.
        cRowM = getfilestreamargument(iIndex, 0, "string");						//Get first comlumn value.
    }
    while (cRow != cRowM && cRowM != "End");									//If no match found for cRow and not at last row ("End"), perform loop actions and continue. 
	
    if (cRowM != "End")															//Was match for cRow found?
    {		
		cArg =	getfilestreamargument(iIndex, iColumn, "string");				//Get argument of iColumn.		

		if (cArg) { return cArg; }												//If value found, return it.
    }
        
	return NULL();																//No value was found, return NULL.		     
}

