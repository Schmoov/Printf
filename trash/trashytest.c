#include <stdio.h>
#include "../libftprintf.h"

int	main()
{
	int a = 42;
	printf("\n\n|%p|\nVS\n",(void *)&a);
	ft_putchar_fd('|',1);
	p_printer(parse_one("p"),(void *)&a);
	printf("|\n");

	printf("->%d<-\n",printf("%14p",NULL));

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
