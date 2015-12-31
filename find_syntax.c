#include <lexer.h>

static t_type_syntax	apply_special_syntax(t_group_syntax gr, t_syntax stx, int nb_match)
{
	t_type_syntax	type;

	type.group_name = gr.group_name;
	type.name = stx.name;
	type.nb_match = nb_match;
	return (type);
}

static int		is_special_syntax(t_syntax syntax, char *search)
{
	if (!ft_strcmp(":number", syntax.syntax) && !ft_isnan(search))
	{
		return (1);
	}
	if (!ft_strcmp(":string", syntax.syntax) && ft_isword(search))
	{
		return (2);
	}
	return (0);
}

t_type_syntax	find_syntax(t_group_syntax *gr, char *search, int exactly)
{
	t_type_syntax	type;
	t_group_syntax	*tmp;
	t_syntax		*tmp2;

	tmp = gr;
	ft_bzero(&type, sizeof(t_type_syntax));
	//dprintf(1, "find_syntax |%s|\n", search);
	while (tmp)
	{
		tmp2 = tmp->group_syntax;
		while (tmp2)
		{
			if (exactly)
			{
				if (!ft_strcmp(search, tmp2->syntax) || is_special_syntax(*tmp2, search))
				{
					type = apply_special_syntax(*tmp, *tmp2, 1);
	//				dprintf(1, "YES: %s\n", type.name);
					return (type);
				}
			}
			else {
				if (!ft_strncmp(search, tmp2->syntax, ft_strlen(search)))
				{
					type = apply_special_syntax(*tmp, *tmp2, ++type.nb_match);
	//				dprintf(1, "\t%d: %s\n", type.nb_match, tmp2->name);
				}
				if (is_special_syntax(*tmp2, search))
					type = apply_special_syntax(*tmp, *tmp2, -1);
			}
			//if (!ft_strcmp(":number", tmp2->syntax) && !ft_isnan(syntax))
			//{
			//	type.group_name = tmp->group_name;
			//	type.name = tmp2->name;
			//	type.nb_match = 200000;
			//}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	/*
	if (type.nb_match == 1)
		dprintf(1, "-> is maybe %s\n", type.name);
	else if (type.nb_match)
		dprintf(1, "%u match found\n", type.nb_match);
		*/
	return (type);
}
