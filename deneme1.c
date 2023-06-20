#include<stdio.h>

int main()
{
	enum boolean 
	{
		false = 0, true = 1
	};
	
	enum boolean a;
	
	a = false;
	
	if(a == 1 )
	{
		printf("True\n");	
	}	

	else
	{
		printf("False\n");	
	}	
	
	
	return 0;
}
