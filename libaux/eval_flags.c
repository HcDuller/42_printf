/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/05 18:16:17 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"
#include "../libft/libft.h"

int	eval_flags(t_chunk *chunk, char *str)
{
	int	i;

	i = 0;
	while (allowed_character((unsigned char)str[i]))
	{
		i++;
	}
	if (i > 0)
	{
		chunk->flags = ft_substr(str, 0, i);
	}
	return (i);
}

int	allowed_character(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}
