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

int main(int ac, char **av, char **env) {

    t_tokenizer *tokens;
    char *input;
    int exit_status;
    char **args;
    char **envp;
	char *path;

  (void)ac;
  (void)av;

  glb_list()->env = NULL;
  init_env_var(&glb_list()->env, env);

  while (1) {
    input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell $> \033[0m");

    if (!input) {
      printf("exit\n");
      exit(0); // ou free et exit proprement si nécessaire
    }
    // check_quo_error();
    tokens = tokenizer(input);
    expanding(&tokens);
    print_tokenizer(tokens);

	args = tokens_to_args(tokens);
	if (args && args[0])
	{
		exit_status = 0;
		if (execute_builtin(args, &glb_list()->env, &exit_status) == 1)
			printf("Builtin command executed successfully.\n");
		else
		{
			path = get_cmd_path(args[0], glb_list()->env);
			if (!path)
			{
				ft_putstr_fd("minishell: command not found: ", 2);
				ft_putstr_fd(args[0], 2);
				ft_putchar_fd('\n', 2);
				exit_status = 127;
			}
			else
				{
					envp = envlist_to_array(glb_list()->env);
					if (!envp)
					{
						perror("envlist_to_array");
						free(path);
						exit(1);
					}

					if (fork() == 0)
					{
						execve(path, args, envp);
						perror("execve");
						exit(1);
					}
					else
					{
						wait(&exit_status);
					}
					free(path);
					free_strs(envp);
				}
			}
		}
//	print_env(glb_list()->env);
	free_args(args);
	free_tokens(input, tokens);
  }
}
   // t_ast		*ast;
    // ast = ast_builder(tokens);
    // printf("________________NO_THE_TREE_________________");
    // print_node(ast);
    // printf("this is the right \n");
    // print_node(ast->left);
    // printf("this is the left \n");
    // print_node(ast->left);
    // free_all(input, tokens);

