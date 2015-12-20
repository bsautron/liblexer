#ifndef TOKEN_H
# define TOKEN_H

# include <libft.h>

// set this config
typedef enum	e_type_tk
{
	DEFAULT,
	TK1,
	TK2,
	TK3,
	TK4
}				t_type_tk;

typedef struct	s_token
{
	void		*next;
	char		*data;
	t_type_tk	type;
}				t_token;


#endif
