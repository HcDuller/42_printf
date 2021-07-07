/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/07 18:18:03 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"
#include "../libft/libft.h"

int	eval_precision(t_chunk *chunk, char *str, va_list args)
{
	int		i;
	char	*l;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		if (str[i] == '*')
		{
			chunk->precision = va_arg(args, int);
			return (i + 1);
		}
		while (ft_isdigit(str[i]) != 0)
		{
			i++;
		}
		if (i > 1)
		{
			l = ft_substr(str, 0, i);
			chunk->precision = ft_atoi(l);
			free(l);
			l = NULL;
		}
		else
			chunk->precision = 0;
	}
	return (i);
}
