#include "../includes/blt_lib.h"

void	ft_cd(t_env **env, char *p)
{
	t_env	*tmp;
	char	*op;

	tmp = ft_getval(env, "PWD");
	op = tmp->value;
	if (!p)
	{
		tmp->value = ft_getval(env, "HOME")->value;
		tmp = ft_getval(env, "OLDPWD");
		tmp->value = op;
		chdir(ft_getval(env, "HOME")->value);
		return;
	}
	if((p[0] == '-'))
	{
		if (!(ft_getval(env, "OLDPWD")->value))
		{
			perror("OLDPWD not set");
			return;
		}
		else
		{
			chdir(ft_getval(env, "OLDPWD")->value);
			tmp->value = ft_getval(env, "OLDPWD")->value;
			tmp = ft_getval(env, "OLDPWD");
			tmp->value = op;
			return;
		}
	}
	else
	{
		
	}
}