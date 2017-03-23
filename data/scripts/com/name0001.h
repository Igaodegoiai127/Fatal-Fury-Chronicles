#include "data/scripts/vars/index.h"
#include "data/scripts/com/rnd0001.h" 

void name0001(void vEnt)
{

    /*
    name0001
    Damon Vaughn Caskey
    12102008 (moved from spawn0002, created unknown date)
    
    Assign random alias from name chart. Requires names text file. See 
	
	vEnt:	Entity receiving random alias.
    */

    void vModel     = getentityproperty(vEnt, "model");                     //Ent's model name
    char vAlias     = getentityproperty(vEnt, "name");                      //Ent's alias.
    int  iCount     = 0;                                                    //Column count.
    int  iCheck     = 0;                                                    //Valid value flag.
    int  iRndName   = 0;                                                    //Random name flag.
    int  iIndex;                                                            //Names text file index.
    char vMatch;                                                            //Model matching placeholder. 
 
    if (vAlias == "Random")                                                 //Alias set to "Random"?
    {
        iIndex = getindexedvar(TNAMES);                                     //Get names text file index.
        
        if(!iIndex && iIndex != 0)                                          //File index empty and not a 0?
        {                                         
            iIndex = openfilestream("data/bin/names.txt");                  //Open Names file stream.
            setindexedvar(TNAMES, iIndex);                                  //Store value for next check.
        }

        setfilestreamposition(iIndex, 0);                                   //Go to begining of filestream.
        vMatch = getfilestreamargument(iIndex, 0, "string");                //Get first column argument.
                
        do                                                                  //Look through all rows in first colmun until model name is found.                                                                 
        {        
            filestreamnextline(iIndex);
            vMatch = getfilestreamargument(iIndex, 0, "string");
        }
        while (vModel != vMatch && vMatch != "End");

        if (vMatch != "End")                                                //Model found?
        {                                                
            do                                                              //Look through each column on current row to get a count of available names.
            {                                                             
                iCheck = getfilestreamargument(iIndex, iCount, "int");      //Get colmun value (if any).
                iCount++;                                                   //Increment column counter.
            }
            while (!iCheck);                                                //Stop when no colmun value is returned.
            
            iRndName = rnd0001(0, iCount - 2, 0,0,0,0);                     //Select a random number from count of columns.
            vAlias   = getfilestreamargument(iIndex, iRndName, "string");   //Get argument of random column.            
        }
        else                                                                //No alias was found.
        {
            vAlias = vModel;												//Place error msg in alias.
        }
        changeentityproperty(vEnt, "name", vAlias);							//Asign new alias to model.
    }    
}
