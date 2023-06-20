#include<stdio.h>

int main( void )
{
	
	
	struct 
	{
		char name [40];
		int lenght;
		struct 
		{
			int year;
			int month;
			int day;
		} bornInformation;
	}person;


	printf("Your name: " );
	scanf("%s", person.name); 
	printf("Your lenght: "); 
	scanf("%d", &person. lenght );
	printf("Your birth day: "); scanf("%d-%d-%d",&person.bornInformation.month, &person.bornInformation. day,&person.bornInformation. year );
	
	printf("Entered information:\n" );
	printf("Name: %s\n", person.name);
	printf("Lenght: %d\n", person.lenght );
	printf("Birth day: %d/%d/%d\n", person.bornInformation.month, person.bornInformation.day,person.bornInformation.year );
return 0;
}


