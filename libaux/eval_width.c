/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:43:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/07 15:57:43 by hde-camp         ###   ########.fr       */
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

int	eval_width(t_chunk *chunk, char *str, va_list args)
{
	int		i;
	char	*l;

	i = 0;
	if (str[i] == '*')
	{
		chunk->width = va_arg(args, int);
		return (i + 1);
	}
	if (ft_isdigit(str[i]) != 0 && (char)str[i] != '0')
	{
		while (ft_isdigit(str[i]) != 0)
		{
			i++;
		}
		l = ft_substr(str, 0, i);
		chunk->width = ft_atoi(l);
		free(l);
		l = NULL;
	}
	return (i);
}
