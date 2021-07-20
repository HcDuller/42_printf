/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:46:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/19 20:56:41 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

int	has_char(char *haystack, char needle)
{
	while (*haystack)
		if ((char)*(haystack++) == needle)
			return (1);
	return (0);
}
