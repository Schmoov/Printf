#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	printf("\n\n|%-12.5d|\nVS\n",42);
	ft_putchar_fd('|',1);
	d_printer(parse_one("-12.5d"), 42);
	printf("|\n");

	printf("\n\n|%-5.12d|\nVS\n",42);
	ft_putchar_fd('|',1);
	d_printer(parse_one("-5.12d"), 42);
	printf("|\n");

	printf("\n\n|%-12d|\nVS\n",42);
	ft_putchar_fd('|',1);
	d_printer(parse_one("-12d"), 42);
	printf("|\n");

	printf("\n\n|%-12.5d|\nVS\n",42);
	ft_putchar_fd('|',1);
	d_printer(parse_one("-12.5d"), 42);
	printf("|\n");

}
