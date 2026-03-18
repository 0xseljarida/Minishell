#include "minishell.h"

int	is_name_char(int c)
{
	return (ft_isalnum(c) || c == '_');
}

int	heredoc_delimiter_is_quoted(t_tokenizer *delim_tok)
{
	if (!delim_tok)
		return (0);
	if (delim_tok->redirect.qt == THERES_QUOTE)
		return (1);
	return (0);
}
