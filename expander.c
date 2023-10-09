#include "includes/blt_lib.h"
#include "includes/tokenizer.h"
#include "includes/parcing.h"

static int	checkarg(char arg)
{
	int	i;

	i = 1;
	if (!ft_isalpha(arg) && arg != '_')
		return (0);
	return (1);
}

static int	spc_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			break ;
		i++;
	}
	return (i);
}

static char	*extr_name(char *s)
{
	char	*nam;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[i] == '$')
	{
		nam = ft_substr("$", 0, 1);
		return (nam);
	}
	if (s[i] == '?')
	{
		nam = ft_substr("?", 0, 1);
		return (nam);
	}
	while (s[i] && s[i] != '$' && checkarg(s[0]))
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			break ;
		i++;
	}
	nam = ft_substr(s, 0, i);
	return (nam);
}

static char	*ft_val(t_env **env, char *name, char *ret)
{
	if (ft_strcmp2(name, "?"))
		ret = ft_strjoin(ret, ft_itoa(0));
	else if (!ft_getval(env, name))
		ret = ft_strjoin(ret, NULL);
	else
		ret = ft_strjoin(ret, ft_getval(env, name)->value);
	return (ret);
}

char	* expand(t_env **env, char *var)
{
	char	*name;
	char	*val;
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (var[i])
	{
		val = ret;
		if (var[i] == '$')
		{
			name = extr_name(var + i + 1);
			ret = ft_val(env, name, ret);
			free(val);
			i += ft_strlen(name) + 1;
		}
		else
		{
			ret = ft_strjoin(ret, ft_substr(var, i, spc_len(var + i)));
			free(val);
			i += spc_len(var + i);
		}
	}
	return (ret);
}
