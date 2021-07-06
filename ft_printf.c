/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:05:28 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/06 18:05:51 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux/libaux.h"

static int	eval_format(char *str, t_chunk **chunk);
static int	eval_simple_s(char *str, t_chunk **chunk);
void	eval_chunk(t_chunk **chunk, va_list args);
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
			s += eval_format(s, &chunks);
		else
			s += eval_simple_s(s, &chunks);
	}
	args_iterator(&chunks, eval_chunk, args);
	for_each_chunk(&chunks, print_chunk);
	for_each_chunk(&chunks, free_chunk);
}

int	eval_format(char *str, t_chunk **chunk)
{
	int	i;

	*chunk = new_last_chunk(chunk, NULL);
	i = 1;
	i += eval_flags(*chunk, str + i);
	i += eval_width(*chunk, str + i);
	i += eval_precision(*chunk, str + i);
	i += eval_conversion(*chunk, str + i);
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

void	eval_chunk(t_chunk **chunk, va_list args)
{
	if ((*chunk)->argument == NULL)
		(*chunk)->argument = va_arg(args, char *);
}