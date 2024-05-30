#include <stdio.h>

int main()
{
	printf("|%#.5x|\n",42);
	printf("|%#0.5x|\n",42);
	printf("|%#5x|\n",42);
	printf("|%0#5x|\n",42);
}
