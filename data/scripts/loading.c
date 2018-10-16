#include "data/scripts/dc_d20/main.c"

void main()
{
	void	s;
	void	value	=	getlocalvar("value");
	void	max		=	getlocalvar("max");
	if(max==1){
		return;
	}else{}

	void percent=value*100/max;
	percent%=++percent;

	void dot=percent%3;
	if(dot==0)
		s=".";
	else if(dot==1)
		s="..";
	else
		s="...";

	drawstring(194,60,2,"WARNING");
	drawstring(36,100,2,"THIS GAME IS NOT PRODUCED UNDER LICENCE OF");
	drawstring(162,140,2,"CAPCOM AND SNK");
	drawstring(143,242,0,"Loading Models..."+percent);
	drawstring(259,242,0,"% Complete"+s);
	drawbox(0,260,480,2,11,rgbcolor(0,122,133),0);
	drawbox(0,260,percent*480*0.01,2,15,rgbcolor(0,233,233),0);

	if (value == max)
	{
		list_models_cached();
	}
}

void list_models_cached()
{
	int i;
	int max;
	char path;
	int loaded;

	max = openborvariant("models_cached");

	for (i = 0; i < max; i++)
	{
		
		path = getmodelproperty(i, 3);

		log("\npath: " + path);
	}
}

