/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:05:59 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 11:44:22 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_sp_dist(t_source *s, t_ray *r)
{
	int		i;

	i = 0;
	while (i < s->sp_num)
	{
		((s->sp)[i])->dist = (r->px - (((s->sp)[i])->x)) * \
		(r->px - (((s->sp)[i])->x)) + (r->py - (((s->sp)[i])->y)) * \
		(r->py - (((s->sp)[i])->y));
		i++;
	}
}

void		ft_sprite_swap(t_source *s, int check)
{
	float	dist;
	float	x;
	float	y;

	dist = ((s->sp)[check])->dist;
	((s->sp)[check])->dist = ((s->sp)[check + 1])->dist;
	((s->sp)[check + 1])->dist = dist;
	x = ((s->sp)[check])->x;
	((s->sp)[check])->x = ((s->sp)[check + 1])->x;
	((s->sp)[check + 1])->x = x;
	y = ((s->sp)[check])->y;
	((s->sp)[check])->y = ((s->sp)[check + 1])->y;
	((s->sp)[check + 1])->y = y;
}

void		ft_sort_sprite(t_source *s)
{
	int		check_round;
	int		check;

	check_round = 0;
	check = 0;
	while (check_round < (s->sp_num - 1))
	{
		check = 0;
		while (check < s->sp_num - 1)
		{
			if (((s->sp)[check])->dist < ((s->sp)[check + 1])->dist)
				ft_sprite_swap(s, check);
			check++;
		}
		check_round++;
	}
}

void		ft_struct_sp_init(t_source *s, t_ray *r, int num)
{
	r->sp_x = ((s->sp)[num])->x - r->px;
	r->sp_y = ((s->sp)[num])->y - r->py;
	r->inv = 1 / (r->plane_x * r->dir_y - r->dir_x * r->plane_y);
	r->sp_trans_x = r->inv * (r->dir_y * r->sp_x - r->dir_x * r->sp_y);
	r->sp_trans_y = r->inv * (-(r->plane_y) * r->sp_x + r->plane_x * r->sp_y);
	r->sp_screen_x = (int)((r->win_width / 2) * \
					(1 + r->sp_trans_x / r->sp_trans_y));
	r->sp_h = abs((int)(r->win_length / (r->sp_trans_y)));
	r->sp_start_y = (r->win_length - r->sp_h) / 2;
	if (r->sp_start_y < 0)
		r->sp_start_y = 0;
	r->sp_end_y = (r->win_length + r->sp_h) / 2;
	if (r->sp_end_y >= r->win_length)
		r->sp_end_y = r->win_length - 1;
	r->sp_w = abs((int)(r->win_length / (r->sp_trans_y)));
	r->sp_start_x = -(r->sp_w) / 2 + r->sp_screen_x;
	if (r->sp_start_x < 0)
		r->sp_start_x = 0;
	r->sp_end_x = r->sp_w / 2 + r->sp_screen_x;
	if (r->sp_end_x >= r->win_width)
		r->sp_end_x = r->win_width - 1;
}

void		ft_sprite(t_source *s, t_ray *r, t_graph *g)
{
	int		num;
	int		clear;

	num = 0;
	clear = 0;
	ft_sp_dist(s, r);
	ft_sort_sprite(s);
	r->tex_code = 4;
	while (num < s->sp_num)
	{
		ft_struct_sp_init(s, r, num);
		ft_display_sprite(r, g);
		num++;
	}
}
