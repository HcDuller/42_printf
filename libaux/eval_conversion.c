/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:49:44 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/15 19:06:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static int	is_conv_spec(char c);

int	eval_conversion(t_chunk *chunk, char *str)
{
	if (is_conv_spec(str[0]))
	{
		chunk->conversion = str[0];
		return (1);
	}
	return (0);
}

int	is_conv_spec(char c)
{
	char	allowed_specs[10];
	int		i;

	i = 0;
	ft_strlcpy(allowed_specs, "cspdiuxX%", 10);
	while (allowed_specs[i])
	{
		if (c == allowed_specs[i])
			return (1);
		i++;
	}
	return (0);
}
