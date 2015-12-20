#include <lexer.h>

void		add_syntax(t_group_syntax **gr, char *group_name, t_syntax *new)
{
	t_group_syntax	*find;

	find = find_group_syntax(*gr, group_name);
	if (!find)
	{
		insert_group_syntax(gr, create_group_syntax(group_name));
		find = *gr;
	}
	LIST_PUSH_FRONT(&find->group_syntax, new);
}

