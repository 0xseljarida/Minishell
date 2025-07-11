#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "libft/libft.h"
# define TRUE 1
# define FALSE 2



typedef enum e_operator
{
	LESS_LESS,
	GREAT_GREAT,
	LESS,
	GREAT,
	PIPE,
	QUOTE,
	DOUBLE_QUOTE,
	OR,
	AND,
	CMD,
	WILDCARD,
	NEXT,
}				t_operator;

typedef enum e_quote
{
	NO_SPACE,
	SPACE_BEFORE,
	SPACE_AFTER,
	SPACE_BEFORE_AFTER,
	NO_QUOTE,
	THERES_QUOTE,
}			t_quote;

typedef struct s_expantion
{
	char	*value;
	int		position_i;
	int		start;
	int		end;
	struct s_expantion *next;
}t_expantion;


typedef struct s_tokenizer
{
	int					i;
	char				*str;
	t_quote				quote_state;
	t_operator			op;
	t_expantion			*exp;
	struct s_tokenizer	*next;
}				t_tokenizer;

typedef struct s_redirections
{
	t_operator		type;
	char			*str;
	int				file_fd;
	struct s_redirections	*next;
	
}			t_redirections;

typedef struct s_ast
{
	t_operator 		type;
	t_redirections	*rdc;
	t_tokenizer		*cmd_line;
	char			*cmd;
	struct s_ast	*right;
	struct s_ast	*left;
}				t_ast;

typedef struct s_garbage_collector
{
	t_ast			*tree_node;
	t_tokenizer		*token;
	t_redirections	*rdc;

}				t_garbage_collector;

typedef struct s_env
{
	char	*name;
	char	*value;	
	struct s_env *next; 

}t_env;

typedef struct s_glb
{
	t_ast			*ast;
	t_env			*env;
	t_tokenizer		*tokens;
	t_redirections	*rdr;
}t_glb;

/* PRINT */
t_glb	*glb_list(void);
void	print_env(t_env *env_list);
void	print_node(t_ast	*ast);
void	print_tree(t_ast	*ast);
void	print_tokenizer(t_tokenizer *tokens);
void	print_op(t_operator op, char *str);

/* FREE_EXIT*/
extern t_garbage_collector		*g_free;
void	free_all(char *input, t_tokenizer *tokens);
void	save_garbage(char **tokens, int is_arr);
t_env 	*save_env(char **env);

/* TOKENIZER */
int		is_operator(char *str);
char	*alloc_quote_help(char *str, int *i);
void	fill_the_node_str(t_tokenizer *node, int i, char *token, t_quote quote_state);
void	fill_the_node_op(t_tokenizer *node, int op, int i);
t_tokenizer *tokenizer(char *input);
void expanding(t_tokenizer *token);
char	is_quote(char c);
char *check_env(char *str, t_env *env);
/* AST_ PASRER */
t_ast	*ast_builder(t_tokenizer *token);
#endif
