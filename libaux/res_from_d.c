/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_from_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:16:30 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/16 18:49:23 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static	char	*sign_agnostic_uitoa(int n, int precision);
static	int	available_digits(int n);
static	int	mod(int n);

char	*res_from_d(int arg, t_chunk **chunk)
{
	char	*p;
	char	sign;

	if (arg >= 0)
		sign = '+';
	else
		sign = '-';
	p = sign_agnostic_uitoa(arg, (*chunk)->precision);
	proc_d_flags(&p, chunk, sign);
	return (p);
}

char	*sign_agnostic_uitoa(int n, int precision)
{
	int		i;
	char	*r;

	if (!n && !precision)
		return (ft_calloc(1,sizeof(char)));
	i = available_digits(n);
	if (precision > i)
		i = precision;
	r = ft_calloc(i + 1, sizeof(char));
	while (i > 0)
	{
		r[i-- - 1] = (unsigned char)(mod(n % 10) + 48);
		n = n / 10;
	}
	return (r);
}

int	available_digits(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	mod(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}
