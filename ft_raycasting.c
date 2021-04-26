/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:53:43 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 11:51:17 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_raycasting(t_source *s, t_ray *r, t_graph *g)
{
	int		line;

	line = 0;
	while (line < s->win_width)
	{
		ft_struct_r_algo(r, line);
		ft_dist(r);
		ft_digital_diff_analy(s, r, line);
		ft_perp_wall_init(r, line);
		ft_pick_texture(r);
		ft_stripe_algo(r, g);
		ft_display_stripe(r, g, line);
		ft_display_floor_and_ceiling(r, g, line);
		line++;
	}
}

void		ft_struct_r_algo(t_ray *r, int line)
{
	r->px_int = (int)r->px;
	r->py_int = (int)r->py;
	r->l_dir_x = 0;
	r->l_plane_x = 0;
	r->camera_x = 2 * line / (float)r->win_width - 1;
	r->r_dir_x = r->dir_x + r->plane_x * r->camera_x;
	r->r_dir_y = r->dir_y + r->plane_y * r->camera_x;
	r->hit = 0;
	r->stripe_start = 0;
	r->stripe_end = 0;
	r->stripe_h = 0;
	r->side = -1;
}

void		ft_dist(t_ray *r)
{
	r->delta_dist_x = fabs(1 / r->r_dir_x);
	r->delta_dist_y = fabs(1 / r->r_dir_y);
	if (r->r_dir_x < 0)
	{
		r->step_x = -1;
		r->first_dist_x = (r->px - r->px_int) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->first_dist_x = (r->px_int + 1 - r->px) * r->delta_dist_x;
	}
	if (r->r_dir_y < 0)
	{
		r->step_y = -1;
		r->first_dist_y = (r->py - r->py_int) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->first_dist_y = (r->py_int + 1 - r->py) * r->delta_dist_y;
	}
}

void		ft_digital_diff_analy(t_source *s, t_ray *r, int line)
{
	if (line == 0)
		r->sp_count = 0;
	while (r->hit != 1)
	{
		if (r->first_dist_x < r->first_dist_y)
		{
			r->first_dist_x += r->delta_dist_x;
			r->px_int += r->step_x;
			r->side = 0;
		}
		else
		{
			r->first_dist_y += r->delta_dist_y;
			r->py_int += r->step_y;
			r->side = 1;
		}
		if (s->map[r->py_int][r->px_int] == '1')
			r->hit = 1;
	}
}
