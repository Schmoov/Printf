#include <stdio.h>
#include "../ft_printf.h"
int ft_printf(const char *format, ...);
int	main()
{
	int res = -69;
	char *str = "%-7c%.3s%#0 -+12.7% %17p% 4d%++ +i%u%#x%--00-0--07X";
	ft_printf(str,'q',"WANNACRY",&res,INT_MAX,3958496,0,0,4969964);
	printf("           \n");
	printf(str,'q',"WANNACRY",&res,INT_MAX,3958496,0,0,4969964);
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
