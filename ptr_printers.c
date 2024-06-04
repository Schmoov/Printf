/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:05:52 by parden            #+#    #+#             */
/*   Updated: 2024/06/04 14:32:43 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void cap_strlen(char *s, int cap)
{
	while (cap && *s)
	{
		s++;
		cap--;
	}
	*s = 0;
}

int	s_printer(t_token *tok, void *p)
{
	char	*toprint;
	int		ret_value;

	if (p)
		toprint = ft_strdup((char *)p);
	else if (!tok->has_prec || tok->precision > 5)
		toprint = ft_strdup("(null)");
	else
		toprint = ft_strdup("");
	if (p && tok->has_prec)
		cap_strlen(toprint, tok->precision);
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}

int	p_printer(t_token *tok, void *p)
{
	char	*toprint;
	int		ret_value;

	if (p)
	{
		toprint = ptrtoa_base(p, LOBASE16);
		add_base_prefix(&toprint, tok, "0x");
	}
	else
		toprint = ft_strdup("(nil)");
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}
