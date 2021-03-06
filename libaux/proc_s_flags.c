/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_s_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:04:27 by hde-camp          #+#    #+#             */
/*   Updated: 2021/07/19 16:07:14 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libaux.h"

void	proc_s_flags(char *flags, char **arg, int n)
{
	int		i;
	char	flag;

	i = 0;
	while (flags[i])
		if (flags[i++] == '0')
			flag = '0';
	i = 0;
	while (flags[i])
		if (flags[i++] == '-')
			flag = '-';
	if (flag == '0')
		apply_padding(arg, n, -1, '0');
	else if (flag == '-')
		apply_padding(arg, n, 1, ' ');
	else
		apply_padding(arg, n, -1, ' ');
}
