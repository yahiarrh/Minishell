#ifndef	BLT_LIB_H
# define BLT_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_env{
	char			*name;
	char			*value;
	struct s_env	*next;
} t_env;

t_env	*ft_getenv(char **envp);
t_env	*ft_getval(t_env **env, char *name);
void	ft_env(t_env **env);
void	ft_pwd(t_env **env);
void	ft_cd(t_env **env, char *p);
void	ft_lstadd_back(t_env **lst, t_env *new);
t_env	*ft_lstlast(t_env *lst);
void	ft_echo(char **s);
void	ft_cd(t_env **env, char *p);
void	ft_update(t_env **env, char *name, char *nv);

#endif