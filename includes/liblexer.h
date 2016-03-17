#ifndef LIBLEXER_H
# define LIBLEXER_H

# include <stdio.h>
# include <libft.h>
# include <liblist.h>

enum			e_type_char
{
	CHAR_NULL,
	CHAR_DIGIT,
	CHAR_APLHA,
	CHAR_OPERATOR,
	CHAR_WHITE_SPACE,
	CHAR_OTER,
	CHAR_IGNORE
}				e_type_char;

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

typedef struct	s_type_syntax
{
	char			*group_name;
	char			*name;
	unsigned int	nb_match;
	int				exactly;
}				t_type_syntax;

typedef struct	s_token
{
	void			*next;
	char			value[128];
	unsigned int	len;
	t_type_syntax	type;
}				t_token;

typedef struct	s_lexer
{
	t_group_syntax	*lexical;
	unsigned int	pos;
}				t_lexer;



t_group_syntax		*create_group_syntax(char *name);
t_group_syntax		*find_group_syntax(t_group_syntax *gr, char *name);
void				insert_group_syntax(t_group_syntax **gr, t_group_syntax *new);
t_syntax			*create_syntax(char *name, char *syntax, unsigned int type);

void				add_syntax(t_lexer **lexer, char *group_name, char *name, char *syntax);
void				show_config(t_group_syntax *lexical);

t_lexer				*init_lexer(void);
t_token				*get_token(t_lexer **lexer, char *str);
t_token				*get_next_token(t_lexer **lexer, char *str);

t_type_syntax		find_syntax(t_group_syntax *gr, char *syntax, int exactly);

#endif
