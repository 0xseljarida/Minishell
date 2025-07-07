#include "minishell.h"

int	is_operator(char *str)
{
	t_operator	op;

	if (ft_strncmp("<<", str, 2) == 0)
		op = LESS_LESS; //0
	else if (ft_strncmp(">>", str, 2) == 0)
		op = GREAT_GREAT; //1
	else if (ft_strncmp("|", str, 1) == 0)
		op = PIPE; //2
	else if (ft_strncmp("<", str, 1) == 0)
		op = LESS; //3
	else if (ft_strncmp(">", str, 1) == 0)
		op = GREAT; //4
	else if (ft_strncmp("\"", str, 1) == 0)
		op = DOUBLE_QUOTE; //5
	else if (ft_strncmp("\'", str, 1) == 0)
		op = QUOTE; //6
	else
		return (-1);
	return (op);
}

char	*alloc_quote_help(char *str, int *i)
{
	int		len;
	char	*alc_str;
	char	c;

	len = 1;
	c = *str;
	while (str[len] != c)
		len++;
	alc_str = malloc(len + 2);
	ft_strlcpy(alc_str, str, len + 2);
	*i = *i + len;
	return (alc_str);
}

void	print_op(t_operator op, char *str)
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

void	fill_the_node_op(t_tokenizer *node, int op, int i)
{
	node->i = i;
	node->op = op;
	node->str = NULL;
	node->quote_state = -1;
}

void	fill_the_node_str(t_tokenizer *node, int i, char *token,
		t_quote quote_state)
{
	node->i = i;
	node->op = -1; // -1 if it's no an operator 
	node->str = token;
	node->quote_state = quote_state;
}

char	is_quote(char c)
{
	if (c == '\'')
		return ('\'');
	else if (c == '\"')
		return ('\"');
	else 
		return (0);
}