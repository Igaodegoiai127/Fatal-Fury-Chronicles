void oncreate()
{
	log("\n");
	log("update.c");
	log("\t");
	log("- oncreate().");
	log("\n");
}

void ondestroy()
{
	log("\n");
	log("update.c");
	log("\t");
	log("- ondestroy().");
	log("\n");
}




void main()
{
	//trai0001();
	//trai0002();

	setdrawmethod(NULL(), 1, 512, 512, 0, 0, 0, 1, -1, 0, 0, 0, 0);

	//changedrawmethod(NULL(), "scalex", 512);
	//changedrawmethod(NULL(), "scaley", 512);
	//changedrawmethod(NULL(), "enabled", 1);

	dc_draw_select_names();
	
}

// Caskey, Damon V.
// 2019-02-22
//
// Draws names of characters during select screen.
void dc_draw_select_names()
{
	#define WAIT_NAME_FONT		3
	#define SELECT_NAME_FONT	4
	#define FONT_Y				18	// Vertical size of font (unavailable as of 2019-02-22). Includes margin.
	#define SELECT_Y_BASE		105
	#define SPACE_CHAR			"_"
	#define	MAX_DRAW_SIZE		256 * 10
	#define MAX_DRAW_SIZE_TIME	100

	// Don't waste any more cycles if we aren't 
	// in select screen.
	if (!openborvariant("in_selectscreen"))
	{
		return;
	}

	int i;
	int maxplayers;
	char name_full;
	char name_last;
	char name_first;

	int font;
	int x_base;
	int x_pos;
	int y_pos;
	int string_width;

	int section_size;
	int section_half;

	int elapsed_time;
	int select_time;

	elapsed_time = openborvariant("elapsed_time");

	maxplayers = openborvariant("maxplayers");

	// Divide up the screen into even sections for each player.
	section_size = openborvariant("hresolution") / maxplayers;
	section_half = section_size / 2;

	for (i = 0; i < maxplayers; i++)
	{
		// When did player select a character?
		select_time = getlocalvar("dc_draw_select_p" + i);

		if (getplayerproperty(i, "playkeys") && !select_time)
		{
			setlocalvar("dc_draw_select_p" + i, elapsed_time + MAX_DRAW_SIZE_TIME);
		}

		if (select_time > elapsed_time)
		{
			int scale_size;
			int base_time;
			int difference;

			// Get time when selection was made.
			base_time = select_time - MAX_DRAW_SIZE_TIME;

			difference = select_time - base_time;

			float percentage = difference / MAX_DRAW_SIZE_TIME;

			changedrawmethod(NULL(), "scalex", percentage * 256);
			changedrawmethod(NULL(), "scaley", percentage * 256);
		}

		

		
		// Get to start of our section, and add half to find the center.
		x_base = (dc_player_multiplier(i) * section_size) + section_half;

		name_full = getplayerproperty(i, "name");
		name_last = strinfirst(name_full, SPACE_CHAR);

		// No last name?
		if (name_last == -1)
		{
			x_pos = dc_center_string_x(x_base, name_full, WAIT_NAME_FONT);
			y_pos = dc_center_string_y(SELECT_Y_BASE, name_full, FONT_Y);

			drawstring(x_pos, y_pos, WAIT_NAME_FONT, name_full);
		}
		else
		{
			// Get a Y center based on two lines (first name, last name).
			y_pos = dc_center_string_y(SELECT_Y_BASE, name_last, FONT_Y * 2);

			// Get first name string and center x position.
			name_first = strleft(name_full, strlength(name_full) - strlength(name_last));
			x_pos = dc_center_string_x(x_base, name_first, WAIT_NAME_FONT);

			drawstring(x_pos, y_pos, WAIT_NAME_FONT, name_first);

			// Remove sapce character from last name.
			name_last = strright(name_last, 1);

			x_pos = dc_center_string_x(x_base, name_last, WAIT_NAME_FONT);

			// Add vertical font space.
			y_pos += FONT_Y;

			drawstring(x_pos, y_pos, WAIT_NAME_FONT, name_last);
		}

		// Restore drawmethod.
		//changedrawmethod(NULL(), "scalex", 256);
		//changedrawmethod(NULL(), "scaley", 256);
	}

	#undef SELECT_NAME_FONT
	#undef SELECT_NAME_FONT_Y
	#undef SELECT_Y_BASE
}

// Caskey, Damon V.
// 2019-02-22
//
// Return position to horizontaly center a string.
int dc_center_string_x(int x_base, char string, int font)
{
	return x_base - (strwidth(string, font) / 2);
}

// Caskey, Damon V.
// 2019-02-22
//
// Return position to horizontaly center a string. At time of
// coding, font height is not available, so we have to use
// a known static font size.
int dc_center_string_y(int y_base, char string, int font_size)
{
	return y_base - (font_size / 2);
}

// Caskey, Damon V.
// 2019-02-22
//
// Dirty function to deal with first player being in 
// the middle when we want to use player number as a
// position multiplier.
int dc_player_multiplier(int player)
{
	switch(player)
	{
		case 0:

			return 1;
			break;

		case 1:

			return 0;
			break;

		default:

			return player;
			break;
	}
}

