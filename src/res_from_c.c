/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_from_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:32:48 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/12 15:34:50 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static	int	proc_c_flags(char *flags);

char	*res_from_c(int arg, t_chunk **chunk)
{
	char	*r;
	int		i;

	i = 0;
	if ((*chunk)->width > 1)
	{
		r = ft_calloc((*chunk)->width + 1, sizeof(char));
		while (i < (*chunk)->width)
			r[i++] = ' ';
		if (proc_c_flags((*chunk)->flags))
			r[0] = (unsigned char)arg;
		else
			r[(*chunk)->width - 1] = (unsigned char)arg;
	}
	else
	{
		r = ft_calloc(2, sizeof(char));
		r[0] = (unsigned char)arg;
	}
	return (r);
}

int	proc_c_flags(char *flags)
{
	int	i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '-')
			return (1);
		i++;
	}
	return (0);
}
