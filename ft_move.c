/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:55:01 by shlu              #+#    #+#             */
/*   Updated: 2021/02/10 16:36:05 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_move_front(t_source *s, t_ray *r)
{
	float	move_speed;

	move_speed = 0.2;
	if ((s->map[(int)(r->py)][(int)(r->px + r->dir_x * (move_speed * 4))] \
		!= '1') && \
	(s->map[(int)(r->py)][(int)(r->px + r->dir_x * (move_speed * 4))] != '2'))
	{
		r->px += r->dir_x * move_speed;
		r->action = 1;
	}
	if ((s->map[(int)(r->py + r->dir_y * (move_speed * 4))][(int)(r->px)] \
		!= '1') && \
	(s->map[(int)(r->py + r->dir_y * (move_speed * 4))][(int)(r->px)] != '2'))
	{
		r->py += r->dir_y * move_speed;
		r->action = 1;
	}
}

void		ft_move_back(t_source *s, t_ray *r)
{
	float	move_speed;

	move_speed = 0.2;
	if ((s->map[(int)(r->py)][(int)(r->px - r->dir_x * (move_speed * 4))] \
		!= '1') && \
	(s->map[(int)(r->py)][(int)(r->px - r->dir_x * (move_speed * 4))] != '2'))
	{
		r->px -= r->dir_x * move_speed;
		r->action = 1;
	}
	if ((s->map[(int)(r->py - r->dir_y * (move_speed * 4))][(int)(r->px)] \
		!= '1') && \
	(s->map[(int)(r->py - r->dir_y * (move_speed * 4))][(int)(r->px)] != '2'))
	{
		r->py -= r->dir_y * move_speed;
		r->action = 1;
	}
}

void		ft_move_l_front(t_source *s, t_ray *r)
{
	float	move_speed;

	move_speed = 0.2;
	if ((s->map[(int)(r->py)][(int)(r->px + r->dir_y * (move_speed * 4))] \
		!= '1') && \
	(s->map[(int)(r->py)][(int)(r->px + r->dir_y * (move_speed * 4))] != '2'))
	{
		r->px += r->dir_y * move_speed;
		r->action = 1;
	}
	if ((s->map[(int)(r->py - r->dir_x * (move_speed * 4))][(int)(r->px)] \
		!= '1') && \
	(s->map[(int)(r->py - r->dir_x * (move_speed * 4))][(int)(r->px)] != '2'))
	{
		r->py -= r->dir_x * move_speed;
		r->action = 1;
	}
}

void		ft_move_r_front(t_source *s, t_ray *r)
{
	float	move_speed;

	move_speed = 0.2;
	if ((s->map[(int)(r->py)][(int)(r->px - r->dir_y * (move_speed * 4))] \
		!= '1') && \
	(s->map[(int)(r->py)][(int)(r->px - r->dir_y * (move_speed * 4))] != '2'))
	{
		r->px -= r->dir_y * move_speed;
		r->action = 1;
	}
	if ((s->map[(int)(r->py + r->dir_x * (move_speed * 4))][(int)(r->px)] \
		!= '1') && \
	(s->map[(int)(r->py + r->dir_x * (move_speed * 4))][(int)(r->px)] != '2'))
	{
		r->py += r->dir_x * move_speed;
		r->action = 1;
	}
}

void		ft_rotate(int keycode, t_ray *r)
{
	float	rot_speed;

	rot_speed = 0.05;
	if (keycode == K_ARROW_L)
	{
		r->l_dir_x = r->dir_x;
		r->dir_x = r->dir_x * cos(-rot_speed) - r->dir_y * sin(-rot_speed);
		r->dir_y = r->l_dir_x * sin(-rot_speed) + r->dir_y * cos(-rot_speed);
		r->l_plane_x = r->plane_x;
		r->plane_x = r->plane_x * cos(-rot_speed) - \
			r->plane_y * sin(-rot_speed);
		r->plane_y = r->l_plane_x * sin(-rot_speed) + \
			r->plane_y * cos(-rot_speed);
	}
	if (keycode == K_ARROW_R)
	{
		r->l_dir_x = r->dir_x;
		r->dir_x = r->dir_x * cos(rot_speed) - r->dir_y * sin(rot_speed);
		r->dir_y = r->l_dir_x * sin(rot_speed) + r->dir_y * cos(rot_speed);
		r->l_plane_x = r->plane_x;
		r->plane_x = r->plane_x * cos(rot_speed) - r->plane_y * sin(rot_speed);
		r->plane_y = r->l_plane_x * sin(rot_speed) + \
			r->plane_y * cos(rot_speed);
	}
}
