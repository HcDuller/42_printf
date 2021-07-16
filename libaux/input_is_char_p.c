/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_char_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:53:12 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/15 18:30:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

char	*input_is_char_p(const char *arg, t_chunk **chunk)
{
	int		final_length;
	int		o_length;

	if (arg == NULL)
		return (ft_strdup("(null)"));
	o_length = ft_strlen(arg);
	final_length = o_length;
	if (final_length < (*chunk)->width)
		final_length = (*chunk)->width;
	if ((*chunk)->precision > -1)
	{
		if ((*chunk)->precision < final_length)
			final_length = (*chunk)->precision;
		if (final_length == 0)
			return ((char *)ft_calloc(1, sizeof(char)));
	}
	if (final_length <= o_length)
		return (ft_substr(arg, 0, final_length));
	return (proc_s_flags((*chunk)->flags, arg, final_length - o_length));
}
