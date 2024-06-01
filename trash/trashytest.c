#include <stdio.h>
#include "../libftprintf.h"
int ft_printf(const char *format, ...);
int	main()
{
	int a = 42;
	int exp;
	int res;
	exp = printf("\n|int :% 5d addr :%p|\n",a,(void *)&a);
	printf("VS");
	res = ft_printf("\n|int :% 5d addr :%p|\n",a,(void *)&a);

	printf("%d VS %d\n",exp,res);

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
