/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:05:52 by parden            #+#    #+#             */
/*   Updated: 2024/05/31 17:05:42 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	char	*printed;
	int		ret_value;

	printed = ft_strdup((char *)p);
	if (!printed)
		return (-1);
	if (tok->precision >= 0)
		cap_strlen(printed, tok->precision);
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

int	p_printer(t_token *tok, void *p)
{
	char	*printed;
	int		ret_value;

	if (p)
	{
		printed = ptrtoa_base(p, LOBASE16);
		if (!printed)
			return (-1);
		printed = add_prefix(printed, "0x");
	}
	else
		printed = ft_strdup("(nil)");
	if (!printed)
		return (-1);
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
