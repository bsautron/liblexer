#include <lexer.h>

int		main(void)
{
	t_lexer				*lexer;
	t_token				*token;
	char	*str;

	str = ft_strdup("///////////");
	lexer = init_lexer();


	add_syntax(&lexer, "Operator", "Mulplier", "*");
	add_syntax(&lexer, "Operator", "Addier", "+");
	add_syntax(&lexer, "Operator", "Subbier", "-");
	add_syntax(&lexer, "Operator", "Ratio", "/");

	add_syntax(&lexer, "Sub operator", "Sub Begin", "(");
	add_syntax(&lexer, "Sub operator", "Sub End", ")");

	add_syntax(&lexer, "Separator", "Space", " ");
	add_syntax(&lexer, "Separator", "Tabulation", "\\t");
	add_syntax(&lexer, "Separator", "Chariot", "\\r");
	add_syntax(&lexer, "Separator", "Return", "\\n");

	add_syntax(&lexer, "Comment", "Start comment", "/*");
	add_syntax(&lexer, "Comment", "End comment", "*/");
	add_syntax(&lexer, "Comment", "Single comment 1", "//");
	add_syntax(&lexer, "Comment", "Single comment 2", "##");

	show_config(lexer->lexical);

	dprintf(1, "%s\n", str);

	token = get_token(&lexer, str);

	return (0);
}
