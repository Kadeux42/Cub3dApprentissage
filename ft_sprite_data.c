/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:10:23 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 13:30:33 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int				ft_sp_malloc(t_source *s)
{
	int			i;

	i = 0;
	s->sp = (t_sp **)malloc(sizeof(t_sp *) * (s->sp_num + 1));
	if (!s->sp)
		return (1);
	s->sp[s->sp_num] = NULL;
	while (i < s->sp_num)
	{
		s->sp[i] = (t_sp *)malloc(sizeof(t_sp));
		if (!(s->sp[i]))
			return (1);
		i++;
	}
	return (0);
}

void			ft_sprite_data(t_source *s)
{
	int		num;
	int		y;
	int		x;

	num = 0;
	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x] != '\0')
		{
			if (s->map[y][x] == '2')
			{
				((s->sp)[num])->x = x + .5;
				((s->sp)[num])->y = y + .5;
				num++;
			}
			x++;
		}
		y++;
	}
}
