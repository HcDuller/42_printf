/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:19:21 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/06 18:05:19 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

void	for_each_chunk(t_chunk **chunk, void (*f)(t_chunk **))
{
	t_chunk *temp;
	t_chunk *aux;

	temp = first_chunk(*chunk);
	aux  = temp;
	while (temp != NULL)
	{
		aux = temp->next;
		f(&temp);
		temp = aux;
	}
}

void	args_iterator(t_chunk **chunk, void (*f)(t_chunk **, va_list),va_list args)
{
	t_chunk *temp;
	t_chunk *aux;

	temp = first_chunk(*chunk);
	aux  = temp;
	while (temp != NULL)
	{
		aux = temp->next;
		f(&temp, args);
		temp = aux;
	}
}