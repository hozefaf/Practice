// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

char a[4] = { 'a', 'b', 'c', 'd' };
char b[5] = { 'd', 'c', 'b', 'a', 'd' };

bool checkstring(char * string1, char* string2) {
	int i = 0;
	int	j = 0;
	int swap;
	bool retval = false;
	while (string1[i] != '\0')
	{
		j = i;
		while (string2[j] != '\0')
		{
			if (string1[i] == string2[j])
			{
				//swap
				swap = string2[j];
				string2[j] = string2[i];
				string2[i] = swap;
				retval = true;
				break;
			}
			j++;
			retval = false;
		}
		i++;

	}

	return retval;

}


int main()
{
	bool match;

    
	match = checkstring(a, b);
	printf("RESULT = %d", match);
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
