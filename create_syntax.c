#include <liblexer.h>

t_syntax	*create_syntax(char *name, char *syntax, unsigned int type)
{
	t_syntax	*new;

	new = LIST_NEW(t_syntax);
	new->name = ft_strdup(name);
	new->syntax = ft_strdup(syntax);
	new->type = type;
	return (new);
}
