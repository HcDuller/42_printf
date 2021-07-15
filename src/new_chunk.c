/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:20:52 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/07 17:53:01 by hde-camp         ###   ########.fr       */
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
		self_ptr->width = 0;
		self_ptr->precision = -1;
		self_ptr->conversion = (unsigned char)0;
		self_ptr->next = NULL;
		self_ptr->previous = NULL;
	}
	return (self_ptr);
}
