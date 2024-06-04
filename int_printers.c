/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:07:25 by parden            #+#    #+#             */
/*   Updated: 2024/06/04 14:49:58 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	pad_with_char(char **toprint, int output_len, char c, bool leftpad)
{
	char	*prefix;
	char	*res;

	if (!*toprint)
		return;
	prefix = str_filled_with_char(output_len - ft_strlen(*toprint), c);
	if (!prefix)
	{
		free(*toprint);
		return;
	}
	if (leftpad)
		res = ft_strjoin(prefix, *toprint);
	else
		res = ft_strjoin(*toprint, prefix);
	free(*toprint);
	free(prefix);
	*toprint = res;
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

void	add_precision_zeroes(char **toprint, t_token *tok)
{
	if (*toprint)
		return;
	if (tok->has_prec && (size_t)tok->precision > ft_strlen(*toprint))
		pad_with_char(toprint, tok->precision, '0', true);
}

void	add_width_zeroes(char **toprint, t_token *tok, int prefix_width)
{
	if (*toprint)
		return;
	if (tok->zero_flag)
	{
		tok->width -= prefix_width;
		if (tok->width >= 0 && (size_t)tok->width > ft_strlen(*toprint))
			pad_with_char(toprint, tok->width, '0', true);
	}
}

void	add_sign(char **toprint, t_token *tok)
{
	if (*toprint)
		return;
	if (tok->sign)
		pad_with_char(toprint, ft_strlen(*toprint) + 1, tok->sign, true);
}

void	add_width_blanks(char **toprint, t_token *tok)
{
	if (*toprint)
		return;
	if (!tok->zero_flag && tok->width >= 0 && (size_t)tok->width > ft_strlen(*toprint))
		pad_with_char(toprint, tok->width, ' ', !(tok->minus_flag));
}

void	add_base_prefix(char **toprint, t_token *tok, char *prefix)
{
	char *res;

	if (*toprint || (tok->spec != 'p' && !tok->prefix))
		return;
	res = ft_strjoin(prefix, *toprint);
	free(*toprint);
	*toprint = res;
}

int	d_printer(t_token *tok, int n)
{
	char	*toprint;
	int		ret_value;

	if (n < 0)
		tok->sign = '-';
	if (!n && tok->has_prec && !tok->precision)
		toprint = ft_strdup("");
	else
		toprint = itoa_base(n, BASE10, true);
	add_precision_zeroes(&toprint, tok);
	add_width_zeroes(&toprint, tok, !!tok->sign);
	add_sign(&toprint, tok);
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}

int	u_printer(t_token *tok, int n)
{
	char	*toprint;
	int		ret_value;

	if (!n && tok->has_prec && !tok->precision)
		toprint = ft_strdup("");
	else
		toprint = itoa_base(n, BASE10, false);
	add_precision_zeroes(&toprint, tok);
	add_width_zeroes(&toprint, tok, 0);
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}

int	xlo_printer(t_token *tok, int n)
{
	char	*toprint;
	int		ret_value;

	if (!n && tok->has_prec && !tok->precision)
		toprint = ft_strdup("");
	else
		toprint = itoa_base(n, LOBASE16, false);
	add_precision_zeroes(&toprint, tok);
	add_width_zeroes(&toprint, tok, 2 * tok->prefix);
	add_base_prefix(&toprint, tok, "0x");
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}

int	xup_printer(t_token *tok, int n)
{
	char	*toprint;
	int		ret_value;

	if (!n && tok->has_prec && !tok->precision)
		toprint = ft_strdup("");
	else
		toprint = itoa_base(n, UPBASE16, false);
	add_precision_zeroes(&toprint, tok);
	add_width_zeroes(&toprint, tok, 2 * tok->prefix);
	add_base_prefix(&toprint, tok, "0X");
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}
