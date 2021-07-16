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
void	free_chunk(t_chunk **str_ptr);
int		eval_flags(t_chunk *chunk, char *str);
int		eval_width(t_chunk *chunk, char *str, va_list args);
int		eval_precision(t_chunk *chunk, char *str, va_list args);
int		eval_conversion(t_chunk *chunk, char *str);
char	*input_is_char_p(const char *arg, t_chunk **chunk);
char	*input_is_int(int arg, t_chunk **chunk);
char	*input_is_uint(unsigned int n, t_chunk **chunk);
char	*input_is_ulong(unsigned long add, t_chunk **chunk);
char	*proc_s_flags(char *flags, const char *arg, int n);
char	*proc_d_flags(char **base_number, t_chunk **chunk, char sign);
void	proc_ux_flags(char **str, t_chunk **chunk);
void	proc_p_flags(char **str, t_chunk **chunk);
char	*res_from_d(int arg, t_chunk **chunk);
char	*res_from_c(int arg, t_chunk **chunk);
void	apply_padding(char **str, int size, int side, char c);
int		ft_printf(const char *s, ...);

#endif