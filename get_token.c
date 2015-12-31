#include <lexer.h>

t_token			*get_token(t_lexer **lexer, char *str)
{
	t_token		*tk;
	t_token		*new_tk;

	tk = NULL;
	while ((*lexer)->pos < ft_strlen(str))
	{
		new_tk = get_next_token(lexer, str);
		if (!new_tk->type.name)
		{
			dprintf(1, "%s: %s\n", "Unexepted token", new_tk->value);
			exit(1);
		}
		if (ft_strcmp(new_tk->type.group_name, "Ignore"))
		{
			dprintf(1, "-ADD: '%10s'%10s\n", new_tk->value, new_tk->type.name);
			LIST_PUSH_BACK(&tk, new_tk);
		}
	}
	return (tk);
}
