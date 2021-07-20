/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_ux_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:44:45 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/19 22:20:05 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static	void	x_identifier(char **str, char *flags, char conversion);
static	void	x_zero_padding(char **str, t_chunk **chunk);
static	void	apply_flags(char **str, t_chunk **chunk);
static	int	is_non_zero(char *str);

void	proc_ux_flags(char **str, t_chunk **chunk)
{
	int		lens[2];

	lens[0] = ft_strlen(*str);
	lens[1] = (*chunk)->width;
	x_identifier(str, (*chunk)->flags, (*chunk)->conversion);
	apply_flags(str, chunk);
}

void	x_identifier(char **str, char *flags, char conversion)
{
	char	*res;
	char	*aux;

	if (is_non_zero(*str))
	{
		if (has_char(flags, '#') && has_char("xX", conversion))
		{
			if (conversion == 'x')
				aux = ft_strdup("0x");
			else
				aux = ft_strdup("0X");
			res = ft_strjoin(aux, *str);
			free(*str);
			*str = res;
			free(aux);
		}
	}
}

void	apply_flags(char **str, t_chunk **chunk)
{
	char	style;
	char	*flags;
	int		width;
	int		i;

	i = 0;
	style = 0;
	flags = (*chunk)->flags;
	width = (*chunk)->width;
	while (flags[i])
		if (flags[i++] == '0' && (*chunk)->precision == -1)
			style = '0';
	i = 0;
	while (flags[i])
		if (flags[i++] == '-')
			style = '-';
	if (style == '0')
		x_zero_padding(str, chunk);
	if (style == '-')
		apply_padding(str, width, 1, ' ');
	if (style == 0)
		apply_padding(str, width, -1, ' ');
}

void	x_zero_padding(char **str, t_chunk **chunk)
{
	char	conversion;
	char	**aux;
	int		l;

	l = 0;
	conversion = (*chunk)->conversion;
	aux = (char **)ft_calloc(2, sizeof(char **));
	if (has_char((*chunk)->flags, '#') && (*chunk)->precision == -1)
	{
		if (is_non_zero(*str))
		{
			aux[0] = ft_substr(*str, 0, 2);
			aux[1] = ft_substr(*str, 2, ft_strlen(*str) - 2);
			free(*str);
			apply_padding(&aux[1], (*chunk)->width - 2, -1, '0');
			*str = ft_strjoin(aux[0], aux[1]);
			free(aux[0]);
			free(aux[1]);
		}
		else
			apply_padding(str, (*chunk)->width, -1, '0');
	}
	else
		apply_padding(str, (*chunk)->width, -1, '0');
	free(aux);
}

int	is_non_zero(char *str)
{
	while (*str)
		if ((char )*(str++) != '0')
			return (1);
	return (0);
}
