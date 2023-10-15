/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:48:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 11:15:16 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_err_msg(char *err, char *targ, char *erty, int exit_stat)
{
	g_exit_status = exit_stat;
	ft_putstr_fd(PROMPT, 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd(targ, 2);
	ft_putstr_fd(erty, 2);
	return ;
}
