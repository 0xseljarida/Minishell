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
		printf("index : %d\n",temp->i);
		if (temp->op == -1)
		{
			printf("cmd   : %s\n",temp->str);
			printf("quote : %d\n",temp->quote_state);
		}
		else
			print_op(temp->op, temp->str);
		temp = temp->next;
		i++;
		printf("----------------\n");
	}
}

void	print_tree(t_ast	*ast)
{
	while (ast != NULL)
	{
		if (ast->type != PIPE)
		{
			print_tokenizer(ast->cmd_line);
		}
		if (ast->left != NULL && ast->left->type != PIPE)
		{
			print_tokenizer(ast->left->cmd_line);
		}
		ast = ast->left;
	}
}

void	print_node(t_ast	*ast)
{
	if (ast->type == PIPE)
		return ;
	print_tokenizer(ast->cmd_line);
}

// char	*handle_input(char *input)
// {
// 	int	i;
// 	int	len;

// 	len = ft_strlen(input);
// 	i = 0;
// 	while (i )
// 	if (input[i] == '\'' && input[i + 1] == '\'' ||
// 		input[i] == '\"' && input[i + 1] == '\"')
// 	{
// 		while(i < len)	
// 		{
			
// 		}
// 	}
// }

int	main(int ac, char **av, char **env)
{

	t_tokenizer *tokens;
	t_ast		*ast;
	char		*input;

	//signal_handler();
	input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m");
	//check_quo_error();
	//fix_input(input);
	tokens = tokenizer(input);
	expanding(tokens);
	print_tokenizer(tokens);
	ast = ast_builder(tokens);
	printf("________________NO_THE_TREE_________________");
	print_node(ast);
	print_node(ast->left);
	print_node(ast->right);
	free_all(input, tokens);
}
