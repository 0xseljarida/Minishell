#include "minishell.h"

static t_tokenizer	*add_node(t_tokenizer **node)
{
	*node = malloc(sizeof(t_tokenizer));
	if (*node == NULL)
	{
		exit(0);
	}
	(*node)->next = NULL;
	return (*node);
}

int	alloc_quote(char *input, size_t *end)
{
	int	bl;

	bl = 0;
	while (is_quote(input[*end]))
	{
		*end += 1;
		while (is_quote(input[*end]) == 0)
			*end += 1;
		*end += 1;
		bl = 1;
	}
	return (bl);
}

static int	alloc_str(char *input, int *i, t_tokenizer **node, int node_i)
{
	size_t		end;
	char		*to_alloc;

	end = 0;
	while (input[*i + end] != '\0' && input[*i + end] != ' '
		&& (is_operator(input + *i + end) == -1 || is_quote(input[*i + end])))
	{
		if (alloc_quote(input + *i, &end))
			end--;
		end++;
	}
	if (end == 0)
		return (*i);
	*node = add_node(&((*node)->next));
	to_alloc = ft_substr(input, *i, end);
	fill_the_node_str(*node, node_i, to_alloc, -1);
	*i = *i + end;
	return (*i);
}

static int	alloc_operator(int	*i, char *input, t_tokenizer **node, int node_i)
{
	if (!input[*i])
		return (*i);
	if (is_operator(input + *i) < QUOTE && is_operator(input + *i) > -1)
	{
		*node = add_node(&((*node)->next));
		fill_the_node_op(*node, is_operator(input + *i), node_i);
		if (is_operator(input + *i) < LESS)
			*i += 1;
	}
	return (*i);
}

t_tokenizer	*tokenizer(char *input)
{
	t_tokenizer	*head;
	t_tokenizer	*node;
	int			i;
	int			node_i;

	i = 0;
	node_i = 0;
	head = add_node(&node);
	while (input[i])
	{
		if (input[i] == ' ')
		{
			i++;
			continue ;
		}
		i = alloc_str(input, &i, &node, node_i);
		// i = alloc_quote(i, input, &node, node_i);
		i = alloc_operator(&i, input, &node, node_i);
		if (input[i] == 0)
			break ;
		i++;
		node_i++;
	}
	//node->next = NULL;
	node = head;
	head = head->next;
	free(node);
	return (head);
}
/*
static int	alloc_quote(int i, char *input, t_tokenizer **node, int node_i)
{
	char	*to_alloc;
	t_quote	quote_state;

	if (!input[i])
		return (i);
	quote_state = -1;
	if (is_operator(input + i) == DOUBLE_QUOTE
		|| is_operator(input + i) == QUOTE)
	{
		if (is_operator(input + i) == is_operator(input + i + 1))
		{
			return (i + 1);		
		}
		*node = add_node(&((*node)->next));
		if (i != 0 && input[i - 1] == ' ')
			quote_state = SPACE_BEFORE;
		to_alloc = alloc_quote_help(input + i, &i);
		if (input[i + 1] == ' ' && quote_state != -1)
			quote_state = SPACE_BEFORE_AFTER;
		else if (input[i + 1] == ' ' && quote_state == -1)
			quote_state = SPACE_AFTER;
		else if (input[i + 1] != ' ' && quote_state == -1)
			quote_state = NO_SPACE;
		fill_the_node_str(*node, node_i, to_alloc, quote_state);
	}
	return (i);
}
*/