/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtostr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:07:25 by parden            #+#    #+#             */
/*   Updated: 2024/05/30 20:29:45 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

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

int	c_printer(t_token *tok, int n)
{
	char	*printed;
	int		ret_value;

	printed = malloc(2);
	printed[0] = (unsigned char)n;
	printed[1] = 0;
	if (tok->width > 1)
		printed = pad_with_char(printed, tok->width - 1, ' ', !tok->pad);
	ft_putstr_fd(printed, 1);
	if (tok->width > 1)
		return (tok->width);
	return (1);
}

int	d_printer(t_token *tok, int n)
{
	char	*printed;
	int		ret_value;

	printed = itoa_base(n, BASE10, true);
	if (!printed)
		return (-1);
	//precision doesnt count sign space
	if (tok->precision >= 0 && tok->precision > ft_strlen(printed))
	{
		printed = pad_with_char(printed, tok->precision, '0', true);
		if (!printed)
			return (-1);
	}
	//need to treat '0' flag before the sign to not print "00-42"
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
	//can add sign now
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
	//can add width for non '0' flags
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

int	u_printer(t_token *tok, int n)
{
	char	*printed;
	int		ret_value;

	printed = itoa_base(n, BASE10, false);
	if (!printed)
		return (-1);
	if (tok->precision >= 0 && tok->precision > ft_strlen(printed))
	{
		printed = pad_with_char(printed, tok->precision, '0', true);
		if (!printed)
			return (-1);
	}
	if (tok->width > ft_strlen(printed))
	{
		if (tok->pad == '0' && tok->precision < 0)
		{
			printed = pad_with_char(printed, tok->width, '0', true);
			if (!printed)
				return (-1);
		}
		else
		{
			printed = pad_with_char(printed, tok->width, ' ', !(tok->pad == '-'));
			if (!printed)
				return (-1);
		}
	}
	ret_value = ft_strlen(printed);
	ft_putstr_fd(printed, 1);
	free(printed);
	return (ret_value);
}

char	*add_prefix(char *suffix, char *prefix)
{
	char *res;

	res = ft_strjoin(prefix, suffix);
	free(suffix);
	return (res);
}

int	xlo_printer(t_token *tok, int n)
{
	char	*printed;
	int		ret_value;

	printed = itoa_base(n, LOBASE16, false);
	if (!printed)
		return (-1);
	if (tok->precision >= 0 && tok->precision > ft_strlen(printed))
	{
		printed = pad_with_char(printed, tok->precision, '0', true);
		if (!printed)
			return (-1);
	}
	//need to treat '0' flag before prefix
	if (tok->pad == '0' && tok->precision < 0)
	{
		if (tok->prefix)
			(tok->width) -= 2;
		if (tok->width > ft_strlen(printed))
		{
			printed = pad_with_char(printed, tok->width, '0', true);
			if (!printed)
				return (-1);
		}
	}
	if (tok->prefix)
	{
		printed = add_prefix(printed, "0x");
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
int	xup_printer(t_token *tok, int n)
{
	char	*printed;
	int		ret_value;

	printed = itoa_base(n, UPBASE16, false);
	if (!printed)
		return (-1);
	if (tok->precision >= 0 && tok->precision > ft_strlen(printed))
	{
		printed = pad_with_char(printed, tok->precision, '0', true);
		if (!printed)
			return (-1);
	}
	//need to treat '0' flag before prefix
	if (tok->pad == '0' && tok->precision < 0)
	{
		if (tok->prefix)
			(tok->width) -= 2;
		if (tok->width > ft_strlen(printed))
		{
			printed = pad_with_char(printed, tok->width, '0', true);
			if (!printed)
				return (-1);
		}
	}
	if (tok->prefix)
	{
		printed = add_prefix(printed, "0X");
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
