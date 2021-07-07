/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:26:20 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/07 16:36:50 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

void	free_chunk(t_chunk **str_ptr)
{
	if (*str_ptr)
	{
		if ((*str_ptr)->argument)
			free((*str_ptr)->argument);
		//if ((*str_ptr)->conversion)
		//	free((*str_ptr)->conversion);
		if ((*str_ptr)->flags)
			free((*str_ptr)->flags);
		//if ((*str_ptr)->width)
		//	free((*str_ptr)->width);
		//if ((*str_ptr)->precision)
		//	free((*str_ptr)->precision);
		(*str_ptr)->argument = NULL;
		(*str_ptr)->conversion = (char)0;
		(*str_ptr)->flags = NULL;
		//(*str_ptr)->width = NULL;
		(*str_ptr)->precision = 0;
	}
	free(*str_ptr);
	*str_ptr = NULL;
}
