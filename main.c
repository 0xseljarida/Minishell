#include "minishell.h"

t_garbage_collector *g_free;

void	print_tokenizer(t_tokenizer *tokens)
{
	int i = 0;
	t_tokenizer	*temp;

	temp = tokens;
	printf("_____________________\n");
	while (temp != NULL && temp->op != PIPE)
	{
		printf("%d - ",temp->i);
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
}

int main()
{

	t_tokenizer *tokens;
	t_ast		*ast;
	char		*input;

	//signal_handler();
	input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m");
	//check_quo_error();
	//fix_input(input);
	tokens = tokenizer(input);
	print_tokenizer(tokens);
	ast = ast_builder(tokens);
	printf("________NO_THE_TREE_________________");
	printf("%s",ast->cmd);
	// while (ast != NULL)
	// {
	// 	if (ast->type != PIPE)
	// 	{
	// 		print_tokenizer(ast->cmd_line);
	// 	}
	// 	if (ast->left != NULL && ast->left->type != PIPE)
	// 	{
	// 		print_tokenizer(ast->left->cmd_line);
	// 	}
	// 	ast = ast->left;
	// }
	free_all(input, tokens);
}
