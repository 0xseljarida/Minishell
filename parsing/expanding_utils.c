#include "minishell.h"

char	*check_env(char *str)
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

char	*new_alloc(char *str, char *env_value, int start, int len)
{
	int		new_len;
	char	*new_str;

	new_len = ft_strlen(str) - len + ft_strlen(env_value);
	new_str = malloc(new_len + 1);
	ft_strlcpy(new_str, str, start + 1);
	ft_strlcat(new_str, env_value, new_len + 1);
	ft_strlcat(new_str, str + start + len, new_len + 1);
	return (new_str);
}

char	*re_alloc(char *str, int start, int len, char *env_value)
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

t_here_doc	*here_doc(t_tokenizer *token)
{
	char		*delemeter;
	t_here_doc	*hd;
	t_here_doc	*head;

	hd = malloc(sizeof(t_here_doc));
	head = hd;
	hd->str = token->next->str;
	delemeter = hd->str;
	hd->next = malloc(sizeof(t_here_doc));
	hd = hd->next;
	hd->str = readline("> ");
	while (ft_strncmp(delemeter, hd->str, ft_strlen(hd->str)) != 0)
	{
		hd->next = malloc(sizeof(t_here_doc));
		hd = hd->next;
		hd->str = readline("> ");
	}
	hd->next = NULL;
	return (head);
}

t_glb	*glb_list(void)
{
	static t_glb	glb;

	return (&glb);
}
