#include <liblexer.h>

t_group_syntax	*create_group_syntax(char *name)
{
	t_group_syntax	*new;

	new = LIST_NEW(t_group_syntax);
	new->group_name = ft_strdup(name);
	return (new);
}
