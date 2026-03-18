#include "libft.h"

void	*ft_calloc(size_t ne, size_t size)
{
	void	*ptr;

	ptr = malloc(ne * size);
	if (ptr)
		ft_bzero(ptr, size * ne);
	return (ptr);
}
