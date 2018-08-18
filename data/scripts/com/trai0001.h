#include "data/scripts/vars/trails.h"

void trai0001()
{
    /*
    trai0001
    Utunnels
    Unknown Date (Converted to Hungarian Notation by Damon Vaughn Caskey 10262009)

    Parses artificial array (created by numerically sequenced global vars) and displays stored sprite
    depending on stored settings.
    */

	int     i;                  // Loop index.
	int     cd;                 // Expire time.
	void    sprite;             // Sprite pointer.
	float   pos_X;              // Sprite position.
	float   pos_Y;
	float   pos_Z;
	int     draw_flip_x;        // facing.
    void    draw_table;
    float   draw_scale;

    //  Existing draw methods.
    void    old_draw_table;
    int     old_draw_scale_x;
    int     old_draw_scale_y;
    int     old_draw_alpha;
	int     old_draw_flip_x;
    int     old_draw_enable;


	for(i=1; i<=TRAILMAX; i++)                                  //Loop trailer slots.
	{
	     // Get sprite.
		sprite = getglobalvar("trailer"+i+".s");

		// Sprite found?
		if(sprite)
		{
			cd = getglobalvar("trailer"+i+".c");                //Get expire time.

			// No expire time or decremented to 0?
			if(!cd)
			{
			    // Clear the globals for this element.
				setglobalvar("trailer"+i+".c", NULL());         // expire time.
				setglobalvar("trailer"+i+".s", NULL());         // sprite.
				setglobalvar("trailer"+i+".x", NULL());         // X
				setglobalvar("trailer"+i+".z", NULL());         // Y
				setglobalvar("trailer"+i+".a", NULL());         // Z
                setglobalvar("trailer"+i+".m", NULL());         // map.
                setglobalvar("trailer"+i+".r", NULL());         // scale ratio.
			}
			else
			{
			    // Let's get the old drawmethods so we can reapply them
                // when we're done.
                old_draw_enable     = getdrawmethod(NULL(), "enabled");
                old_draw_flip_x     = getdrawmethod(NULL(), "flipx");
                old_draw_scale_x    = getdrawmethod(NULL(), "scalex");
                old_draw_scale_y    = getdrawmethod(NULL(), "scaley");
                old_draw_table      = getdrawmethod(NULL(), "table");
                old_draw_alpha      = getdrawmethod(NULL(), "alpha");

			    // Game not paused?
				if(openborvariant("game_paused")==0)
				{
				    // Decrement expire time.
					setglobalvar("trailer"+i+".c", cd-1);
				}

                // Get global sprite adjustment values.
				pos_X       = getglobalvar("trailer"+i+".x");       // stored X.
				pos_Z       = getglobalvar("trailer"+i+".z");       // stored Z.
				pos_Y       = getglobalvar("trailer"+i+".a");       // stored Y.
				draw_flip_x = getglobalvar("trailer"+i+".f");       // stored facing.
                draw_table  = getglobalvar("trailer"+i+".m");       // stored map.
                draw_scale  = getglobalvar("trailer"+i+".r"); // scale ratio.

                if(!draw_scale)
                {
                    draw_scale = 1;
                }

                draw_scale *= 256;

                // Position adjustments.
                pos_X -= openborvariant("xpos");
                pos_Y = pos_Z-pos_Y-openborvariant("ypos");
                pos_Z -= i;

                // Set global drawmethods.
                changedrawmethod(NULL(), "enabled", 1);
                changedrawmethod(NULL(), "alpha", 6);
                changedrawmethod(NULL(), "scalex", draw_scale);
                changedrawmethod(NULL(), "scaley", draw_scale);
                changedrawmethod(NULL(), "flipx", draw_flip_x);
                changedrawmethod(NULL(), "table", draw_table);

				// Draw the sprite.
				drawsprite(sprite, pos_X, pos_Y, pos_Z, 0);

				// Restore old drawmthods.
				changedrawmethod(NULL(), "enabled", old_draw_enable);
                changedrawmethod(NULL(), "flipx", old_draw_flip_x);
                changedrawmethod(NULL(), "scalex", old_draw_scale_x);
                changedrawmethod(NULL(), "scaley", old_draw_scale_y);
                changedrawmethod(NULL(), "flipx", old_draw_flip_x);
                changedrawmethod(NULL(), "table", old_draw_table);
                changedrawmethod(NULL(), "alpha", old_draw_alpha);
			}
		}
	}
}
