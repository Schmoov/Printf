/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:07:25 by parden            #+#    #+#             */
/*   Updated: 2024/06/03 18:49:59 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

char	*pad_with_char(char **printed, int output_len, char c, bool leftpad)
{
	char	*prefix;
	char	*res;

	if (!suffix)
		return (NULL);
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
	int count;

	count = 1;
	while (!tok->minus_flag && tok->width > 1)
	{
		ft_putchar_fd(' ', 1);
		tok->width--;
		count++;
	}
	ft_putchar_fd((unsigned char)n, 1);
	while (tok->minus_flag && tok->width > 1)
	{
		ft_putchar_fd(' ', 1);
		tok->width--;
		count++;
	}
	return (count);
}

char	*add_int_precision(char *printed, t_token *tok)
{
	if (tok->has_prec && (size_t)tok->precision > ft_strlen(printed))
		return (pad_with_char(printed, tok->precision, '0', true));
}

char	*add_zero_flag(char *printed, t_token *tok)
{
	if (tok->zero_flag)
	{
		if (tok->sign)
			(tok->width)--;
		if (tok->width >= 0 && (size_t)tok->width > ft_strlen(printed))
			printed = pad_with_char(printed, tok->width, '0', true);
	}
	return (printed);
}

char	*add_sign(char *printed, t_token *tok)
{
	if (tok->sign)
		printed = pad_with_char(printed, ft_strlen(printed) + 1, tok->sign, true);
	return (printed);
}

char	*add_width_blanks(char *printed, t_token *tok)
{
	if (!tok->zero_flag && tok->width >= 0 && (size_t)tok->width > ft_strlen(printed))
		printed = pad_with_char(printed, tok->width, ' ', !(tok->minus_flag));
	return (printed);
}

int	d_printer(t_token *tok, int n)
{
	char	*printed;
	int		ret_value;

	if (n < 0)
		tok->sign = '-';
	if (!n && !tok->precision)
		printed = ft_strdup("");
	else
		printed = itoa_base(n, BASE10, true);
	add_precision_zeroes(&printed, tok);
	add_width_zeroes(&printed, tok);
	add_sign(&printed, tok);
	add_width_blanks(&printed, tok);
	if (!printed)
		return (-1);
	ret_value = ft_strlen(printed);
	ft_putstr_fd(printed, 1);
	free(printed);
	return (ret_value);
}

int	d_printer(t_token *tok, int n)
{
	char	*printed;
	int		ret_value;

	if (n < 0)
		tok->sign = '-';
	printed = itoa_base(n, BASE10, true);
	if (!printed)
		return (-1);
	//Dealing with n == 0 default precision
	if (!tok->has_prec && !n)
	{
		free(printed);
		printed = ft_strdup("0");
		if (!printed)
			return (-1);
	}
	//precision doesnt count sign space
	if (tok->has_prec && (size_t)tok->precision > ft_strlen(printed))
	{
		printed = pad_with_char(printed, tok->precision, '0', true);
		if (!printed)
			return (-1);
	}
	//need to treat '0' flag before the sign to not print "00-42"
	if (tok->zero_flag)
	{
		if (tok->sign)
			(tok->width)--;
		if ((size_t)tok->width > ft_strlen(printed))
		{
			printed = pad_with_char(printed, tok->width, '0', true);
			if (!printed)
				return (-1);
		}
	}
	//can add sign now
	if (tok->sign)
	{
		printed = pad_with_char(printed, ft_strlen(printed) + 1, tok->sign, true);
		if (!printed)
			return (-1);
	}
	//can add width for non '0' flags
	if ((size_t)tok->width > ft_strlen(printed))
	{
		printed = pad_with_char(printed, tok->width, ' ', !(tok->minus_flag));
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
	if (!tok->has_prec && !n)
	{
		free(printed);
		printed = ft_strdup("0");
		if (!printed)
			return (-1);
	}
	if (tok->has_prec && (size_t)tok->precision > ft_strlen(printed))
	{
		printed = pad_with_char(printed, tok->precision, '0', true);
		if (!printed)
			return (-1);
	}
	if ((size_t)tok->width > ft_strlen(printed))
	{
		if (tok->zero_flag)
		{
			printed = pad_with_char(printed, tok->width, '0', true);
			if (!printed)
				return (-1);
		}
		else
		{
			printed = pad_with_char(printed, tok->width, ' ', !(tok->minus_flag));
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
	if (tok->has_prec && !n)
	{
		free(printed);
		printed = ft_strdup("0");
		if (!printed)
			return (-1);
	}
	if (tok->precision >= 0 && (size_t)tok->precision > ft_strlen(printed))
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
		if (tok->width >= 0 && (size_t)tok->width > ft_strlen(printed))
		{
			printed = pad_with_char(printed, tok->width, '0', true);
			if (!printed)
				return (-1);
		}
	}
	if (tok->prefix && n)
	{
		printed = add_prefix(printed, "0x");
		if (!printed)
			return (-1);
	}
	if (tok->width >= 0 && (size_t)tok->width > ft_strlen(printed))
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
	if (tok->precision == -1 && !n)
	{
		free(printed);
		printed = ft_strdup("0");
		if (!printed)
			return (-1);
	}
	if (tok->precision >= 0 && (size_t)tok->precision > ft_strlen(printed))
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
		if (tok->width >= 0 && (size_t)tok->width > ft_strlen(printed))
		{
			printed = pad_with_char(printed, tok->width, '0', true);
			if (!printed)
				return (-1);
		}
	}
	if (tok->prefix && n)
	{
		printed = add_prefix(printed, "0X");
		if (!printed)
			return (-1);
	}
	if (tok->width >= 0 && (size_t)tok->width > ft_strlen(printed))
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
