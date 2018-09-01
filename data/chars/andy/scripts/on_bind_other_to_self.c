void main()
{
    void self;
    void other;
    void binding;
    int animation;
    void enable;
    int enable_x;
    int enable_y;
    int enable_z;
    void offset;
    int offset_x;
    int offset_y;
    int offset_z;
    int direction;
    int sort_id;
	int tag;
    void target;
    char target_name;
    char self_name;
    char other_name;

    self    = getlocalvar("self");
    other   = getlocalvar("other");

    binding = getlocalvar("binding");

    animation   = get_binding_property(binding, "matching");
    enable      = get_binding_property(binding, "enable");
        enable_x = get_axis_principal_int_property(enable, "x");
        enable_y = get_axis_principal_int_property(enable, "y");
        enable_z = get_axis_principal_int_property(enable, "z");
    offset = get_binding_property(binding, "offset");
        offset_x = get_axis_principal_int_property(offset, "x");
        offset_y = get_axis_principal_int_property(offset, "y");
        offset_z = get_axis_principal_int_property(offset, "z");
    direction   = get_binding_property(binding, "direction");
    sort_id     = get_binding_property(binding, "sort_id");
	tag			= get_binding_property(binding, "tag");
	target      = get_binding_property(binding, "target");

    self_name   = getentityproperty(self, "name");
    other_name = getentityproperty(other, "name");
    target_name = getentityproperty(target, "name");

    log("\n\n Binding properties:");
    log("\n binding: " + binding);
    log("\n enable: " + enable);
    log("\n enable_x: " + enable_x);
    log("\n enable_y: " + enable_x);
    log("\n enable_z: " + enable_x);
    log("\n offset: " + offset);
    log("\n offset_x: " + offset_x);
    log("\n offset_y: " + offset_x);
    log("\n offset_z: " + offset_x);
    log("\n direction: " + direction);
    log("\n sort_id: " + sort_id);
	log("\n tag: " + tag);
	log("\n target: " + target);
    log("\n self_name: " + self_name);
    log("\n other_name: " + other_name);
    log("\n target_name: " + target_name);


}
