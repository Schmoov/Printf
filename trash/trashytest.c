#include <stdio.h>
#include "../libftprintf.h"
int ft_printf(const char *format, ...);
int	main()
{
	int a = 42;
	int exp;
	int res;
	char *str ="zeroes|%.d|%.0d|%.1d|"
		"sign position for negative|%7.3d|%7d|%.7d|%07d|%07.3d|"
		"positives|%+7.3d|%+7d|%+.7d|%+07d|%+07.3d|"
		"left-justif|%7.3d|%7d|%.7d|%07d|%07.3d|%+7.3d|%+7d|%+.7d|%+07d|%+07.3d|";
	res = ft_printf(str,0,0,0,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1);
	printf("\n");
	printf(str,0,0,0,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1);

/*
	printf("\n\n|%0-12.5u|\nVS\n",42);
	ft_putchar_fd('|',1);
	u_printer(parse_one("0-12.5u"), 42);
	printf("|\n");

	printf("\n\n|%0-5.12u|\nVS\n",42);
	ft_putchar_fd('|',1);
	u_printer(parse_one("0-5.12u"), 42);
	printf("|\n");

	printf("\n\n|%0-12u|\nVS\n",42);
	ft_putchar_fd('|',1);
	u_printer(parse_one("0-12u"), 42);
	printf("|\n");

	printf("\n\n|%0-12.5u|\nVS\n",42);
	ft_putchar_fd('|',1);
	u_printer(parse_one("0-12.5u"), 42);
	printf("|\n");
*/
}
