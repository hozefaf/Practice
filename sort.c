#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


//Global Variables
#define SIZEOFSTRING 8
int string[SIZEOFSTRING] = {1,3,7,8,2,4,9,6};

void print_array(int * array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
		printf("String = %d ", array[i]);
	printf("\n\n");
}

void quicksort( int * unsorted_string, int sizeofstring)
{
	int i;
	int lessthanstringcounter, greaterthanstringcounter,pointofreference;
	lessthanstringcounter = greaterthanstringcounter = 0;

	int lessthanstring[SIZEOFSTRING] = {0};
	int greaterthanstring[SIZEOFSTRING] = {0};
	for(i =0 ; i<sizeofstring; i++)
	{

		if(unsorted_string[i] == 0)
			break; // we are at the end of the string
		pointofreference = unsorted_string[sizeofstring/2];
		printf("\n PointofReference = %d\n",pointofreference);
		if(unsorted_string[i] <  pointofreference)
		{
			lessthanstring[lessthanstringcounter] = unsorted_string[i];
			printf("\n Less than = %d\n",lessthanstring[lessthanstringcounter]);
			lessthanstringcounter ++;
		}

		else if( unsorted_string[i] >  unsorted_string[sizeofstring/2])
		{
			greaterthanstring[greaterthanstringcounter] = unsorted_string[i];
			printf("\n Greater than = %d\n", greaterthanstring[greaterthanstringcounter]);
			greaterthanstringcounter ++;
		}
	}

	printf("\nLessthancounter = %d", lessthanstringcounter);
	printf("\ngreaterthancounter = %d\n", greaterthanstringcounter);

	print_array(lessthanstring, lessthanstringcounter);
	print_array(greaterthanstring, greaterthanstringcounter);
	memcpy((void *)unsorted_string, (void *)lessthanstring,
	(lessthanstringcounter * sizeof(int)));
	memcpy((void *)(&unsorted_string[lessthanstringcounter+1]), (void
	*)greaterthanstring, (greaterthanstringcounter * sizeof(int)));
	unsorted_string[lessthanstringcounter] = pointofreference;

	print_array(unsorted_string, sizeofstring);
	
	if(lessthanstringcounter >  1)
	{
		printf("\n Less than quick sort call\n");
		quicksort(unsorted_string, lessthanstringcounter);
	}	
	if(greaterthanstringcounter > 1)
	{
		printf("\n greater than quick sort call\n");
		quicksort(&(unsorted_string[lessthanstringcounter + 1]), greaterthanstringcounter);
	}

}


int main(int argc, char * argv[])
{

 	quicksort (string, SIZEOFSTRING);
	print_array(string, SIZEOFSTRING);
}

