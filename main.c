#include <lexer.h>

int		main(void)
{
	t_lexer				*lexer;
	t_token				*token;
	char	*str_shell;
	char	*str_f;
	char	*str;

	str_shell = ft_strdup("make && ./lexer ; echo \"iuesrhg\"");
	str_f = ft_strdup("((3+4)/ (-13) + (3 *( 234 - 324) /2)");
	lexer = init_lexer();

//#define SHELL
#define OPERATION

#if defined OPERATION
	str = str_f;
	add_syntax(&lexer, "Operator", "Mulplier", "*");
	add_syntax(&lexer, "Operator", "Addier", "+");
	add_syntax(&lexer, "Operator", "Subbier", "-");
	add_syntax(&lexer, "Operator", "Ratio", "/");

	add_syntax(&lexer, "Sub operator", "Sub Begin", "(");
	add_syntax(&lexer, "Sub operator", "Sub End", ")");

	add_syntax(&lexer, "Comment", "Start comment", "/*");
	add_syntax(&lexer, "Comment", "End comment", "*/");
	add_syntax(&lexer, "Comment", "Single comment 1", "//");
	add_syntax(&lexer, "Comment", "Single comment 2", "##");

	add_syntax(&lexer, "Numbers", "Zero", "0");
	add_syntax(&lexer, "Numbers", "One", "1");
	add_syntax(&lexer, "Numbers", "Two", "2");
	add_syntax(&lexer, "Numbers", "Three", "3");
	add_syntax(&lexer, "Numbers", "Four", "4");
	add_syntax(&lexer, "Numbers", "Five", "5");
	add_syntax(&lexer, "Numbers", "Six", "6");
	add_syntax(&lexer, "Numbers", "Seven", "7");
	add_syntax(&lexer, "Numbers", "Eight", "8");
	add_syntax(&lexer, "Numbers", "Nine", "9");
#endif
#if defined SHELL
	str = str_shell;
	add_syntax(&lexer, "Operator", "And", "&&");
	add_syntax(&lexer, "Operator", "Or", "||");

	add_syntax(&lexer, "Separator", "Next", ";");

	add_syntax(&lexer, "Redirection", "Pipe", "|");
	add_syntax(&lexer, "Redirection", "Redir right", ">");
	add_syntax(&lexer, "Redirection", "Redir doulbe right", ">>");
	add_syntax(&lexer, "Redirection", "Redir left", "<");
	add_syntax(&lexer, "Redirection", "Redir doulbe left", "<<");

	add_syntax(&lexer, "Sub shell", "Sub Begin", "(");
	add_syntax(&lexer, "Sub shell", "Sub End", ")");

	add_syntax(&lexer, "Pair", "Double quote", "\"");
	add_syntax(&lexer, "Pair", "Simple quote", "'");
	add_syntax(&lexer, "Pair", "Hook begin", "[");
	add_syntax(&lexer, "Pair", "Hook end", "]");
	add_syntax(&lexer, "Pair", "Cursh begin", "{");
	add_syntax(&lexer, "Pair", "Cursh end", "}");


#endif
	add_syntax(&lexer, "Ignore", "Space", " ");
	add_syntax(&lexer, "Ignore", "Tabulation", "\t");
	add_syntax(&lexer, "Ignore", "Chariot", "\r");
	add_syntax(&lexer, "Ignore", "Return", "\n");


	show_config(lexer->lexical);

	dprintf(1, "|%s|\n", str);

	dprintf(1, "|%10s-%20s-%20s|\n", "----------", "--------------------", "--------------------");
	token = get_token(&lexer, str);
		dprintf(1, "|%10s|%20s|%20s|\n", "Value", "Name", "Group Name");
		dprintf(1, "|%10s|%20s|%20s|\n", "----------", "--------------------", "--------------------");
	while (token)
	{
		if (!ft_strequ(token->type.group_name, "Ignore"))
			dprintf(1, "|%10s|%20s|%20s|\n", token->value, token->type.name, token->type.group_name);
		token = token->next;
	}
	dprintf(1, "|%10s-%20s-%20s|\n", "----------", "--------------------", "--------------------");


	return (0);
}
