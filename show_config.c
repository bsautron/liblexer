#include <liblexer.h>

static t_syntax			*print_name(t_syntax *stx)
{
	ft_putstr(" [");
	ft_putstr(stx->name);
	ft_putstr("]");
	return (stx);
}

static t_syntax			*print_syntax(t_syntax *stx)
{
	ft_putstr(" [");
	ft_putstr(stx->syntax);
	ft_putstr("]");
	return (stx);
}

static t_group_syntax	*print_group(t_group_syntax *gr)
{
	ft_putstr(gr->group_name);
	ft_putstr(":");
	if (!ft_strcmp(gr->group_name, "Ignore"))
		LIST_APPLY(gr->group_syntax, &print_name);
	else
		LIST_APPLY(gr->group_syntax, &print_syntax);
	ft_putchar('\n');
	return (gr);
}

void					show_config(t_group_syntax *lexical)
{
	ft_putendl("\t-- LEXICAL CONFIGURATION --");
	LIST_APPLY(lexical, &print_group);
}
