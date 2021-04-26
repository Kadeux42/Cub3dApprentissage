/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:54:13 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 12:59:35 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	ft_free_ray(t_ray *r)
{
	if (r)
	{
		if (r->perp_w_dist)
			ft_free_ptr(r->perp_w_dist);
		ft_free_ptr(r);
	}
}

void	ft_free_cub(t_cub *c)
{
	if (c)
		ft_free_ptr(c);
}

int		ft_free_all_struct(t_cub *c)
{
	if (c)
	{
		if (c->s)
			ft_free_source(c->s);
		if (c->g)
			ft_free_graph(c->g);
		if (c->r)
			ft_free_ray(c->r);
		if (c->lkeys)
			ft_lstclear(&c->lkeys, &free);
		ft_free_cub(c);
	}
	exit(0);
}
