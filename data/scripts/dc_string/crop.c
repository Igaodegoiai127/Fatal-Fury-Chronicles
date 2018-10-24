#include "data/scripts/dc_string/config.h"

// Caskey, Damon V.
// 2010-06-18
//
// Crop the right side of a string (haystack) 
// starting with last occurence of needle.

// Example: 
// - haystack:	"data/scripts/hello.c"
// - needle:	"/"
// - output:	"data/scripts"
char dc_string_crop_right(char haystack, char needle)
{
	char    temp_string;
	int     index;

	// Get string length, minus 1
	// to account for zero indexing.
	index = strlength(haystack);

	// The strinlast function doesn't work, so we'll just build
	// our own naive search algorithm here. 
	//
	// We create a temporary string from haystack, starting
	// at the far right character. We then use stringinfirst 
	// to see if our needle is in the temp_string, and if it
	// is we now have an index to use for strleft. 
	//
	// If the result is invalid (-1), then we build the
	// tempstring from haystack, now one character back, and
	// continue until our strinfirst gets a good result.
	do
	{
		index--;

		// Get the right end of haystack, starting
		// from index.
		temp_string = strright(haystack, index);

	} while (strinfirst(temp_string, needle) == -1);

	// Now that we have our index pointing to the last
	// occurence of needle in haystack, we can use strleft 
	// to return the preceeding characters.
	return strleft(haystack, index);
}