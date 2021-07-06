/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:10 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/06 14:54:54 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

t_chunk	*first_chunk(t_chunk *ptr)
{
	while (ptr->previous != NULL)
		ptr = ptr->previous;
	return (ptr);
}
