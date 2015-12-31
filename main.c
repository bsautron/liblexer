#include <lexer.h>

int		main(void)
{
	t_lexer				*lexer;
	t_token				*token;
	char				*str = "-#       --##34Ou##i jai 20 ans";

	lexer = init_lexer();

	add_syntax(&lexer, "Write", "Word", ":string");
	add_syntax(&lexer, "Write", "Number", ":number");
	add_syntax(&lexer, "Other", "Hashtag", "#");
	add_syntax(&lexer, "Other", "Tiret", "-");
	add_syntax(&lexer, "Comment", "Single", "##");


	show_config(lexer->lexical);

	dprintf(1, "Str: |%s|\n\n", str);

	token = get_token(&lexer, str);
	dprintf(1, "|%10s-%20s-%20s|\n", "----------", "--------------------", "--------------------");
		dprintf(1, "|%10s|%20s|%20s|\n", "Value", "Name", "Group Name");
		dprintf(1, "|%10s|%20s|%20s|\n", "----------", "--------------------", "--------------------");
	while (token)
	{
		dprintf(1, "|%10s|%20s|%20s|\n", token->value, token->type.name, token->type.group_name);
		token = token->next;
	}
	dprintf(1, "|%10s-%20s-%20s|\n", "----------", "--------------------", "--------------------");

	return (0);
}
