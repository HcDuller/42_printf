/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:26:20 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/01 14:32:36 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

void	free_chunk(t_chunk **str_ptr)
{
	if (*str_ptr)
	{
		if ((*str_ptr)->argument)
			free((*str_ptr)->argument);
		if ((*str_ptr)->conversion)
			free((*str_ptr)->conversion);
		if ((*str_ptr)->flags)
			free((*str_ptr)->flags);
		(*str_ptr)->argument = NULL;
		(*str_ptr)->conversion = NULL;
		(*str_ptr)->flags = NULL;
	}
	free(*str_ptr);
	*str_ptr = NULL;
}
