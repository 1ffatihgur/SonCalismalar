#include<stdio.h>

int main()
{
	
	enum maincollors
{
	Red, Blue, Yellow
};

	enum maincollors pixel;
	
	pixel == Yellow;
	
	if(pixel == Red)
	{
		printf("Red Pixel\n");
	}
	
	
	else if(pixel == Blue)
	{
		printf("Blue Pixel\n");
	}


	else 	
	{
		printf("Yellow Pixel\n");
	}
	
	return 0;
}
