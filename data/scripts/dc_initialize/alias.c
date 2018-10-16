#include "data/scripts/dc_initialize/config.h"

char dc_random_alias(void ent)
{
	char model;
	int names;
	char match;
	char alias;
	int column_count;
	int random_index;

	model = getentityproperty(ent, "model");

	// Get names text file index.
	names = getglobalvar("filestream_names");

	// If there is no file index, then we need to 
	// open one.
	if (typeof(names) == openborconstant("VT_EMPTY"))
	{
		// Open Names file stream.
		names = openfilestream("data/bin/names.txt");
		setindexedvar("filestream_names", names);
	}

	// Make sure we are at the begining of file,
	// and get first column value.
	setfilestreamposition(names, 0);
	match = getfilestreamargument(names, 0, "string");

	// Look through all rows in first colmun until model name is found.   
	do
	{

		filestreamnextline(names);
		match = getfilestreamargument(names, 0, "string");

	} while (model != match && match);

	// Found the model?
	if (match)
	{
		// Get number of columns with a name value.
		column_count = dc_filestream_column_index_count(names);

		// Set maximum random number to column count.
		setlocalvar(DC_D20_KEY_UPPER, column_count);

		// Generate random number.
		random_index = dc_d20_random_int();

		// Use random number to select a column value.
		alias = getfilestreamargument(names, random_index, "string");
	}
	else
	{
		// If no model match was found, alert user with
		// an error message instead.
		alias = "#Error:_No_Alias";
	}

	// Return the resulting alias.
	return alias;
}

// Caskey, Damon V.
// 2018-10-16
//
// Count the number of columns in a filestream
// line for indexed referencing.
int dc_filestream_column_index_count(int filestream)
{

	int count;
	char value;

	// Make sure count is a valid 0, or
	// filestreamargument() will fail.
	count = 0;

	// Count the number of columns that have a valid string value.
	do
	{
		// Get colmun value (if any).
		value = getfilestreamargument(filestream, count, "string");

		// Only increment if a value is found.
		if (value)
		{
			count++;
		}

	} while (value);

	// Decrement by 1 to compensate for zero indexing.	
	count--;

	return count;
}