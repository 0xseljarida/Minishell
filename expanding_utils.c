#include "minishell.h"

// int	is_expanded(char c)
// {
// 	if (is_alnum(c) != 0 && (c == '@' || c == '$', || c == ''))
// }

char *check_env(char *str, t_env *env)
{
	while (env != 0)
	{
		if (ft_strcmp(str, env->name) == 0)
		{
			free(str);
			return (env->value);
		}
	}
	free(str);
	return (NULL);
}