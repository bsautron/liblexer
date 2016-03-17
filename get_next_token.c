#include <liblexer.h>

//function push
//function pop

t_token			*get_next_token(t_lexer **lexer, char *str)
{
	t_token			*current;
	t_type_syntax	type;
	char			c[2];
	int				matched_befor;

	current = LIST_NEW(t_token);
	matched_befor = 0;
	c[1] = 0;
	while ((c[0] = str[(*lexer)->pos]))
	{
		current->value[current->len++] = c[0];
		type = find_syntax((*lexer)->lexical, current->value, 0);
		if (type.nb_match == 1)
		{
			current->type = type;
			(*lexer)->pos++;
			return (current);
		}
		if (type.nb_match == 0 && current->len > 1)
		{
			current->value[--current->len] = 0;
			current->type = find_syntax((*lexer)->lexical, current->value, 1);
			return (current);
		}
		if (type.nb_match == 0 && current->len == 1)
			return (current);
		(*lexer)->pos++;
	}
	current->type = find_syntax((*lexer)->lexical, current->value, 1);
	return (current);
}
