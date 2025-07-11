#include "minishell.h"

// empty_quote(char **s, int i)
// {

// }

void	remove_empty_quote(char *str, int start ,int end, char q)
{
	int	i;

	i = 0;
	while(str[start + i + 1] != 0)
	{
		str[start + i] = str[start + i + 1];
		i++;
		// if (q == '\"')
		// 	expanding(i , );
	}
	start = end - 1;
	i = 0;
	while(str[start + i + 1] != 0)
	{
		str[start + i] = str[start + i + 1];
		i++;
	}
	
	str[ft_strlen(str) - 2] = 0;
}

int	quote_handling(char *str)
{
	int 	i;
	char	q;
	int		start;

	i = 0;
	while (str[i] != 0)
	{
		q = is_quote(str[i]);
		if (q != 0)
		{
			start = i;
			i++;
			while (q != is_quote(str[i]))
				i++;
			remove_empty_quote(str, start, i, q);
			i -= 2;
		}
		i++;
	}
	return (0);
}

/*for other $? $!...*/
int	valid_expanding(char *str, int *start)
{
	int			i;

	i = 0;
	if (!ft_isalnum(str[1]))
		return (0);
	if (ft_isdigit(str[1]))
	{
		*start = 2;
		return (1);
	}
	while (ft_isalnum(str[i]))
		i++;
	*start = i;
	return (1);
}

void	env_var(t_tokenizer *token)
{
	int			i;
	t_expantion	*expd;
	t_expantion	*head;
	int			next_start;


	expd = malloc(sizeof(t_expantion));
	head = expd;
	i = 0;
	while (token->str[i] != 0)	
	{
		if (token->str[i] == '$' && valid_expanding(token->str + i, next_start))
		{
			end = check_env(ft_substr(token->str, i, next_start), glb_list()->env);
			re_alloc(token->str, i, end);
		}
		// else if(token->str[i] == '$' && !valide_expanding(token->str + i))
	}
	expd = head;
	head = head->next;
	free(expd);
}

void expanding(t_tokenizer *token)
{
	while (token != NULL)
	{
		// if (token->op != -1)
		// 	env_var(token);
		if (token->quote_state != NO_QUOTE && token->op == -1)
		{
			quote_handling(token->str);
		}
		token = token->next;
	}
}