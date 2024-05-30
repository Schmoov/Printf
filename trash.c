#include <stdio.h>

int main()
{
	printf("zero :\n|%012.1d|\nVS\n",-42000);
	printf("|%012d|\n",-42000);

	printf("minus :\n|%-12.5d|\nVS\n",-42);
	printf("|%-5.12d|\n",-42);

	printf("blank :\n|%12d|\nVS\n",-42);
	printf("|%5d|\n",-42);
}
