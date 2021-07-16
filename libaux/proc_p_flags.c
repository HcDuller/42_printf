/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_p_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:20:22 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/15 14:42:17 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

static	int	search_flag(char *flags, char target);
static	char	*hex_identifier(int blank, int plus);

void	proc_p_flags(char **str, t_chunk **chunk)
{
	char	*hex_tag;
	char	*temp;
	int		flags[4];

	flags[0] = search_flag((*chunk)->flags, '0');
	flags[1] = search_flag((*chunk)->flags, ' ');
	flags[2] = search_flag((*chunk)->flags, '-');
	flags[3] = search_flag((*chunk)->flags, '+');
	hex_tag = hex_identifier(flags[1], flags[3]);
	if (flags[2] || (*chunk)->precision != -1)
	{
		temp = ft_strjoin(hex_tag, *str);
		free(*str);
		*str = temp;
		if (flags[2])
			apply_padding(str, (*chunk)->width, 1, ' ');
		else
			apply_padding(str, (*chunk)->width, -1, ' ');
	}
	else if (flags[0])
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

int	search_flag(char *flags, char target)
{
	while (*flags)
		if (*(flags++) == target)
			return (1);
	return (0);
}

char	*hex_identifier(int blank, int plus)
{
	if (plus)
		return (ft_strdup("+0x"));
	if (blank)
		return (ft_strdup(" 0x"));
	return (ft_strdup("0x"));
}
