/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:35:23 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 11:53:15 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int			ft_graphics(t_cub *c)
{
	ft_key_hook(0, c);
	if ((c->r)->action == 1)
	{
		if ((c->s)->put_window == 1)
			mlx_clear_window((c->g)->mlx_ptr, (c->g)->win_ptr);
		ft_raycasting(c->s, c->r, c->g);
		ft_sprite(c->s, c->r, c->g);
		(c->r)->action = 0;
	}
	if ((c->s)->put_window == 1)
		mlx_put_image_to_window((c->g)->mlx_ptr, (c->g)->win_ptr, \
							(((c->g)->img)[5])->ptr, 0, 0);
	return (0);
}
