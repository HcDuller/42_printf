#ifndef LIBAUX_H
# define LIBAUX_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_chunk
{
	void			*argument;
	char			*flags;
	int				width;
	int				precision;
	char			*conversion;
	struct s_chunk	*next;
	struct s_chunk	*previous;
}	t_chunk;

t_chunk	*new_chunk(void *arg);
void	free_chunk(t_chunk **str_ptr);
int		eval_flags(t_chunk *chunk, char *str);

#endif