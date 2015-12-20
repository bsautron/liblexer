#include <lexer.h>

t_syntax		*print_syntax(t_syntax *stx)
{
	ft_putstr(" [");
	ft_putstr(stx->name);
	ft_putstr("]");
	return (stx);
}

t_group_syntax	*print_group(t_group_syntax *gr)
{
	ft_putstr(gr->group_name);
	ft_putstr(":");
	LIST_APPLY(gr->group_syntax, &print_syntax);
	ft_putchar('\n');
	return (gr);
}

int		main(void)
{
	t_group_syntax	*root;

	root = NULL;
	//insert_group_syntax(&root, create_group_syntax("Comment"));
	//insert_group_syntax(&root, create_group_syntax("Starting"));
	//insert_group_syntax(&root, create_group_syntax("Ending"));

	add_syntax(&root, "Default", create_syntax("*", "Mulplier", 1));
	add_syntax(&root, "Default", create_syntax("+", "Addier", 2));
	add_syntax(&root, "Default", create_syntax("-", "Subbier", 2));
	add_syntax(&root, "Default", create_syntax("/", "Ratio", 2));
	add_syntax(&root, "Separator", create_syntax(" ", "Sapce", 0));
	add_syntax(&root, "Separator", create_syntax("\\t", "Tabulation", 0));
	add_syntax(&root, "Separator", create_syntax("\\r", "Chariot", 0));
	add_syntax(&root, "Comment", create_syntax("/*", "Start comment", 3));
	add_syntax(&root, "Comment", create_syntax("*/", "End comment", 4));

	//LIST_PUSH_BACK(&root->group_syntax, mult);
	//LIST_PUSH_BACK(&root->group_syntax, plus);

	LIST_APPLY(root, &print_group);

	return (0);
}
