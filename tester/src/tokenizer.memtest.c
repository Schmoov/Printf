/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.memtest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:45:29 by parden            #+#    #+#             */
/*   Updated: 2024/05/28 13:41:00 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdio.h>
#include "../../libft/libft.h"
#include "../../ft_printf.h"

Test(count_tokens, mandatory)
{
	cr_expect_eq(count_tokens("I live sheltered by luxurious ifelse tree forests"), 0);
	cr_expect_eq(count_tokens("n = %d in block x = %x\nAt address %p"), 3);
	cr_expect_eq(count_tokens("%c%s%p%d%i%u%x%X"), 8);
	cr_expect_eq(count_tokens("Qui pour %s le %s pos %%pos%%\nMerde %%%%pos%%%%\nUwU %d,%d\n"), 4);
	cr_expect_eq(count_tokens("%%%d%%%u%%cs%%p%x%X%%"), 4);
	cr_expect_eq(count_tokens(""), 0);
}


Test(count_tokens, with_flags)
{
	cr_expect_eq(count_tokens("I l---ive 000sheltered by l4354uxuri000ous ifel###se tr#ee forests"), 0);
	cr_expect_eq(count_tokens("n = % 05d in block x = %#-x\nAt address %-12p"), 3);
	cr_expect_eq(count_tokens("%-7c%.3s%014p% 4d%-- -i%u%#x%07X"), 8);
}

Test(tokenize, mandatory)
{
	char **token_strs = ft_calloc(1, sizeof(char *));
	tokenize(token_strs, "I live sheltered by luxurious ifelse tree forests");
	cr_expect_null(token_strs[0]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(4, sizeof(char *));
	tokenize(token_strs,"n = %d in block x = %x\nAt address %p");
	cr_expect_str_eq(token_strs[0], "d");
	cr_expect_str_eq(token_strs[1], "x");
	cr_expect_str_eq(token_strs[2], "p");
	cr_expect_null(token_strs[3]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(9, sizeof(char *));
	tokenize(token_strs,"%c%s%p%d%i%u%x%X");
	cr_expect_str_eq(token_strs[0], "c");
	cr_expect_str_eq(token_strs[1], "s");
	cr_expect_str_eq(token_strs[2], "p");
	cr_expect_str_eq(token_strs[3], "d");
	cr_expect_str_eq(token_strs[4], "i");
	cr_expect_str_eq(token_strs[5], "u");
	cr_expect_str_eq(token_strs[6], "x");
	cr_expect_str_eq(token_strs[7], "X");
	cr_expect_null(token_strs[8]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(5, sizeof(char *));
	tokenize(token_strs,"Qui pour %s le %s pos %%pos%%\nMerde %%%%pos%%%%\nUwU %d,%d\n");
	cr_expect_str_eq(token_strs[0], "s");
	cr_expect_str_eq(token_strs[1], "s");
	cr_expect_str_eq(token_strs[2], "d");
	cr_expect_str_eq(token_strs[3], "d");
	cr_expect_null(token_strs[4]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(5, sizeof(char *));
	tokenize(token_strs,"%%%d%%%u%%cs%%p%x%X%%");
	cr_expect_str_eq(token_strs[0], "d");
	cr_expect_str_eq(token_strs[1], "u");
	cr_expect_str_eq(token_strs[2], "x");
	cr_expect_str_eq(token_strs[3], "X");
	cr_expect_null(token_strs[4]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(1, sizeof(char *));
	tokenize(token_strs,"");
	cr_expect_null(token_strs[0]);
	free_token_strs(token_strs);
}

Test(tokenize, with_flags)
{
	char **token_strs = ft_calloc(1, sizeof(char *));
	tokenize(token_strs,"I l---ive 000sheltered by l4354uxuri000ous ifel###se tr#ee forests");
	cr_expect_null(token_strs[0]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(4, sizeof(char *));
	tokenize(token_strs,"n = % 05d in block x = %#-x\nAt address %-12p");
	cr_expect_str_eq(token_strs[0], " 05d");
	cr_expect_str_eq(token_strs[1], "#-x");
	cr_expect_str_eq(token_strs[2], "-12p");
	cr_expect_null(token_strs[3]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(9, sizeof(char *));
	tokenize(token_strs,"%-7c%.3s%014p% 4d%-- -i%u%#x%07X");
	cr_expect_str_eq(token_strs[0], "-7c");
	cr_expect_str_eq(token_strs[1], ".3s");
	cr_expect_str_eq(token_strs[2], "014p");
	cr_expect_str_eq(token_strs[3], " 4d");
	cr_expect_str_eq(token_strs[4], "-- -i");
	cr_expect_str_eq(token_strs[5], "u");
	cr_expect_str_eq(token_strs[6], "#x");
	cr_expect_str_eq(token_strs[7], "07X");
	cr_expect_null(token_strs[8]);
	free_token_strs(token_strs);
}
