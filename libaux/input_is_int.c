/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:41:17 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/16 15:48:59 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

char	*input_is_int(int arg, t_chunk **chunk)
{
	if ((*chunk)->conversion == 'c')
	{
		if ((*chunk)->precision <= 0)
			(*chunk)->precision = 1;
		if ((*chunk)->width == 0)
			(*chunk)->width = 1;
		return (res_from_c(arg, chunk));
	}
	if ((*chunk)->conversion == 'd' || (*chunk)->conversion == 'i')
		return (res_from_d(arg, chunk));
	return (ft_strdup("b.s"));
}
