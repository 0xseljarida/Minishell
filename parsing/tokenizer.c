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

static int	alloc_quote(char *input, size_t *end)
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

static int	alloc_str(char *input, int *i, t_tokenizer **node, int *node_i)
{
	size_t		end;
	char		*to_alloc;

	end = 0;
	while (input[*i + end] != '\0' && !ft_isspace(input[*i + end])
		&& (is_operator(input + *i + end) == NOT_OP
			|| is_quote(input[*i + end])))
	{
		if ((*i == 0 || ft_isspace(input[*i - 1])) && is_quote(input[*i])
			&& is_quote(input[*i]) == is_quote(input[*i + 1]))
			return (*i + 1);
		if (alloc_quote(input + *i, &end) == 1)
			end--;
		end++;
	}
	if (end == 0)
		return (*i);
	*node = add_node(&((*node)->next));
	to_alloc = ft_substr(input, *i, end);
	fill_the_node_str(*node, *node_i, to_alloc);
	*i = *i + end;
	*node_i += 1;
	return (*i);
}

static int	alloc_operator(int	*i, char *input, t_tokenizer **node
	, int *node_i)
{
	if (!input[*i])
		return (*i);
	if (is_operator(input + *i) < QUOTE)
	{
		*node = add_node(&((*node)->next));
		fill_the_node_op(*node, is_operator(input + *i), *node_i);
		if (is_operator(input + *i) < LESS)
			*i += 1;
		*node_i += 1;
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
		i = alloc_str(input, &i, &node, &node_i);
		i = alloc_operator(&i, input, &node, &node_i);
		if (input[i] == 0)
			break ;
		i++;
	}
	node = head;
	head = head->next;
	free(node);
	return (head);
}
