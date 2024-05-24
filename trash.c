#include <stdio.h>


int main()
{
	int a = -42;
	
	printf("|%20x|\n",a);
	printf("|%-20x|\n",a);
	printf("|%020x|\n",a);
	printf("|%+20x|\n",a);
	printf("|%#20x|\n",a);
	printf("|% 20x|\n",a);
}

