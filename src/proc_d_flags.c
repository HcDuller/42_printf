/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_d_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:12:32 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/14 19:47:27 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static	char	sign_flag(char *flags);
static	char	pad_flag(char *flags);

char	*proc_d_flags(char **base_number, t_chunk **chunk, char sign)
{
	char	*p;
	char	f[2];

	f[0] = pad_flag((*chunk)->flags);
	f[1] = sign_flag((*chunk)->flags);
	if (f[0] == '0')
		apply_padding(base_number, (*chunk)->width, -1, '0');
	else if (f[0] == '-')
		apply_padding(base_number, (*chunk)->width, 1, ' ');
	if (sign == '-')
		apply_padding(base_number, ft_strlen(*base_number) + 1, -1, '-');
	else
	{
		if (f[1] == ' ')
			apply_padding(base_number, ft_strlen(*base_number) + 1, 1, ' ');
		else if (f[1] == '+')
			apply_padding(base_number, ft_strlen(*base_number) + 1, 1, '+');
	}
	return (p);
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
	while (flags[i])
	{
		if (flags[i] == '-')
			c = '-';
		i++;
	}
	return (c);
}

char	sign_flag(char *flags)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	while (flags[i])
	{
		if (flags[i] == ' ')
			c = ' ';
		i++;
	}
	while (flags[i])
	{
		if (flags[i] == '+')
			c = '+';
		i++;
	}
	return (c);
}
