/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:15:47 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/16 16:50:31 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	q_add(char *arg, t_token **head, t_flags *flag, int i)
{
	flag->len = chr_q(arg + i + 1, flag, arg[i]);
	printf("-%c-\n", arg[i + 2]);
	if (flag->len || (!flag->len
			&& (flag->spc && (spc_chk(arg[i + 2]) || !arg[i + 2]))))
		token_back(head, ft_quotes(arg + i, flag), flag->spc);
	i += flag->len + 2;
	if (!flag->len && (flag->spc))
		flag->spc = 1;
	else
		flag->spc = 0;
	return (i);
}

int	wrd_add(t_token **head, t_flags *flag, char *arg, int i)
{
	flag->len = ft_delim(arg + i);
	token_back(head, word_tok(arg + i, flag->len), flag->spc);
	flag->spc = 0;
	i += flag->len;
	return (i);
}
