#include <lexer.h>

t_type_syntax	find_syntax(t_group_syntax *gr, char *syntax)
{
	t_type_syntax	type;
	t_group_syntax	*tmp;
	t_syntax		*tmp2;

	tmp = gr;
	type.group_name = NULL;
	type.name = NULL;
	while (tmp)
	{
		tmp2 = tmp->group_syntax;
		while (tmp2)
		{
			if (ft_strnequ(syntax, tmp2->syntax, ft_strlen(syntax)))
			{
				type.group_name = tmp->group_name;
				type.name = tmp2->name;
				type.nb_match++;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (type);
}
