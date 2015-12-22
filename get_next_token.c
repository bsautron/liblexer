#include <lexer.h>

t_token			*get_next_token(t_lexer **lexer, char *str)
{
	t_token			*current;
	t_type_syntax	type_char;
	t_type_syntax	type;
	char			c[2];
	char			bre;
	int				matched_befor;

	(void)bre;
	current = LIST_NEW(t_token);
	matched_befor = 0;
	while (0101010)
	{
		sleep(0);
		c[1] = 0;
		c[0] = str[(*lexer)->pos];
		current->value[current->len++] = c[0];
		type = find_syntax((*lexer)->lexical, current->value);
		type_char = find_syntax((*lexer)->lexical, c);
		//dprintf(1, "str\t[%s]: %s\t%u matched\n", current->value, type.name, type.nb_match);
		//dprintf(1, "char\t'%s': %s\t%u matched\n", c, type_char.name, type_char.nb_match);

		if (matched_befor && type.nb_match == 0 && type_char.nb_match == 0)
		{
			current->value[--current->len] = 0;
			current->type = find_syntax((*lexer)->lexical, current->value);
			return (current);
		}
		if (type.nb_match == 1)
		{
			(*lexer)->pos++;
			current->type = type;
			return (current);
		}
		if (type_char.nb_match > 0 && type.nb_match == 0)
		{
			current->value[--current->len] = 0;
			current->type = type;
			return (current);
		}
		else
		{
			// do nothing
		}

		if (type.nb_match > 0)
			matched_befor = 1;
		if (!c[0])
			return (current);
		(*lexer)->pos++;
	}
	return (current);
}
