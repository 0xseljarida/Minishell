#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	list_length;

	list_length = 0;
	while (lst)
	{
		list_length++;
		lst = lst->next;
	}
	return (list_length);
}
