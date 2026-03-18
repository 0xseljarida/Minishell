#include "libft.h"
#include "../includes/minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = gc_alloc(s1_len + s2_len + 1);
	if (!ptr)
		return (0);
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	i = -1;
	while (s2[++i])
		ptr[s1_len + i] = s2[i];
	ptr[s1_len + s2_len] = 0;
	return (ptr);
}
