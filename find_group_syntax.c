#include <liblexer.h>

t_group_syntax	*find_group_syntax(t_group_syntax *gr, char *name)
{
	t_group_syntax	*tmp;

	tmp = gr;
	while (tmp)
	{
		if (ft_strequ(tmp->group_name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
