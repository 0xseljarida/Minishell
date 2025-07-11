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
int	valide_expanding(char *str, int *start)
{
	int			i;
	char		*var;

	i = 1;
	var = NULL;
	if (str[i] == 0 || str[i] == ' ')
	{
		*start = 1;
		return 0;
	}
	if (!is_alnum(str[i]))
	{
		*start = i;
		return (0);
	}
	while (is_alnum(str[i]))
	{
		if (i == 1 && is_digit(str[i]))
			break;
		i++;
	}
	*start = i;
	var = ft_substr(str, 1, i);
	var = check_env(var, glb_list()->env);
	return (var);
}
void	env_var(t_tokenizer *token)
{
	int	i;
	t_expantion	*expd;
	t_expantion	*head;
	int			*next_start;

	if (token->op != -1)
		return ;
	expd = malloc(sizeof(t_expantion));
	head = expd;

	while (token->str[i] != 0)	
	{
		if (token->str[i] == '$')
		{
			expd->next = malloc(sizeof(t_expantion));
			expd = expd->next;
			expd->value = valid_expanding(token->str + i, next_start);	
			expd->start = i + *next_start;		
		}
		// else if(token->str[i] == '$' && !valide_expanding(token->str + i))
	}
	expd = head;
	head = head->next;
	free(expd);
	return (head);
}

void expanding(t_tokenizer *token)
{
	while (token != NULL)
	{
		env_var(token);
		if (token->quote_state != NO_QUOTE && token->op == -1)
		{
			quote_handling(token->str);
		}
		token = token->next;
	}
}