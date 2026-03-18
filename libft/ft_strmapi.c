#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	s_len;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	ptr = malloc(s_len + 1);
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
