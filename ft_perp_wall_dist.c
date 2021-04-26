/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perp_wall_dist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:16:17 by shlu              #+#    #+#             */
/*   Updated: 2021/02/10 16:38:28 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_perp_wall_init(t_ray *r, int line)
{
	if (r->side == 0)
		r->perp_wall_dist = (r->px_int - r->px + (1 - r->step_x) / 2) \
			/ r->r_dir_x;
	else
		r->perp_wall_dist = (r->py_int - r->py + (1 - r->step_y) / 2) \
			/ r->r_dir_y;
	r->perp_w_dist[line] = r->perp_wall_dist;
	r->stripe_h = (int)(r->win_length / r->perp_wall_dist);
	r->stripe_start = -(r->stripe_h) / 2 + r->win_length / 2;
	r->stripe_end = r->stripe_h / 2 + r->win_length / 2;
	if (r->stripe_start < 0)
		r->stripe_start = 0;
	if (r->stripe_end >= r->win_length)
		r->stripe_end = r->win_length - 1;
	if (r->side == 0)
		r->wall_hit_x = r->py + r->perp_wall_dist * r->r_dir_y;
	else
		r->wall_hit_x = r->px + r->perp_wall_dist * r->r_dir_x;
	r->wall_hit_x -= floorf(r->wall_hit_x);
}
