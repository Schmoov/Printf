/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:30:15 by parden            #+#    #+#             */
/*   Updated: 2024/05/25 17:34:26 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIERS "cspdiuxX"
# define FLAGS "0-+ #"

# include <stdlib.h>

//pad can be /0 (right-justify), '-' (left-justify), or '0' (pad with zero)
//sign can be ' ' (no plus sign) or '+' (yes plus sign)
//prefix can be /0 (no prefix) or '#' (yes prefix)
//default precision is represented as -1
typedef struct	s_token
{
	char		spec;
	char		pad;
	char		sign;
	char		prefix;
	int			width;
	int			precision;
}				t_token;

#endif
