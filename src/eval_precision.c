/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/13 16:58:43 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"
#include "../libft/libft.h"

static	int	count_digits(char *ptr);

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
		i += count_digits(&str[i]);
		if (i > 1)
		{
			l = ft_substr(str, 1, i);
			chunk->precision = ft_atoi(l);
			free(l);
			l = NULL;
		}
		else
			chunk->precision = 0;
	}
	return (i);
}

int	count_digits(char *ptr)
{
	int	i;

	i = 0;
	while (ft_isdigit(ptr[i]) != 0)
		i++;
	return (i);
}
