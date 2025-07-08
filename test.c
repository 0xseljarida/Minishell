#include "minishell.h"

int main(int ac, char **av, char **env)
{
	int i = 0;
	int j = 0;	
	while (env[i] != 0)
	{
		printf("%s\n", env[i]);
		i++;
	}
}