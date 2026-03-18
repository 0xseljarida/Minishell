#include "../includes/minishell.h"

void	*gc_alloc(size_t size)
{
	void	*ptr;
	t_list	*new_node;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(ptr);
		return (NULL);
	}
	new_node->content = ptr;
	new_node->next = NULL;
	ft_lstadd_back(&glb_list()->gc, new_node);
	return (ptr);
}

void	gc_free_all(void)
{
	t_list	*tmp;

	while (glb_list()->gc)
	{
		tmp = glb_list()->gc->next;
		free(glb_list()->gc->content);
		glb_list()->gc->content = NULL;
		free(glb_list()->gc);
		glb_list()->gc = NULL;
		glb_list()->gc = tmp;
	}
}
