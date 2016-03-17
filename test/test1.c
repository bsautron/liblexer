#include <liblexer.h>

int test1(void)
{
  printf("test1 ");
  t_lexer				*lexer;
  char          *str = "#-##--";

  lexer = init_lexer();

  char *tab[5][3] = {
    {"Write", "Word", ":string"},
    {"Write", "Number", ":number"},
    {"Other", "Hashtag", "#"},
    {"Other", "Tiret", "-"},
    {"Comment", "Single", "##"}
  };

  for (int i = 0; i < 5; i++)
    add_syntax(&lexer, tab[i][0], tab[i][1], tab[i][2]);

  t_token     *tk = get_token(&lexer, str);

  int i = 0;
  while (tk)
  {
    if (i == 0 && !(ft_strequ(tk->value, "#") && ft_strequ(tk->type.group_name, "Other") && ft_strequ(tk->type.name, "Hashtag")))
      return (0);
    if (i == 1 && !(ft_strequ(tk->value, "-") && ft_strequ(tk->type.group_name, "Other") && ft_strequ(tk->type.name, "Tiret")))
      return (0);
    if (i == 2 && !(ft_strequ(tk->value, "##") && ft_strequ(tk->type.group_name, "Comment") && ft_strequ(tk->type.name, "Single")))
      return (0);
    if (i == 3 && !(ft_strequ(tk->value, "-") && ft_strequ(tk->type.group_name, "Other") && ft_strequ(tk->type.name, "Tiret")))
      return (0);
    if (i == 4 && !(ft_strequ(tk->value, "-") && ft_strequ(tk->type.group_name, "Other") && ft_strequ(tk->type.name, "Tiret")))
      return (0);
    i++;
    tk = tk->next;
  }
  return (1);
}
