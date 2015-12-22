#include <lexer.h>

void		add_syntax(t_lexer **lexer, char *group_name, char *name, char *syntax)
{
	t_group_syntax	*find;

	find = find_group_syntax((*lexer)->lexical, group_name);
	if (!find)
	{
		insert_group_syntax(&((*lexer)->lexical), create_group_syntax(group_name));
		find = (*lexer)->lexical;
	}
	LIST_PUSH_FRONT(&find->group_syntax, create_syntax(name, syntax, 0));
}
