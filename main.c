#include "minishell.h"

t_garbage_collector *g_free;


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
	char		*input;

	(void)ac;
	(void)av;
	//signal_handler();
	glb_list()->env = save_env(env);
	// print_env(glb_list()->env);
	// while (1)
	// {
		input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$ \033[0m");
		input_error(input);
		//check_quo_error();
		tokens = tokenizer(input);
		if (check_parsing_errors(tokens))
			return (1);
		expanding(tokens);
		print_tokenizer(tokens);
		// t_ast		*ast;
		// ast = ast_builder(tokens);
		// printf("________________NO_THE_TREE_________________");
		// print_node(ast);
		// printf("this is the right \n");
		// print_node(ast->left);
		// printf("this is the left \n");
		// print_node(ast->left);
		free_all(input, tokens);
	// }
}
