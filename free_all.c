#include "minishell.h"

void    free_all(char *input, t_tokenizer *tokens)
{
	t_tokenizer	*temp;
	// int     i;
    //t_garbage_collector *tmp;
    // char    **temp;
    // while (g_free != NULL)
    // {
    //     if (g_free->is_arrof_p == 1)
    //     {
    //         temp = g_free->d_content;
    //         i = 0;
    //         while (temp[i] != 0)
    //         {
    //             free(temp[i]);
    //             i++;
    //         }
    //         free(temp);
    //     }
    //     else
    //         free(g_free->content);
    //     tmp = g_free;
    //     g_free = g_free->next;
    //     free(tmp);
    // }
    void        *tmp;
    t_env       *env;

	while (tokens != NULL)
	{
        if (tokens->op == LESS_LESS)
        {
           while (tokens->hd != NULL)
            {
                free(tokens->hd->str);
                tmp = tokens->hd; 
                tokens->hd = tokens->hd->next;
                free(tmp);
            }
        }
		free(tokens->str);
        temp = tokens;
		tokens = tokens->next;
        free(temp);

	}
    free(input);

    env = glb_list()->env;
    while (env != NULL)
    {
        free(env->name);
        free(env->value);
        tmp = env;
        env = env->next;
        free(tmp);
    }
}
