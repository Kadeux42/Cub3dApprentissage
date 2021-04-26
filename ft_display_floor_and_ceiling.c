/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_floor_and_ceiling.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:43:41 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 12:08:28 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_display_floor_and_ceiling(t_ray *r, t_graph *g, int line)
{
	int		pixel;
	int		dst;

	pixel = 0;
	while (pixel < r->stripe_start)
	{
		dst = pixel * (((g->img)[5])->sl) + line * ((((g->img)[5])->bpp) / 8);
		(((g->img)[5])->addr)[dst++] = (char)(g->c_color);
		(((g->img)[5])->addr)[dst++] = (char)(g->c_color >> 8);
		(((g->img)[5])->addr)[dst++] = (char)(g->c_color >> 16);
		(((g->img)[5])->addr)[dst++] = (char)(g->c_color >> 24);
		pixel++;
	}
	pixel = r->stripe_end;
	while (pixel < r->win_length)
	{
		dst = pixel * (((g->img)[5])->sl) + line * ((((g->img)[5])->bpp) / 8);
		(((g->img)[5])->addr)[dst++] = (char)(g->f_color);
		(((g->img)[5])->addr)[dst++] = (char)(g->f_color >> 8);
		(((g->img)[5])->addr)[dst++] = (char)(g->f_color >> 16);
		(((g->img)[5])->addr)[dst++] = (char)(g->f_color >> 24);
		pixel++;
	}
}
