#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s && s)
	{
		write(fd, s, 1);
		s++;
	}
}
