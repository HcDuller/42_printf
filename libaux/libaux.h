#ifndef LIBAUX_H
# define LIBAUX_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_chunk
{
	void			*argument;
	char			*conversion;
	char			*flags;
	struct s_chunk	*next;
	struct s_chunk	*previous;
}	t_chunk;

t_chunk	*new_chunk(void *arg, char *conversion, char *flags);
void	free_chunk(t_chunk **str_ptr);

#endif