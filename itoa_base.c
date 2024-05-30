/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:40:38 by parden            #+#    #+#             */
/*   Updated: 2024/05/30 14:16:14 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

//Output string will NOT have '-' character !!!
//for n == 0 output is ""
static size_t	count_char(long long n, char *base, size_t lbase)
{
	size_t	count;

	count = 0;
	while (n)
	{
		count++;
		n /= lbase;
	}
	return (count);
}

char	*wrap_itoa_base(long long n, char *base)
{
	size_t	len;
	char	*res;
	size_t	lbase

	lbase = ft_strlen(base);
	len = count_char(n, base, lbase);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = 0;
	if (n < 0)
	{
		n = -n;
	}
	while (n)
	{
		res[len - 1] = base[(n % lbase)];
		len--;
		n /= lbase;
	}
	return (res);
}

char	*itoa_base(int n, char *base, bool is_signed)
{
	long long	nb;

	if (is_signed)
		nb = n;
	else
		nb = (unsigned int)n;
	return (wrap_itoa_base(nb, base));
}
