/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:05:59 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 11:44:22 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void				ft_display_sprite_(t_ray *r, t_graph *g, int stripe)
{
	int				modify;
	unsigned char	color;

	while (g->pixel < r->sp_end_y)
	{
		g->byte = 0;
		modify = g->pixel * 256 - (r->win_length) * 128 + r->sp_h * 128;
		r->tex_y = (((modify) * \
					(((g->img)[r->tex_code])->lth)) / r->sp_h) / 256;
		g->src = r->tex_y * ((g->img)[r->tex_code])->sl + \
			r->tex_x * ((((g->img)[r->tex_code])->bpp) / 8);
		if (g->src < 0)
			g->src = 0;
		g->dst = g->pixel * \
			((g->img)[5])->sl + stripe * ((((g->img)[5])->bpp) / 8);
		color = (((g->img)[r->tex_code])->addr)[(g->src) + 3];
		if (color != 0xff)
			while (g->byte < 4)
			{
				color = (((g->img)[r->tex_code])->addr)[(g->src) + (g->byte)];
				(((g->img)[5])->addr)[(g->dst) + (g->byte)] = color;
				g->byte++;
			}
		g->pixel++;
	}
}

void				ft_display_sprite(t_ray *r, t_graph *g)
{
	int				stripe;

	stripe = r->sp_start_x;
	while (stripe < r->sp_end_x)
	{
		r->tex_x = (int)(256 * (stripe - (-(r->sp_w) / 2 + r->sp_screen_x)) * \
						(((g->img)[r->tex_code])->wth) / r->sp_w) / 256;
		if (r->sp_trans_y > 0 && stripe > 0 && stripe < r->win_width && \
			r->sp_trans_y < r->perp_w_dist[stripe])
		{
			g->pixel = r->sp_start_y;
			ft_display_sprite_(r, g, stripe);
		}
		stripe++;
	}
}
