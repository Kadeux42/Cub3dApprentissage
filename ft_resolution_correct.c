/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_g_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:58:06 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 13:01:19 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_resolution_correct(t_source *s, t_graph *g)
{
	int		screen_w;
	int		screen_l;

	mlx_get_screen_size(g->mlx_ptr, &screen_w, &screen_l);
	if (s->win_width > screen_w)
		s->win_width = screen_w;
	if (s->win_length > screen_l)
		s->win_length = screen_l;
}
