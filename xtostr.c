/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtostr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:07:25 by parden            #+#    #+#             */
/*   Updated: 2024/05/30 18:10:09 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	c_printer(t_token *tok, int n)
{
	ft_putchar_fd((char) n, 1);
	return (1);
}

char	*str_filled_with_char(int len, char c)
{
	char	*res;

	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memset(res, c, len);
	res[len] = 0;
	return (res);
}

char	*pad_with_char(char *suffix, int output_len, char c, bool leftpad)
{
	char	*prefix;
	char	*res;

	prefix = str_filled_with_char(output_len - ft_strlen(suffix), c);
	if (!prefix)
	{
		free(suffix);
		return (NULL);
	}
	if (leftpad)
		res = ft_strjoin(prefix, suffix);
	else
		res = ft_strjoin(suffix, prefix);
	free(prefix);
	free(suffix);
	return (res);
}

int	d_printer(t_token *tok, int n)
{
	char	*printed;
	int		ret_value;

	printed = itoa_base(n, BASE10, true);
	if (!printed)
		return (-1);
	if (tok->precision >= 0 && tok->precision > ft_strlen(printed))
	{
		printed = pad_with_char(printed, tok->precision, '0', true);
		if (!printed)
			return (-1);
	}
	if (tok->pad == '0' && tok->precision < 0)
	{
		if (n < 0 || tok->sign)
			(tok->width)--;
		if (tok->width > ft_strlen(printed))
		{
			printed = pad_with_char(printed, tok->width, '0', true);
			if (!printed)
				return (-1);
		}
	}
	if (n < 0)
	{
		printed = pad_with_char(printed, ft_strlen(printed) + 1, '-', true);
		if (!printed)
			return (-1);
	}
	else if (tok->sign)
	{
		printed = pad_with_char(printed, ft_strlen(printed) + 1, tok->sign, true);
		if (!printed)
			return (-1);
	}
	if (tok->width > ft_strlen(printed))
	{
			printed = pad_with_char(printed, tok->width, ' ', !(tok->pad == '-'));
			if (!printed)
				return (-1);
	}
	ret_value = ft_strlen(printed);
	ft_putstr_fd(printed, 1);
	free(printed);
	return (ret_value);
}


/*
int	d_printer(t_token *tok, int n)
{
	char	*printed;
	int		ret_value;

	printed = itoa_base(n, BASE10, true);
	if (!printed)
		return (-1);
	if (tok->precision >= 0 && tok->precision > ft_strlen(printed))
	{
		printed = pad_with_char(printed, tok->precision, '0', true);
		if (!printed)
			return (-1);
	}
	if (tok->width && (n < 0 || tok->sign))
		(tok->width)--;
	if (tok->width > ft_strlen(printed))
	{
		if (tok->pad == '0' && tok->precision < 0)
		{
			printed = pad_with_char(printed, tok->width, '0', true);
			if (!printed)
				return (-1);
		}
		else if (tok->pad == '-')
		{
			printed = pad_with_char(printed, tok->width, ' ', false);
			if (!printed)
				return (-1);
		}
		else
		{
			printed = pad_with_char(printed, tok->width, ' ', true);
			if (!printed)
				return (-1);
		}
	}
	if (n < 0)
	{
		printed = pad_with_char(printed, ft_strlen(printed) + 1, '-', true);
		if (!printed)
			return (-1);
	}
	else if (tok->sign)
	{
		printed = pad_with_char(printed, ft_strlen(printed) + 1, tok->sign, true);
		if (!printed)
			return (-1);
	}
	ret_value = ft_strlen(printed);
	ft_putstr_fd(printed, 1);
	free(printed);
	return (ret_value);
}

*/
