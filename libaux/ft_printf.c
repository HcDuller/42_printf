/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:05:28 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/16 13:11:13 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

int			eval_format(char *str, t_chunk **chunk, va_list args);
static int	eval_simple_s(char *str, t_chunk **chunk);
static void	eval_argument(t_chunk **chunk, va_list args);
static void	print_chunk(t_chunk **ptr);

int	ft_printf(const char *s, ...)
{
	int		i;
	char	*p;
	t_chunk	*chunks;
	va_list	args;

	i = 0;
	chunks = NULL;
	p = ft_strdup(s);
	va_start(args, s);
	while (p[i])
	{
		if (p[i] == '%')
			i += eval_format(&p[i], &chunks, args);
		else
			i += eval_simple_s(&p[i], &chunks);
	}
	free(p);
	for_each_chunk(&chunks, print_chunk);
	for_each_chunk(&chunks, free_chunk);
	return (i);
}

int	eval_format(char *str, t_chunk **chunk, va_list args)
{
	int	i;

	*chunk = new_last_chunk(chunk, NULL);
	i = 1;
	i += eval_flags(*chunk, str + i);
	i += eval_width(*chunk, str + i, args);
	i += eval_precision(*chunk, str + i, args);
	i += eval_conversion(*chunk, str + i);
	eval_argument(chunk, args);
	return (i);
}

int	eval_simple_s(char *str, t_chunk **chunk)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
	{
		i++;
	}
	if (i > 0)
	{
		*chunk = new_last_chunk(chunk, ft_substr(str, 0, i));
	}
	return (i);
}

void	print_chunk(t_chunk **ptr)
{
	if ((*ptr)->conversion == 'c')
	{
		write(1, (*ptr)->argument, (*ptr)->width);
		return ;
	}
	if ((*ptr)->argument != NULL)
		ft_putstr_fd((char *)(*ptr)->argument, 1);
}

void	eval_argument(t_chunk **chunk, va_list args)
{
	char	c;
	char	*p;

	if ((*chunk)->flags != NULL)
	{
		c = (unsigned char)((*chunk)->conversion);
		if ((*chunk)->argument == NULL)
		{
			if (c == 's')
				p = input_is_char_p(va_arg(args, char *), chunk);
			else if (c == 'c' || c == 'd' || c == 'i')
				p = input_is_int(va_arg(args, int), chunk);
			else if (c == 'u' || c == 'x' || c == 'X')
				p = input_is_uint(va_arg(args, unsigned int), chunk);
			else if (c == 'p')
				p = input_is_ulong(va_arg(args, unsigned long), chunk);
			else if (c == '%')
				p = ft_strdup("%");
			else
				p = ft_calloc(1, sizeof(char));
			(*chunk)->argument = p;
		}
	}
}
