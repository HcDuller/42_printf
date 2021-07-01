/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:20:52 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/01 13:32:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"
#include "../libft/libft.h"

t_chunk	*new_chunk(void *arg, char *conversion, char *flags)
{
	t_chunk	*self_ptr;
	char	*c_ptr;
	char	*f_ptr;

	self_ptr = malloc(sizeof(t_chunk));
	if (self_ptr)
	{
		self_ptr->argument = arg;
		if (conversion)
			self_ptr->conversion = conversion;
		else
			self_ptr->conversion = NULL;
		if (flags)
			self_ptr->flags = flags;
		else
			self_ptr->flags = NULL;
		self_ptr->next = NULL;
		self_ptr->previous = NULL;
	}
	return (self_ptr);
}
