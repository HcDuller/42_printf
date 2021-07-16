/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_char_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:53:12 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/16 19:23:06 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

char	*input_is_char_p(const char *arg, t_chunk **chunk)
{
	int			final_length;
	int			o_length;
	const char	*fake_arg;

	if (arg == NULL)
		fake_arg = "(null)";
	else
		fake_arg = arg;
	o_length = ft_strlen(fake_arg);
	final_length = o_length;
	if (final_length < (*chunk)->width)
		final_length = (*chunk)->width;
	if ((*chunk)->precision > -1)
	{
		if ((*chunk)->precision < final_length)
		{
			if ((*chunk)->conversion == '%')
				(*chunk)->precision = final_length;
			else
				final_length = (*chunk)->precision;
		}
		if (final_length == 0)
			return ((char *)ft_calloc(1, sizeof(char)));
	}
	if (final_length <= o_length)
		return (ft_substr(fake_arg, 0, final_length));
	return (proc_s_flags((*chunk)->flags, fake_arg, final_length - o_length));
}
