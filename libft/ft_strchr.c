#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *) s);
		s++;
	}
	if ((char)c == *s)
		return ((char *) s);
	return (0);
}
