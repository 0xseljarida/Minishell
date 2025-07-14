#include "minishell.h"

void	input_error(char *input)
{
	int	i;
	int	error;

	i = 0;
	while (input[i])
	{
		error = 1;
		if (is_quote(input[i]))
		{
			i++;
			while (input[i] && !is_quote(input[i]))
				i++;
			if (is_quote(input[i]))
				error = 0;
			if (error == 1)
				printf("error : no such thing \n");
		}
		i++;
	}
}
int	check_parsing_errors(t_tokenizer *token)
{
	while(token != NULL)
	{
		if (token->op != -1 && ((token->next != NULL && token->next->op != -1) || token->next == NULL))
		{
			if (token->op == PIPE )
			{
				printf("Minishell: syntax error near unexpected token `|\'\n");
			}
			else
				printf("Minishell: syntax error near unexpected token \'newline\'");
			return (1);
		}
		token = token->next;
	}
	return (1);	
}