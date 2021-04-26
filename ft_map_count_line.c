/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_count_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:37:30 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 15:02:52 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int				ft_map_count_line(t_source *s)
{
	static int	countline = -1;

	if (countline == -1)
	{
		s->map_start_line = s->total_line;
		countline = 0;
	}
	countline++;
	return (0);
}
