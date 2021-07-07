/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_from_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:53:12 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/07 19:53:43 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

char	*res_from_s(const char *arg,t_chunk **chunk)
{
	int		final_length;
	int		o_length;
	char	*s;

	o_length = ft_strlen(arg);
	final_length = o_length;
	if (final_length < (*chunk)->width)
		final_length = (*chunk)->width;
	if ((*chunk)->precision > -1)
	{
		if ((*chunk)->precision < final_length)
			final_length = (*chunk)->precision;
		if (final_length == 0)
			return ((char *)ft_calloc(1, sizeof(char)));
	}
	if (final_length <= o_length)
		return (ft_substr(arg, 0, final_length));
	return (eval_s_flags((*chunk)->flags, arg, final_length - o_length));
}

char	*eval_s_flags(char *flags,const char *arg,int n)
{
	int		i;
	int		j;
	char	*pad;
	char	*aux;

	i = 0;
	while (flags[i])
	{
		if (flags[i] != '-')
			return (ft_strdup("(Invalid flag)"));
		i++;
	}
	j = 0;
	pad = ft_calloc(n + 1, sizeof(char));
	while (j < n)
	{
		pad[j++] = (unsigned char)32;
	}
	if (i > 0)
		aux = ft_strjoin(arg, pad);
	else
		aux = ft_strjoin(pad, arg);
	free(pad);
	return (aux);
}