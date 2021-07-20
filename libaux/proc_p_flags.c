/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_p_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:20:22 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/19 22:14:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static	char	*hex_prep(int blank, int plus);
static	void	apply_m_p(char *hex_tag, char **str, int minus, int width);

void	proc_p_flags(char **str, t_chunk **chunk)
{
	char	*hex_tag;
	char	*temp;
	char	*flags;

	flags = (*chunk)->flags;
	hex_tag = hex_prep(has_char(flags, ' '), has_char(flags, '+'));
	if (has_char(flags, '-') || (*chunk)->precision != -1)
		apply_m_p(hex_tag, str, has_char(flags, '-'), (*chunk)->width);
	else if (has_char(flags, '0'))
	{
		apply_padding(str, (*chunk)->width - ft_strlen(hex_tag), -1, '0');
		temp = ft_strjoin(hex_tag, *str);
		free(*str);
		*str = temp;
	}
	else
	{
		temp = ft_strjoin(hex_tag, *str);
		free(*str);
		*str = temp;
		apply_padding(str, (*chunk)->width, -1, ' ');
	}
	free(hex_tag);
}

void	apply_m_p(char *h_t, char **s, int m, int width)
{
	char	*temp;

	temp = ft_strjoin(h_t, *s);
	free(*s);
	*s = temp;
	if (m)
		apply_padding(s, width, 1, ' ');
	else
		apply_padding(s, width, -1, ' ');
}

char	*hex_prep(int blank, int plus)
{
	if (plus)
		return (ft_strdup("+0x"));
	if (blank)
		return (ft_strdup(" 0x"));
	return (ft_strdup("0x"));
}
