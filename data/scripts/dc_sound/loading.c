#include "data/scripts/dc_sound/config.h"

void dc_sounds_populate_database(char category, int sample)
{
	void array_category;

	// Array is kept as a localvar
	// Get the array of sounds.
	array_category = getglobalvar(category);

	if (!array_category)
	{
		return;
	}

	// Reset row cursor.
	reset(array_rows);
}

void dc_sounds_load_array_manual()
{
	void array_cols_a;
	void array_cols_b;
	void array_rows;
	void column_array;
	void column_element;
	int  column_last;
	int  row_last;

	// Column values. We need to create the array of
	// columns first, since they will be inserted
	// into a row array element.
	array_cols_a = array(5);
	set(array_cols_a, "A", "A");
	set(array_cols_a, "B", "B");
	set(array_cols_a, "C", "C");
	set(array_cols_a, "D", "D");
	set(array_cols_a, "E", "E");

	array_cols_b = array(5);
	set(array_cols_b, "A", "Z");
	set(array_cols_b, "B", "Y");
	set(array_cols_b, "C", "X");
	set(array_cols_b, "D", "W");
	set(array_cols_b, "E", "V");

	// Rows array. Each row element is an array of columns.
	// Create array.
	array_rows = array(2);
	set(array_rows, "0", array_cols_a);
	set(array_rows, "1", array_cols_b);

	// Reset row cursor.
	reset(array_rows);

	// Loop all elements of row array.
	do
	{
		// Is this the last row?
		row_last = islast(array_rows);

		log("Row - key: ");
		log(key(array_rows));
		log("\n");

		// Get current row value, which
		// will be an array of columns.
		column_array = value(array_rows);

		// Move to cursor to next array
		// element and get cursor value.
		// Will be 0 if we're already
		// at last array element.
		next(array_rows);


		// Reset cursor for our current
		// array of columns.
		reset(column_array);

		// Loop all elements of column array.
		do
		{
			column_last = islast(column_array);

			log("Column - Key: ");
			log(key(column_array));

			column_element = value(column_array);
			next(column_array);

			log(", value: " + column_element);
			log("\n");

		} while (!column_last)

			log("\n\n");
	} while (!row_last);
}