/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:37 by parden            #+#    #+#             */
/*   Updated: 2024/05/28 16:09:38 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

size_t	free_token_strs(char **token_strs)
{
	size_t	i;

	i = 0;
	while (token_strs[i])
	{
		free(token_strs[i]);
		i++;
	}
	free(token_strs);
	return (0);
}

size_t	count_tokens(const char *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
			i++;
		if (s[i])
		{
			count++;
			i++;
		}
		while (s[i] && !is_in(s[i], SPECIFIERS))
			i++;
		if (s[i])
			i++;
	}
	return (count);
}

static size_t	insert_token(char **token_strs, const char *s, size_t start)
{
	size_t	len;
	
	len = 0;
	while (!is_in(s[start + len], SPECIFIERS))
			len++;
	len++;
	*token_strs = ft_substr(s, start, len);
	if (!*token_strs)
		return (0);
	return (start + len);
}

int	tokenize(char **token_strs, const char *s)
{
	size_t	i_s;
	size_t	i_token_strs;

	i_s = 0;
	i_token_strs = 0;
	while (s[i_s])
	{
		while (s[i_s] && s[i_s] != '%')
			i_s++;
		if (s[i_s])
		{
			i_s = insert_token(token_strs + i_token_strs, s, i_s + 1);
			if (!i_s)
				return (free_token_strs(token_strs));
			i_token_strs++;
		}
	}
	return (1);
}

void	*free_token_list(t_token **token_list)
{
	size_t	i;

	i = 0;
	while (token_list[i])
	{
		free(token_list[i]);
		i++;
	}
	free(token_list);
	return (NULL);
}

static t_token	*new_token(const char token_spec)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->spec = token_spec;
	new->pad = 0;
	new->sign = ' ';
	new->prefix = 0;
	new->width = 0;
	new->precision = -1;

	return (new);
}


static t_token	*parse_one(const char *token_str)
{
	t_token *parsed_token;
	size_t	token_len;
	size_t	i;

	token_len = ft_strlen(token_str);
	parsed_token = new_token(token_str[token_len - 1]);
	if (!parsed_token)
		return (NULL);
	i = 0;
	while (is_in(token_str[i], FLAGS))
	{
		if (token_str[i] == '#')
			parsed_token->prefix = '#';
		if (token_str[i] == '-')
			parsed_token->pad = '-';
		if (token_str[i] == '0' && parsed_token->pad != '-')
			parsed_token->pad = '0';
		if (token_str[i] == '+')
			parsed_token->sign = '+';
		i++;
	}
	if (token_str[i] != '.' && ft_atoi(token_str + i))
		parsed_token->width = ft_atoi(token_str + i);
	while (ft_isdigit(token_str[i]))
		i++;
	if (token_str[i] == '.' && ft_isdigit(token_str[i + 1]))
		parsed_token->precision = ft_atoi(token_str + i + 1);
	return (parsed_token);
}

t_token	**parse(const char *s)
{
	size_t	nb_tok;
	char	**token_strs;
	t_token	**token_list;
	size_t	i;

	nb_tok = count_tokens(s);
	token_strs = (char **)ft_calloc((nb_tok + 1), sizeof(char *));
	if (!token_strs)
		return (NULL);
	if (!tokenize(token_strs, s))
		return (NULL);
	token_list = (t_token **)ft_calloc((nb_tok + 1), sizeof(t_token *));
	if (!token_list)
		return ((void *)free_token_strs(token_strs));
	i = 0;
	while (token_strs[i])
	{
		token_list[i] = parse_one(token_strs[i]);
		if (!token_list[i])
		{
			free_token_strs(token_strs);
			return (free_token_list(token_list));
		}
		i++;
	}
	free_token_strs(token_strs);
	return (token_list);
}
