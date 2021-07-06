/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:20:52 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/05 21:27:49 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"
#include "../libft/libft.h"

t_chunk	*new_chunk(void *arg)
{
	t_chunk	*self_ptr;
	char	*c_ptr;
	char	*f_ptr;

	self_ptr = ft_calloc(1, sizeof(t_chunk));
	if (self_ptr)
	{
		if (arg)
			self_ptr->argument = arg;
		else
			self_ptr->argument = NULL;
		self_ptr->flags = NULL;
		self_ptr->width = NULL;
		self_ptr->precision = NULL;
		self_ptr->conversion = NULL;
		self_ptr->next = NULL;
		self_ptr->previous = NULL;
	}
	return (self_ptr);
}
