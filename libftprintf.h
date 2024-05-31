/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:30:15 by parden            #+#    #+#             */
/*   Updated: 2024/05/31 16:56:37 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "0-+ #"

# define BASE10 "0123456789"
# define UPBASE16 "0123456789ABCDEF"
# define LOBASE16 "0123456789abcdef"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

//pad can be \0 (right-justify), '-' (left-justify), or '0' (pad with zero)
//->0>/0
//sign can be \0 (no plus sign) ' ' (blank as plus sign) or '+' (yes plus sign)
//+>' '>\0
//prefix can be \0 (no prefix) or '#' (yes prefix)
//default width is 0
//default precision is -1
typedef struct	s_token
{
	char		spec;
	char		pad;
	char		sign;
	char		prefix;
	int			width;
	int			precision;
}				t_token;
size_t  free_token_strs(char **token_strs);
size_t  count_tokens(const char *s);
int  	tokenize(char **token_strs, const char *s);
void    *free_token_list(t_token **token_list);
t_token *parse_one(const char *token_str);
t_token **parse(const char *s);


char    *itoa_base(int n, char *base, bool is_signed);
char    *ptrtoa_base(void *p, char *base);
char    *str_filled_with_char(int len, char c);
char    *pad_with_char(char *suffix, int output_len, char c, bool leftpad);
char	*add_prefix(char *suffix, char *prefix);
int		c_printer(t_token *tok, int n);
int		d_printer(t_token *tok, int n);
int		s_printer(t_token *tok, void *p);
int		p_printer(t_token *tok, void *p);
#endif
