#ifndef LIBAUX_H
# define LIBAUX_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_chunk
{
	void			*argument;
	char			*flags;
	int				width;
	int				precision;
	char			conversion;
	struct s_chunk	*next;
	struct s_chunk	*previous;
}	t_chunk;

t_chunk	*new_chunk(void *arg);
t_chunk	*new_last_chunk(t_chunk **chunk, void *content);
t_chunk	*first_chunk(t_chunk *ptr);
void	for_each_chunk(t_chunk **chunk, void (*f)(t_chunk **));
void	args_iterator(t_chunk **chunk, void (*f)(t_chunk **, va_list),va_list args);
void	free_chunk(t_chunk **str_ptr);
int		eval_flags(t_chunk *chunk, char *str);
int		eval_width(t_chunk *chunk, char *str, va_list args);
int		eval_precision(t_chunk *chunk, char *str, va_list args);
int		eval_conversion(t_chunk *chunk, char *str);
char	*res_from_s(const char *arg,t_chunk **chunk);
char	*eval_s_flags(char *flags,const char *arg,int n);

#endif