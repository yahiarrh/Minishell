/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:07:33 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/17 12:07:48 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "includes/blt_lib.h"
# include "includes/expand.h"
# include "includes/exev.h"

int	g_exit_status;
# define PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin\
				:/sbin:/usr/local/munki:/Library/Apple/usr/bin"

#endif