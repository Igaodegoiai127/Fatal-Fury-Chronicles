/*
****
Add an update script, it should be data/updated.c
Also you can give each level a single updated script using updated_script command.

It is for script draw methods, just in case the screen is scrolled after you draw something in update script.
So it is better to put all draw code in updated script, especially when they are related to level position.
****
In 16/32bit mode, you have to use RGB values, which need to be calculated.

32bit 

R + G*256 + B*65536

16bit

R*31/255 + G*63/255*32 + B*31/255*2048

Currently not easy to use.

white = 16777215
****

*/

#include "data/scripts/trai0001.h"        

void main(){    
    
    trai0001();
    
}