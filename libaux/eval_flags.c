/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/16 18:19:54 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

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
	int		i;
	char	*p;

	i = 0;
	p = "-0 #+";
	while (p[i])
	{
		if (p[i] == c)
			return (1);
		i++;
	}
	return (0);
}
