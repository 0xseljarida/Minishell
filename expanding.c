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
			 printf("%d %d", start , i);
			 break;
			remove_empty_quote(str, start, i, q);
			i -= 2;
		}
		i++;
	}
	return (0);
}

void expanding(t_tokenizer *token)
{
	while (token != NULL)
	{
		if (token->quote_state != NO_QUOTE && token->op == -1)
			quote_handling(token->str);
		token = token->next;
	}
}