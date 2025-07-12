#include "../minishell.h"

int main(int ac, char **av, char **env)
{
	int i = 0;
	int j = 0;	
	char *input;
	while (i < 3)
	{
		input = readline("hello : ");
		printf("%s",input);
		i++;
	}
	free(input);
}
