/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.memtest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:45:29 by parden            #+#    #+#             */
/*   Updated: 2024/05/26 12:44:13 by parden           ###   ########.fr       */
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
