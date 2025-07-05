#include "minishell.h"

t_garbage_collector *g_free;

int main()
{

	char	*input;
	t_tokenizer *tokens;
	t_tokenizer	*temp;
	t_ast		*ast;
	int i = 0;

	//signal_handler();
	input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m");
	//check_quo_error();
	//fix_input(input);
	tokens = tokenizer(input);
	ast = ast_builder(tokens);
	temp = tokens;
	printf("_____________________\n");
	while (temp != NULL)
	{
		printf("%d",temp->i);
		if (temp->op == -1)
		{
			printf("%s\n",temp->str);
			printf("%d\n",temp->quote_state);
		}
		else
			print_op(temp->op, temp->str);
		temp = temp->next;
		i++;
		printf("----------------\n");
	}
	temp = tokens;
	free_all(input, tokens);
}
