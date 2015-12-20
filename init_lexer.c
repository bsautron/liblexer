#include <lexer.h>

t_lexer				*init_lexer(void)
{
	t_lexer		*lex;

	lex = (t_lexer *)malloc(sizeof(t_lexer));
	ft_bzero(lex, sizeof(t_lexer));
	return (lex);
}
