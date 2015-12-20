#include <lexer.h>

static t_syntax			*print_syntax(t_syntax *stx)
{
	ft_putstr(" [");
	ft_putstr(stx->name);
	ft_putstr("]");
	return (stx);
}

static t_group_syntax	*print_group(t_group_syntax *gr)
{
	ft_putstr(gr->group_name);
	ft_putstr(":");
	LIST_APPLY(gr->group_syntax, &print_syntax);
	ft_putchar('\n');
	return (gr);
}

void					show_config(t_lexical_config *config)
{
	ft_putendl("\tLEXICAL CONFIGURATION");
	LIST_APPLY(config->lexical, &print_group);
}
