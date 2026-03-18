#include "minishell.h"

void	clean_exit(int i)
{
	gc_free_all();
	free_env(glb_list()->env);
	exit(i);
}
