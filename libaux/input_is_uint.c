/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:10:37 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/19 17:55:45 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static	int	len(unsigned int n, int base);
static	char	*dec_to_hex(unsigned int n, int uppercase, int prec);
static	char	*dec_to_str(unsigned int n, int prec);

char	*input_is_uint(unsigned int n, t_chunk **chunk)
{
	char	*p;
	char	o_b;

	o_b = (*chunk)->conversion;
	if ((*chunk)->precision == 0 && n == 0)
	{
		p = ft_strdup("");
	}
	else if (o_b == 'u')
		p = dec_to_str(n, (*chunk)->precision);
	else if (o_b == 'x')
		p = dec_to_hex(n, 0, (*chunk)->precision);
	else if (o_b == 'X')
		p = dec_to_hex(n, 1, (*chunk)->precision);
	proc_ux_flags(&p, chunk);
	return (p);
}

char	*dec_to_hex(unsigned int n, int uppercase, int prec)
{
	int		l;
	char	*hex;
	char	*map;

	l = len(n, 16);
	if (l < prec)
		l = prec;
	if (uppercase)
		map = ft_strdup("0123456789ABCDEF");
	else
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

char	*dec_to_str(unsigned int n, int prec)
{
	int		l;
	char	*octal;

	l = len(n, 10);
	if (l < prec)
		l = prec;
	octal = ft_calloc(l + 1, 1);
	while (l-- > 0)
	{
		octal[l] = (unsigned char)(n % 10 + 48);
		n = n / 10;
	}
	return (octal);
}

int	len(unsigned int n, int base)
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
