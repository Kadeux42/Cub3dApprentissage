/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stripe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:21:31 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 12:04:12 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void				ft_stripe_algo(t_ray *r, t_graph *g)
{
	g->pixel = r->stripe_start - 1;
	r->tex_x = (int)((1 - r->wall_hit_x) * \
				(float)(((g->img)[r->tex_code])->wth));
	if ((r->side == 0 && r->r_dir_x > 0) || (r->side == 1 && r->r_dir_y < 0))
		r->tex_x = (((g->img)[r->tex_code])->wth) - r->tex_x - 1;
	r->tex_scale = (((g->img)[r->tex_code])->lth) / (float)r->stripe_h;
	r->tex_pos = ((float)r->stripe_start - (float)r->win_length / 2 + \
			(float)r->stripe_h / 2) * (float)r->tex_scale;
}

void				ft_stripe_algo_(t_ray *r, t_graph *g, int line)
{
	g->byte = 0;
	r->tex_y = r->tex_pos;
	if (r->tex_y > ((((g->img)[r->tex_code])->lth) - 1))
		r->tex_y = (((g->img)[r->tex_code])->lth) - 1;
	r->tex_pos += r->tex_scale;
	g->src = r->tex_y * (((g->img)[r->tex_code])->sl) + \
		r->tex_x * ((((g->img)[r->tex_code])->bpp) / 8);
	if (g->src < 0)
		g->src = 0;
	g->dst = (g->pixel) * (((g->img)[5])->sl) + \
		line * ((((g->img)[5])->bpp) / 8);
}

void				ft_display_stripe(t_ray *r, t_graph *g, int line)
{
	unsigned char	color;

	while (g->pixel++ < r->stripe_end)
	{
		ft_stripe_algo_(r, g, line);
		color = (((g->img)[r->tex_code])->addr)[(g->src) + 3];
		while ((g->byte) < 4)
		{
			color = (((g->img)[r->tex_code])->addr)[(g->src) + (g->byte)];
			(((g->img)[5])->addr)[(g->dst) + (g->byte)++] = color;
		}
	}
}
