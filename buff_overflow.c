#include <stdio.h>
#include <string.h>

#define STR_SIZE 15

void other_function()
{
	int x = 0x5016;
	int y = 0x1023456;
	double z = 15213.412;
	char input[STR_SIZE]; // the string that'll be placed onto the stack

	// try passing in different sized inputs to see what you get
	printf("Please provide input for our string: \n");
	gets(input);

	printf("Our int x: %d\n", x);
}

int main(int argc, char** argv)
{
	other_function(); // just to show a basic function call, make main simpler
	return 0;
}