// Import functions.
#include "data/scripts/dc_afterimage/main.c"
#include "data/scripts/dc_kanga/main.c"

void oncreate()
{
	log("\n");
	log("updated.c");
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

void main() {

	void    ent = NULL();   // Target entity pointer.
	int     ent_count = 0;        // Entity count.
	int     i = 0;        // Loop counter.

	
	// Get entity count.
	ent_count = openborvariant("count_entities");

	// Loop over each entity index.
	for (i = 0; i < ent_count; i++)
	{
		// Get entity pointer.
		ent = getentity(i);

		// Execute tint effect on entity.
		dc_kanga_auto_tint(ent);

		char model = getentityproperty(ent, "model");
		
		//if (getentityproperty(ent, "maxhealth") == 101)
		//{
		
		if(model = "Andy")
		{
			//void think = get_entity_property(ent, "function_think");
			//log("\n think: " + think);

			//void take_damage = get_entity_property(ent, "function_take_damage");
			//log("\n take_damage: " + take_damage);

			void alt_idle = get_entity_property(ent, "alternate_idle");
			log("\n alternate_idle: " + alt_idle);

			set_entity_property(ent, "alternate_idle", 1);

			//log("\n\n Recursive:");

			void recursive = get_entity_property(ent, "recursive_damage");

			/*
			if (recursive)
			{
				log("\n\t pointer: " + recursive);

				int force;
				int index;
				int mode;
				void next;
				void owner;
				int rate;
				int tag;
				int tick;
				int time;
				int type;				

				force = get_recursive_damage_property(recursive, "force");
				index = get_recursive_damage_property(recursive, "index");
				mode = get_recursive_damage_property(recursive, "mode");
				next = get_recursive_damage_property(recursive, "next");
				owner = get_recursive_damage_property(recursive, "owner");
				rate = get_recursive_damage_property(recursive, "rate");
				tag = get_recursive_damage_property(recursive, "tag");
				tick = get_recursive_damage_property(recursive, "tick");
				time = get_recursive_damage_property(recursive, "time");
				type = get_recursive_damage_property(recursive, "type");

				log("\n\t force: " + force);
				log("\n\t index: " + index);
				log("\n\t mode: " + mode);
				log("\n\t next: " + next);
				log("\n\t owner: " + owner);
				log("\n\t rate: " + rate);
				log("\n\t tag: " + tag);
				log("\n\t tick: " + tick);
				log("\n\t time: " + time);
				log("\n\t type: " + type);
			}
			*/
		}

		if (model == "Ray")
		{			
		}
	}
	

	// Draw after images
	trai0001();
}



void dc_kanga_position(void ent, int box, int box_y, int i)
{
	int animation = getentityproperty(ent, "animationid");
	int frame = getentityproperty(ent, "animpos");

	float x = get_entity_property(ent, "position_x");
	float y = get_entity_property(ent, "position_y");
	float z = get_entity_property(ent, "position_z");

	settextobj(box, 50, box_y, 0, -1, "ent: " + i + ", Ani: " + animation + "(" + frame + "), X: " + x + ", Y: " + y + ", Z: " + z, openborvariant("elapsed_time") + 200);
}

