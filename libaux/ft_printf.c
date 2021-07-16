/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:05:28 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/16 18:43:57 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

int			eval_format(char *str, t_chunk **chunk, va_list args);
static int	eval_simple_s(char *str, t_chunk **chunk);
static void	eval_argument(t_chunk **chunk, va_list args);
static int	print_list(t_chunk *ptr);

int	ft_printf(const char *s, ...)
{
	int		i;
	t_chunk	*chunks;
	va_list	args;

	i = 0;
	chunks = NULL;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			i += eval_format((char *)&s[i], &chunks, args);
		else
			i += eval_simple_s((char *)&s[i], &chunks);
	}
	i = print_list(chunks);
	for_each_chunk(&chunks, free_chunk);
	va_end(args);
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
				p = input_is_char_p("%", chunk);
			else
				p = ft_calloc(1, sizeof(char));
			(*chunk)->argument = p;
		}
	}
}

int	print_list(t_chunk *ptr)
{
	int	sizes[2];

	sizes[0] = 0;
	sizes[1] = 0;
	while (ptr->previous != NULL)
		ptr = ptr->previous;
	while (ptr->next != NULL)
	{
		if (ptr->conversion == 'c')
			sizes[0] = ptr->width;
		else
			sizes[0] = ft_strlen(ptr->argument);
		write(1, ptr->argument, sizes[0]);
		sizes[1] += sizes[0];
		ptr = ptr->next;
	}
	if (ptr->conversion == 'c')
		sizes[0] = ptr->width;
	else
		sizes[0] = ft_strlen(ptr->argument);
	write(1, ptr->argument, sizes[0]);
	sizes[1] += sizes[0];
	return (sizes[1]);
}
