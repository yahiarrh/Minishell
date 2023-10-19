/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:02:23 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/19 10:49:46 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

# include "tokenizer.h"
# include "blt_lib.h"
# include <stdbool.h>
# include <fcntl.h>
# include "../includes/blt_lib.h"
# include "../libft/libft.h"

# define FILE_ERR ": No such file or directory\n"

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}t_cmd;

typedef struct s_args
{
	int				fd_in;
	int				fd_out;
	t_cmd			*cmd;
	struct s_args	*next;
}t_args;

t_cmd	*filtre_exp(t_env **env, t_token *token);
void	arg_back(t_args **lst, t_args *new);
void	chk_redir(t_token *token, t_args *arg, t_env *env);
int		heredoc(t_env *env, char *delim, bool flag);
bool	fill_redir(t_token *token, t_args *new_arg, t_env *env);
t_args	*check_tokens(t_token **token, t_env *env);
t_args	*parcing(t_token *token, t_env *env);
int		ft_cmdsize(t_cmd *lst);
t_cmd	*exp_last(t_cmd *lst);
int		ft_cmdsize(t_cmd *lst);
t_args	*last_arg(t_args *lst);
t_cmd	*cmd_last(t_cmd *lst);
void	cmd_back(t_cmd **lst, t_cmd *new);
void	print_syn(t_token *token);
char	**join_cmds(t_cmd *command);
char	*join_downs(t_token *cmd);
#endif
