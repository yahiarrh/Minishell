/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:59:34 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 11:14:45 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLT_LIB_H
# define BLT_LIB_H

# include "../minishell.h"

typedef struct s_env{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

t_env	*ft_getenv(char **envp);
t_env	*ft_getval(t_env **env, char *name);
void	ft_env(t_env **env);
void	ft_pwd(t_env **env);
void	ft_cd(t_env **env, char *p);
void	lstadd_back(t_env **lst, t_env *new);
void	lstdelone(t_env *lst, void (*del)(void *));
t_env	*lstlast(t_env *lst);
t_env	*lstnew(char *content);
void	ft_echo(char **s);
void	ft_cd(t_env **env, char *p);
void	ft_update(t_env **env, char *name, char *nv);
void	ft_unset(t_env **env, char **name);
void	ft_export(t_env **env, char **name);
int		ft_checkarg(char *arg);
void	ft_err_msg(char *err, char *targ, char *erty, int exit_stat);
void	ft_exit(char **status);
char	*ft_join(char const *s1, char const *s2);
char	*ft_sub(char const *s, unsigned int start, size_t len);
int		ft_cmp2(const char *s1, const char *s2);
int		ft_cmp(const char *s1, const char *s2);
char	*ft_dup(const char *s);
void	renv(t_env **env);
t_env	*new(char *name, char *val);
#endif