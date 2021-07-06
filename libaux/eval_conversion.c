/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:49:44 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/05 21:39:44 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"
#include "../libft/libft.h"

static int	is_conv_spec(char c);

int	eval_conversion(t_chunk *chunk, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '%')
	{
		chunk->conversion = ft_strdup("%");
		return (i + 1);
	}
	if (is_conv_spec(str[i]))
	{
		while (is_conv_spec(str[i]))
		{
			i++;
		}
		chunk->conversion = ft_substr(str, 0, i);
	}
	return (i);
}

int	is_conv_spec(char c)
{
	char	allowed_specs[9];
	int		i;

	i = 0;
	ft_strlcpy(allowed_specs, "cspdiuxX", 9);
	while (allowed_specs[i])
	{
		if (c == allowed_specs[i])
			return (1);
		i++;
	}
	return (0);
}
