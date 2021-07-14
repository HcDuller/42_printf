/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:51:17 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/14 16:51:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

void	apply_padding(char **str, int size, int side, char c)
{
	int		l;
	int		i;
	char	*padding;
	char	*aux;

	l = ft_strlen(*str);
	if (size <= l)
		return ;
	padding = malloc(size - l + 1);
	i = 0;
	while (i < (size - l))
		padding[i++] = c;
	padding[size - l] = 0;
	if (side > 0)
		aux = ft_strjoin(*str, padding);
	else
		aux = ft_strjoin(padding, *str);
	free(*str);
	free(padding);
	*str = aux;
}
