#include <lexer.h>

int		main(void)
{
	t_lexical_config	*config;

	config = NULL;

	add_syntax(&config, "Default", create_syntax("*", "Mulplier", 1));
	add_syntax(&config, "Default", create_syntax("+", "Addier", 2));
	add_syntax(&config, "Default", create_syntax("-", "Subbier", 2));
	add_syntax(&config, "Default", create_syntax("/", "Ratio", 2));
	add_syntax(&config, "Separator", create_syntax(" ", "Sapce", 0));
	add_syntax(&config, "Separator", create_syntax("\\t", "Tabulation", 0));
	add_syntax(&config, "Separator", create_syntax("\\r", "Chariot", 0));
	add_syntax(&config, "Comment", create_syntax("/*", "Start comment", 3));
	add_syntax(&config, "Comment", create_syntax("*/", "End comment", 4));

	show_config(config);
	return (0);
}
