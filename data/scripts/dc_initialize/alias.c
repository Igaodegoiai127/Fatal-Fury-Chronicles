#include "data/scripts/dc_initialize/config.h"

// Caskey, Damon V.
// 2018-10-17
//
// Add an entry to list of possible name choices from array.
void dc_alias_quick_add(char name)
{
	void alias_list;

	alias_list = getlocalvar(DC_INITIALIZE_VAR_KEY_ALIAS_LIST);

	if (!alias_list)
	{
		alias_list = array(0);

		setlocalvar(DC_INITIALIZE_VAR_KEY_ALIAS_LIST, alias_list);
	}

	add(alias_list, 0, name);
}

// Attempt to return a random alias from array first,
// then from bin file.
char dc_random_alias(void ent)
{
	char result;

	result = dc_alias_from_array();

	if (!result)
	{
		log("dc_text");
		result = dc_alias_from_text(ent);
	}

	return result;
}

// Caskey, Damon V.
// 2018-10-17
//
// Get a random alias from list of names.
char dc_alias_from_array()
{
	char result;
	void list;
	int size;
	int random_index;

	list = getlocalvar(DC_INITIALIZE_VAR_KEY_ALIAS_LIST);

	// Do we have a valid list of alias names?
	if(list)
	{
		// Get array size and decrement for 0 indexing.
		size = size(list);
		size--;

		// Use last index as upper bound for random 
		// number generator.
		dc_d20_set_range_upper(size);

		// Generate random number.
		random_index = dc_d20_random_int();

		// Use random number to select array
		// index and get the value.
		result = get(list, random_index);
	}

	return result;
}

// Caskey, Damon V.
// 2010-12-19
//
// Get a random alias from text list. Text format is
// as follows:
// 
// model_1_name alias_1 alias_2 alias_2 ...
// model_2_name alias_1 alias_2 alias_3 ...
//
// Model name is the model's name (duh), and
// alias choices list left to right. Each model
// may have as many alias names as desisred.
char dc_alias_from_text(void ent)
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
		column_count = dc_filestream_enumerate_column(names);

		// Set maximum random number to column count.
		dc_d20_set_range_upper(column_count);

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
// Get a count of columns in current row of filestream for
// reference. Ex: If there are 16 columns, function will 
// return 15 (0-15 zero indexed).
int dc_filestream_enumerate_column(int filestream)
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