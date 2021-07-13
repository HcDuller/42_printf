/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_s_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:11:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/13 19:18:13 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

char	*proc_s_flags(char *flags, const char *arg, int n)
{
	int		i;
	int		j;
	char	*pad;
	char	*aux;

	i = 0;
	while (*flags)
	{
		if (*flags == '-')
			i++;
		flags++;
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
