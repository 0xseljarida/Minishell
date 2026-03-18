#include "libft.h"

int	ft_atoi(const char *a)
{
	int	dec;
	int	sign;

	sign = 1;
	dec = 0;
	while (*a == ' ' || (*a >= 9 && *a <= 13))
		a++;
	if (*a == '-')
	{
		sign = -1;
		a++;
	}
	else if (*a == '+')
		a++;
	while (ft_isdigit(*a))
	{
		dec *= 10;
		dec += *(a++) - '0';
	}
	return (sign * dec);
}
