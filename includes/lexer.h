#ifndef LEXER_H
# define LEXER_H

#include <stdio.h>
# include <libft.h>
# include <token.h>

typedef struct	s_syntax
{
	void			*next;
	char			*name;
	char			*syntax;
	unsigned int	type;
}				t_syntax;

typedef struct	s_group_syntax
{
	void			*next;
	char			*group_name;
	t_syntax		*group_syntax;
}				t_group_syntax;

typedef struct	s_lexer
{
	t_token			*tk;
	unsigned int	len;
}				t_lexer;

t_lexer		*init_lexer(void);

t_group_syntax		*create_group_syntax(char *name);
t_group_syntax		*find_group_syntax(t_group_syntax *gr, char *name);
void				insert_group_syntax(t_group_syntax **gr, t_group_syntax *new);
t_syntax			*create_syntax(char *name, char *syntax, unsigned int type);

void				add_syntax(t_group_syntax **gr, char *group_name, t_syntax *new);

#endif
