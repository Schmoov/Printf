/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:37 by parden            #+#    #+#             */
/*   Updated: 2024/05/24 17:10:18 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void	*free_res(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static size_t	count_tokens(const char *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
			i++;
		if (s[i] && s[i + 1] != '%')
		{
			count++;
			i += 2;
		}
	}
	return (count);
}

static size_t	insert_token(char **res, const char *s, size_t start)
{
	size_t	len;
	
	len = 0;
	while (!is_in(s[start + len], SPECIFIERS);
			len++;
	len++;
	*res = ft_substr(s, start, len);
	if (!*res)
		return (0);
	return (start + len);
}

char	**tokenizer(const char *s)
{
	char	**res;
	size_t	nb_tok;
	size_t	i_s;
	size_t	i_res;

	nb_tok = count_tokens(s);
	res = (char **)ft_calloc((nb_tok + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i_s = 0;
	i_res = 0;
	while (s[i_s])
	{
		while (s[i_s] && s[i_s] != '%')
			i_s++;
		if (s[i_s] && s[i_s + 1] == '%')
			i_s += 2;
		else if (s[i_s])
		{
			i_s = insert_token(res + i_res, s, i_s + 1);
			if (!i_s)
				return (free_res(res));
			i_res++;
		}
	}
	return (res)
}
