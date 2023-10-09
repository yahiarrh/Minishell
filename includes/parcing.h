/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:02:23 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/07 15:58:25 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARCING_H
# define PARCING_H

# include "tokenizer.h"
# include "blt_lib.h"
# include <stdbool.h>
# include <fcntl.h>
# include "../includes/blt_lib.h"
# include "../libft/libft.h"

#define EPIPE "syntax error near unexpected token `|'"



typedef	struct s_cmd
{
	char	*cmd;
	struct s_cmd *next;
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
bool	fill_redir(t_token *token, t_args *new_arg , t_env *env);
t_args	*check_tokens(t_token **token, t_env *env);
t_args  *parcing(t_token *token, t_env *env);
void	wrd_case(t_env **env, t_cmd **head, t_token *token);
void	dq_case(t_env **env, t_cmd **head, t_token *token);
void	sq_case(t_cmd **head, t_token *token);
int	ft_cmdsize(t_cmd *lst);
t_cmd	*exp_last(t_cmd *lst);

#endif
