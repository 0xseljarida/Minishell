#include "minishell.h"

void	print_tokenizer(t_tokenizer *tokens)
{
	int i = 0;
	t_tokenizer	*temp;
	t_here_doc	*tmp;
	temp = tokens;
	printf("_____________________\n");
	while (temp != NULL)
	{
		printf("index : %d\n",temp->i);
		if (temp->op == -1)
		{
			printf("cmd   : %s = %zu\n",temp->str, ft_strlen(temp->str));
			printf("quote : %d\n",temp->quote_state);

		}
		else
		{
			print_op(temp->op);
			if (temp->op == LESS_LESS)
			{
				tmp = temp->hd;
				printf("\n************HERE IS THE HEREDOC**************\n");
				while (tmp != 0)
				{
					printf("%s \n", tmp->str);
					tmp = tmp->next;
				}
			}
		}
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

void	print_op(t_operator op)
{
	if (op == LESS_LESS)
		printf("<<\n");
	else if (op == GREAT_GREAT)
		printf(">>\n");
	else if (op == PIPE)
		printf("|\n");
	else if (op == LESS)
		printf("<\n");
	else if (op == GREAT)
		printf(">\n");
	else if (op == DOUBLE_QUOTE)
		printf("\"\n");
	else if (op == QUOTE)
		printf("\'\n");
	else
		printf("something else");
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
		while (env[i][j] != '=')
			j++;
		env_list->name = ft_substr(env[i], 0, j);
		env_list->value = ft_substr(env[i], j + 1, ft_strlen(env[i]));
		i++;
		if (env[i] != NULL)
			env_list->next = malloc(sizeof(t_env));
		else
			break;
		env_list = env_list->next;
	}
	env_list->next = NULL;
	return (env_head);
}

void	print_env(t_env *env_list)
{
	while(env_list != NULL)
	{
		printf("%s", env_list->name);
		printf("=");
		printf("%s %zu\n", env_list->value, ft_strlen(env_list->value));
		env_list = env_list->next;
	}
}

t_glb 	*glb_list(void)
{
	static t_glb	glb;

	return (&glb);
}
// char *here_doc(char *input)
// {
// 	int	i;
// 	char	*heredoc_input;
// 	char	*temp;

// 	i = 0;
// 	while (input[i])
// 	{
// 		if (is_operator(input + i) == LESS_LESS)
// 		{
// 			heredoc_input = readline("> ");	
// 		}
// 		i++;
// 	}
// }