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
	t_ast		*ast;
	char		*input;
	t_env		*env_list;
	(void)ac;
	(void)av;
	//signal_handler();
	env_list =  save_env(env);
	while(env_list != NULL)
	{
		printf("%s", env_list->name);
		printf("=");
		printf("%s\n", env_list->value);
		printf("%s",env_list->next->name);
		env_list = env_list->next;
	}
	return 0;
	while (1)
	{
		input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$ \033[0m");
		//check_quo_error();
		tokens = tokenizer(input);
		//expanding(tokens);
		print_tokenizer(tokens);
		ast = ast_builder(tokens);
		printf("________________NO_THE_TREE_________________");
		print_node(ast);
		printf("this is the right \n");
		print_node(ast->left);
		printf("this is the left \n");
		print_node(ast->left);
		free_all(input, tokens);
	}
}
