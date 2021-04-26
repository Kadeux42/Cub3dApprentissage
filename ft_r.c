/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:39:06 by shlu              #+#    #+#             */
/*   Updated: 2020/08/12 17:39:07 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int				ft_r(t_source *s, char *line)
{
	char		**table;
	int			i;
	static int	pass_in = 0;

	i = 0;
	pass_in++;
	if (pass_in == 2)
		return (ft_error_int("Multiple assignments for resolution."));
	table = ft_split(line, ' ');
	while (table[i])
		i++;
	if (i == 2)
	{
		if (ft_table_isnum(table, 'r'))
		{
			ft_free_table(table, i);
			return (ft_error_int("Invalid argument for resolution."));
		}
		s->win_width = ft_atoi(table[0]);
		s->win_length = ft_atoi(table[1]);
	}
	if (ft_free_table(table, i) != 2)
		return (ft_error_int("Wrong number of arguements for resolution."));
	else
		return (0);
}
