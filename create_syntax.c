#include <lexer.h>

t_syntax	*create_syntax(char *name, char *syntax, unsigned int type)
{
	t_syntax	*new;

	new = LIST_NEW(t_syntax);
	new->name = name;
	new->syntax = syntax;
	new->type = type;
	return (new);
}
