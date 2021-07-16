/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_ulong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:37:46 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/15 14:14:46 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static	char	*dec_to_hex(unsigned long n, int prec);
static	int	len(unsigned long n, int base);

char	*input_is_ulong(unsigned long add, t_chunk **chunk)
{
	char	*res;

	res = dec_to_hex(add, (*chunk)->precision);
	proc_p_flags(&res, chunk);
	return (res);
}

char	*dec_to_hex(unsigned long n, int prec)
{
	int		l;
	char	*hex;
	char	*map;

	l = len(n, 16);
	if (l < prec)
		l = prec;
	map = ft_strdup("0123456789abcdef");
	hex = ft_calloc(l + 1, 1);
	while (l-- > 0)
	{
		hex[l] = (unsigned char)map[(n % 16)];
		n = n / 16;
	}
	free(map);
	return (hex);
}

int	len(unsigned long n, int base)
{
	int	l;

	l = 1;
	while (n / base != 0)
	{
		l++;
		n = n / base;
	}
	return (l);
}
