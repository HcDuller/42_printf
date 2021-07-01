#ifndef LIBAUX_H
#define LIBAUX_H

#include <stddef.h>

typedef struct str_chunk
{
	void				*argument;
	char				*conversion;
	char				*flags;
	struct str_chunk	*next;
	struct str_chunk	*previous;
} str_chunk;

str_chunk *new_chunk(void *arg, char *conversion, char *flags);

#endif