/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:19:21 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/13 16:50:03 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

void	for_each_chunk(t_chunk **chunk, void (*f)(t_chunk **))
{
	t_chunk	*temp;
	t_chunk	*aux;

	temp = first_chunk(*chunk);
	aux = temp;
	while (temp != NULL)
	{
		aux = temp->next;
		f(&temp);
		temp = aux;
	}
}
