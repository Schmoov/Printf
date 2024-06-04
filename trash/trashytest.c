#include <stdio.h>
#include "../ft_printf.h"
int ft_printf(const char *format, ...);
int	main()
{
	int res = -69;
	char *str = "n = % 05d in block x = %#-x\nAt address %-20p";

	ft_printf(str,23456,4354976,&res);
	printf("|\n");
	printf(str,23456,4354976,&res);
//	printf("\nici  \n");
//	printf(str,'0',0,'1','2','1',0,0,'1','2');

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
