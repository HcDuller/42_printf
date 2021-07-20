/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_char_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:29:02 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/19 22:18:37 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int			lens[2];
	int			pos;
	const char	*fake_arg;
	char		*r;

	if (arg == NULL)
		fake_arg = "(null)";
	else
		fake_arg = arg;
	lens[0] = ft_strlen(fake_arg);
	if ((*chunk)->precision > -1)
		lens[1] = (*chunk)->precision;
	else
		lens[1] = lens[0];
	r = ft_calloc(lens[0] + 1, sizeof(char));
	pos = 0;
	while (fake_arg[pos] && pos < lens[0] && pos < lens[1])
	{
		r[pos] = fake_arg[pos];
		pos++;
	}
	proc_s_flags((*chunk)->flags, &r, (*chunk)->width);
	return (r);
}
