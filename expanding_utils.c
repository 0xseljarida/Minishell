#include "minishell.h"

// int	is_expanded(char c)
// {
// 	if (is_alnum(c) != 0 && (c == '@' || c == '$', || c == ''))
// }

char *check_env(char *str)
{ 
	t_env	*env;

	env = glb_list()->env;
	while (env != 0)
	{
		if (ft_strncmp(str, env->name, ft_strlen(env->name) + 1) == 0)
		{
			free(str);
			return (env->value);
		}
		env = env->next;
	}
	free(str);
	return (NULL);
}

char *new_alloc(char *str, char *env_value, int start, int len)
{
	// int	i;
	int		new_len;
	// int		env_i;
	char	*new_str;

	new_len = ft_strlen(str) - len + ft_strlen(env_value);
	new_str = malloc(new_len + 1);
	// i = 0;
	// while (i < start)
	// {
	// 	new_str[i] = str[i];
	// 	i++;
	// }
	ft_strlcpy(new_str, str, start + 1);
	ft_strlcat(new_str, env_value, new_len + 1);
	ft_strlcat(new_str, str + start + len, new_len + 1);
	// env_i = 0;
	// while (env_i < ft_strlen(env_value))
	// {
	// 	new_str[i] = env_value[env_i];
	// 	env_i++;
	// 	i++;
	// }
	// while (str[start + len] != 0)
	// {
	// 	new_str[i] = str[start + len];
	// 	start++;
	// 	i++;
	// }
	// new_str[new_len] = 0;
	return (new_str);
}

char	*re_alloc(char *str, int start, int len, char  *env_value)
{
	char	*new_str;

	if (env_value == NULL)
	{
		ft_strlcpy(str + start, str + start + len, ft_strlen(str) - len + 1);
		return (str);
	}
	new_str = new_alloc(str, env_value, start, len);
	free(str);
	return (new_str);
}