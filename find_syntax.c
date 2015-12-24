#include <lexer.h>

t_type_syntax	find_syntax(t_group_syntax *gr, char *syntax)
{
	t_type_syntax	type;
	t_group_syntax	*tmp;
	t_syntax		*tmp2;

	tmp = gr;
	ft_bzero(&type, sizeof(t_type_syntax));
	while (tmp)
	{
		tmp2 = tmp->group_syntax;
		while (tmp2)
		{
			if (!ft_strncmp(syntax, tmp2->syntax, ft_strlen(syntax)))
			{
				if (!type.exactly)
				{
					type.group_name = tmp->group_name;
					type.name = tmp2->name;
				}
//				dprintf(1, "  |%s| ----> %s\n", syntax, type.name);
				type.nb_match++;
			}
			if (!ft_strcmp(syntax, tmp2->syntax))
				type.exactly = 1;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (type);
}
