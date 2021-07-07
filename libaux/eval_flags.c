/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/07 19:19:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"
#include "../libft/libft.h"

static	int	allowed_character(char c);

int	eval_flags(t_chunk *chunk, char *str)
{
	int	i;

	i = 0;
	while (allowed_character((unsigned char)str[i]))
	{
		i++;
	}
	if (i > 0)
		chunk->flags = ft_substr(str, 0, i);
	else
		chunk->flags = ft_calloc(1, sizeof(char));
	return (i);
}

int	allowed_character(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}
