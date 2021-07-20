/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_d_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:24:55 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/19 21:47:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static	char	pad_flag(char *flags);
static	void	apply_sign(char **str, char *flags, char sign);
static	int	has_sign(char sign, char *flags);

void	proc_d_flags(char **base_number, t_chunk **chunk, char sign)
{
	char	f;
	char	u_size;

	u_size = (*chunk)->width - has_sign(sign, (*chunk)->flags);
	f = pad_flag((*chunk)->flags);
	if (f == '0' && (*chunk)->precision == -1)
	{
		apply_padding(base_number, u_size, -1, '0');
		apply_sign(base_number, (*chunk)->flags, sign);
	}	
	else if (f == '-')
	{
		apply_padding(base_number, u_size, 1, ' ');
		apply_sign(base_number, (*chunk)->flags, sign);
	}
	else
	{
		apply_sign(base_number, (*chunk)->flags, sign);
		apply_padding(base_number, (*chunk)->width, -1, ' ');
	}
}

char	pad_flag(char *flags)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	while (flags[i])
	{
		if (flags[i] == '0')
			c = '0';
		i++;
	}
	i = 0;
	while (flags[i])
	{
		if (flags[i] == '-')
			c = '-';
		i++;
	}
	return (c);
}

void	apply_sign(char **str, char *flags, char sign)
{
	char	*temp;
	char	aux[2];

	temp = NULL;
	if (sign == '-')
		temp = ft_strjoin("-", *str);
	else
	{
		if (has_char(flags, '+'))
		{
			aux[0] = sign;
			aux[1] = 0;
			temp = ft_strjoin((char *)aux, *str);
		}
		else if (has_char(flags, ' '))
			temp = ft_strjoin(" ", *str);
	}
	if (temp)
	{
		free(*str);
		*str = temp;
	}
}

int	has_sign(char sign, char *flags)
{
	if (sign == '-')
		return (1);
	if (has_char(flags, ' ') || has_char(flags, '+'))
		return (1);
	return (0);
}
