/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:54:13 by shlu              #+#    #+#             */
/*   Updated: 2021/02/17 19:17:47 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	ft_free_img(t_graph *g)
{
	int	i;

	i = 0;
	while (g->img[i])
	{
		if ((g->img[i])->path)
			ft_free_ptr((g->img[i]->path));
		if ((g->img[i])->ptr)
			mlx_destroy_image(g->mlx_ptr, (g->img[i])->ptr);
		ft_free_ptr(g->img[i]);
		i++;
	}
	ft_free_ptr(g->img);
}

void	ft_free_graph(t_graph *g)
{
	if (g)
	{
		if (g->img)
			ft_free_img(g);
		if (g->win_ptr)
			mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		if (g->mlx_ptr)
		{
			mlx_destroy_display(g->mlx_ptr);
			ft_free_ptr(g->mlx_ptr);
		}
		ft_free_ptr(g);
	}
}
