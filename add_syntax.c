#include <lexer.h>

void		add_syntax(t_lexical_config **config, char *group_name, t_syntax *new)
{
	t_group_syntax	*find;

	if (!*config)
	{
		*config = (t_lexical_config *)malloc(sizeof(t_lexical_config));
		ft_bzero(*config, sizeof(t_lexical_config));
	}
	find = find_group_syntax((*config)->lexical, group_name);
	if (!find)
	{
		insert_group_syntax(&((*config)->lexical), create_group_syntax(group_name));
		find = (*config)->lexical;
	}
	LIST_PUSH_FRONT(&find->group_syntax, new);
}

