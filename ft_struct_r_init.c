/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_r_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:58:18 by shlu              #+#    #+#             */
/*   Updated: 2021/02/11 17:03:09 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_direction(t_source *s, t_ray *r)
{
	if (s->orientation == 'N')
	{
		r->dir_x = 0;
		r->dir_y = -1;
		r->plane_x = 0.66;
		r->plane_y = 0;
	}
	if (s->orientation == 'S')
	{
		r->dir_x = 0;
		r->dir_y = 1;
		r->plane_x = -0.66;
		r->plane_y = 0;
	}
	ft_direction_(s, r);
}

void		ft_direction_(t_source *s, t_ray *r)
{
	if (s->orientation == 'W')
	{
		r->dir_x = -1;
		r->dir_y = 0;
		r->plane_x = 0;
		r->plane_y = -0.66;
	}
	if (s->orientation == 'E')
	{
		r->dir_x = 1;
		r->dir_y = 0;
		r->plane_x = 0;
		r->plane_y = 0.66;
	}
}

t_ray		*ft_struct_r_init(t_source *s, t_ray *r)
{
	r = (t_ray *)malloc(sizeof(t_ray));
	if (!r)
		return (NULL);
	r->perp_w_dist = (float *)malloc(sizeof(float) * (s->win_width));
	if (!(r->perp_w_dist))
	{
		ft_free_ray(r);
		return (NULL);
	}
	r->px = s->px;
	r->py = s->py;
	r->win_width = s->win_width;
	r->win_length = s->win_length;
	ft_direction(s, r);
	r->action = 1;
	r->camera_x = 0;
	r->sp_count = 0;
	return (r);
}
