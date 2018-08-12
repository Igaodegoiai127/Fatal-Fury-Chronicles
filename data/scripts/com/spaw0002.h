#include "data/scripts/vars/index.h"
#include "data/scripts/com/rema0002.h" 
#include "data/scripts/com/rnd0001.h" 

void spaw0002()
{
    void vSelf      = getlocalvar("self");                                  //Caller.
    void vModel     = getentityproperty(vSelf, "model");                    //Caller's model name
    void vAlias     = getentityproperty(vSelf, "name");                     //Caller's alias.
    int  iCount     = 0;                                                    //Column count.
    int  iCheck     = 0;                                                    //Valid value flag.
    int  iRndName   = 0;                                                    //Random name flag.
    int  iIndex;                                                            //Names text file index.
    void vMatch;                                                            //Model matching placeholder. 
   
    if (getentityproperty(vSelf, "map") == 1)                               //Spawned with KO map?
    {                                   
        rema0002(vSelf, 0, 0, 0, 0, 0);                                     //Apply random remap.
    }

    ////Random alias.////
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
            vAlias = "#Error:_No_Alias";                                   //Place error msg in alias.
        }
        changeentityproperty(vSelf, "name", vAlias);                        //Asign new alias to model.
    }

    ////Initialize new variables.////        
    setentityvar(vSelf, OGMAP, getentityproperty(vSelf, "map"));            //Store applied remap (so we can revert to it after applying effect maps).     

}
