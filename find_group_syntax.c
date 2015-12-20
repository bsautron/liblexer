#include <lexer.h>

t_group_syntax	*find_group_syntax(t_group_syntax *gr, char *name)
{
	while (gr)
	{
		if (ft_strequ(gr->group_name, name))
			return (gr);
		gr = gr->next;
	}
	return (NULL);
}
