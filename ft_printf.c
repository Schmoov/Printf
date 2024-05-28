/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:59:49 by parden            #+#    #+#             */
/*   Updated: 2024/05/28 16:59:44 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static int print_str_litteral(char **s)
{
	int	i;

	i = 0;
	while ((*s)[i] && (*s)[i] != '%')
		i++;
	write(1, *s, i);
	*s = *s + i;
	return (i);
}

static int print_percent_block(char **s, t_token *tok)
{
	int count;

	count = print_str_litteral(s);
	write(1, "%", 1);
	count++;
	(*s)++;
	while (**s && !is_in(**s, SPECIFIERS))
		(*s)++;
	(*s)++;
	return (count);
}

static int print_ptr_block(char **s, t_token *tok, void *p)
{
	//TODO
}

static int print_int_block(char **s, t_token *tok, int n)
{
	//TODO
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_token	**token_list;
	char	*s;
	size_t	i;
	int		count;

	s = (char *)format;
	count = 0;
	i = 0;
	va_start(args, format);
	token_list = parse(format);
	while (token_list[i])
	{
		if (token_list[i]->spec == '%')
			count += print_percent_block(&s, *token_list);
		else if (token_list[i]->spec == 's' || token_list[i]->spec == 'p')
			count += print_ptr_block(&s, *token_list, va_args(args, void *));
		else
			count += print_int_block(&s, *token_list, va_args(args, int));
		i++;
	}
	count += print_str_litteral(&s);
	va_end(args);
	return (count);
}
