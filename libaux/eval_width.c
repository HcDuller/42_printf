/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:43:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/06 14:43:23 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/05 19:42:53 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"
#include "../libft/libft.h"

int	eval_width(t_chunk *chunk, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '*')
	{
		chunk->width = ft_strdup("*");
		return (i + 1);
	}
	if (ft_isdigit(str[i]) != 0 && (char)str[i] != '0')
	{
		while (ft_isdigit(str[i]) != 0)
		{
			i++;
		}
		chunk->width = ft_substr(str, 0, i);
	}
	return (i);
}
