/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_last_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:27:50 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/06 14:19:07 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

t_chunk	*new_last_chunk(t_chunk **chunk, void *content)
{
	t_chunk	*ptr;

	ptr = new_chunk(NULL);
	if (*chunk != NULL)
	{
		(*chunk)->next = ptr;
		ptr->previous = *chunk;
	}
	if (content != NULL)
	{
		ptr->argument = content;
	}
	return (ptr);
}
