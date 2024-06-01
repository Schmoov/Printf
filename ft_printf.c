/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:59:49 by parden            #+#    #+#             */
/*   Updated: 2024/06/01 17:42:58 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	skip_past_token(char **s)
{
	if (!**s)
		return;
	(*s)++;
	while (**s && !is_in(**s, SPECIFIERS))
		(*s)++;
	if(**s)
		(*s)++;
}

static int print_until_percent(char **s)
{
	int	i;

	i = 0;
	while ((*s)[i] && (*s)[i] != '%')
		i++;
	write(1, *s, i);
	*s = *s + i;
	skip_past_token(s);
	return (i);
}

int percent_printer(void)
{
	write(1, "%", 1);
	return (1);
}

static int ptr_dispatcher(t_token *tok, void *p)
{
	if (tok->spec == 's')
		return (s_printer(tok, p));
	return (p_printer(tok, p));
}
	

static int int_dispatcher(t_token *tok, int n)
{
	if (tok->spec == 'i' || tok->spec == 'd')
		return (d_printer(tok, n));
	if (tok->spec == 'u')
		return (u_printer(tok, n));
	if (tok->spec == 'x')
		return (xlo_printer(tok, n));
	if (tok->spec == 'X')
		return (xup_printer(tok, n));
	return (c_printer(tok, n));
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
		count += print_until_percent(&s);
		if (token_list[i]->spec == '%')
			count += percent_printer();
		else if (token_list[i]->spec == 's' || token_list[i]->spec == 'p')
			count += ptr_dispatcher(token_list[i], va_arg(args, void *));
		else
			count += int_dispatcher(token_list[i], va_arg(args, int));
		i++;
	}
	count += print_until_percent(&s);
	free_token_list(token_list);
	va_end(args);
	return (count);
}
