/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:05:28 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/07 19:54:25 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux/libaux.h"

int			eval_format(char *str, t_chunk **chunk, va_list args);
static int	eval_simple_s(char *str, t_chunk **chunk);
static int	eval_conv_input(t_chunk *chunk);
static void	eval_argument(t_chunk **chunk, va_list args);
static void	print_chunk(t_chunk **ptr);

int	ft_printf(const char *s, ...)
{
	int		i;
	t_chunk	*chunks;
	va_list args;

	i = 0;
	chunks = NULL;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
			s += eval_format(s, &chunks, args);
		else
			s += eval_simple_s(s, &chunks);
	}
	for_each_chunk(&chunks, print_chunk);
	for_each_chunk(&chunks, free_chunk);
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
	if ((*ptr)->argument != NULL)
		ft_putstr_fd((char *)(*ptr)->argument, 1);
}

void	eval_argument(t_chunk **chunk, va_list args)
{
	int	t;

	if ((*chunk)->flags != NULL)
	{
		t = eval_conv_input(*chunk);
		if ((*chunk)->argument == NULL)
		{
			if (t == 0)
				(*chunk)->argument = va_arg(args, char);
			if (t == 1)
				(*chunk)->argument = res_from_s(va_arg(args, char *), chunk);
			if (t == 2)
				(*chunk)->argument = va_arg(args, int);
			if (t == 3)
				(*chunk)->argument = va_arg(args, unsigned int);
			if (t == 4)
				(*chunk)->argument = va_arg(args, unsigned long);
			if (t == 5)
				(*chunk)->argument = ft_strdup("%");
		}
	}
}

int	eval_conv_input(t_chunk *chunk)
{
	char	c;

	c = (unsigned char)(chunk->conversion);
	if (c == 's')
		return (1);
	if (c == 'c' || c == 'd' || c == 'i')
		return (2);
	if (c == 'u' || c == 'x' || c == 'X')
		return (3);
	if (c == 'p')
		return (4);
	if (c == '%')
		return (5);
	return (0);
}
