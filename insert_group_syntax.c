#include <lexer.h>

void		insert_group_syntax(t_group_syntax **start, t_group_syntax *new)
{
	LIST_PUSH_FRONT(start, new);
}
