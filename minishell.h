/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:07:33 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 14:57:18 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include <unistd.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "libft/libft.h"
# include "includes/parcing.h"
# include "includes/tokenizer.h"
# include "includes/blt_lib.h"
# include "includes/expand.h"
# include "includes/exev.h"


int	g_exit_status;
# define PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:\
/usr/local/munki:/Library/Apple/usr/bin"
# define ALLOC 1
# define FREE 0
# define PROMPT "minishell-1.0$ "

typedef struct s_gt
{
	void		*ptr;
	struct s_gt *next;
}t_gt;

void	*get_ptr(size_t i, int flag);

#endif