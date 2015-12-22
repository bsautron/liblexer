#include <lexer.h>

t_token			*get_token(t_lexer **lexer, char *str)
{
	t_token		*tk;
	t_token		*new_tk;

	tk = LIST_NEW(t_token);
	while ((*lexer)->pos < ft_strlen(str))
	{
		new_tk = get_next_token(lexer, str);
		dprintf(1, "'%s'\t%s\n", new_tk->value, new_tk->type.name);
		LIST_PUSH_BACK(&tk, new_tk);
	}
	return (tk);
}
