#include "minishell.h"

void	print_tokenizer(t_tokenizer *tokens)
{
	int i = 0;
	t_tokenizer	*temp;

	temp = tokens;
	printf("_____________________\n");
	while (temp != NULL)
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
		printf("\n_________PIPE____________\n");
	print_tokenizer(ast->cmd_line);
}

t_env	*save_env(char **env)
{
	t_env	*env_list;
	t_env	*env_head;
	int		i;
	int		j;

	i = 0;
	env_head = malloc(sizeof(t_env));
	env_list = env_head;
	while (env[i] != 0)	
	{
		j = 0;
		if (env_head == NULL)
			env_head = env_list;
		while (env[i][j] != '=')
			j++;
		env_list->name = ft_substr(env[i], 0, j);
		env_list->value = ft_substr(env[i], j + 1, ft_strlen(env[i]));
		i++;
		if (env[i] == 0)
			env_list->next = malloc(sizeof(t_env));
		env_list = env_list->next;
	}
		printf("%s\n",env_head->name);
		printf("%s \n",env_head->value);
	env_list = NULL;
	return (env_head);
}