#include <liblexer.h>

t_lexer				*init_lexer(void)
{
	t_lexer		*lex;

	lex = (t_lexer *)malloc(sizeof(t_lexer));
	ft_bzero(lex, sizeof(t_lexer));
	add_syntax(&lex, "Ignore", "\\ ", " ");
	add_syntax(&lex, "Ignore", "\\t", "\t");
	add_syntax(&lex, "Ignore", "\\r", "\r");
	add_syntax(&lex, "Ignore", "\\n", "\n");
	return (lex);
}
