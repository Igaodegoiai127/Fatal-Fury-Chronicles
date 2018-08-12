#include "data/scripts/vars/entity.h"
#include "data/scripts/com/fall0001.h"

void main()
{
    void vSelf = getlocalvar("self");

    setentityvar(vSelf, STATUS, NULL());    //Take away power up.

    fall0001();
}