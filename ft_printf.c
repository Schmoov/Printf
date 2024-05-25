/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:59:49 by parden            #+#    #+#             */
/*   Updated: 2024/05/25 18:56:08 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static int	put_int_token(t_token *token, int n)
{
	//TODO
}

static int	put_ptr_token(t_token *token, void *ptr)
{
	//TODO
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_token	**token_list;
	size_t	i_s;
	size_t	i_tok;
	int		count;

	count = 0;
	va_start(args, s);
	token_list = parse(s);
	i_s = 0;
	while (s[i_s])
	{
		while (s[i_s] && s[i_s] != '%')
		{
			ft_putchar_fd(s[i_s], 1);
			i_s++;
			count++;
		}
		if (s[i_s] && s[i_s + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i_s += 2;
			count++;
			continue;
		}
		if (!s[i_s])
			break;
		if (token_list[i_tok]->spec == 's' || token_list[i_tok]->spec == 'p')
		{
			void *p = va_arg(args, void *);
			count += put_ptr_token(token_list[i_tok],n);
		}
		else
		{
			int n = va_arg(args, int);
			count += put_int_token(token_list[i_tok],n);
		}
		while (!is_in(s[i_s], SPECIFIERS))
			i_s++;
		i_s++;
		i_tok++;
	}
	va_end(args);
	return (count);
}
