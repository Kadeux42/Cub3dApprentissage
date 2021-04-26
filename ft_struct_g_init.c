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

void		ft_img_init_(t_source *s, t_graph *g)
{
	int		i;

	i = 0;
	g->img[0]->path = ft_strdup(s->path_no);
	g->img[1]->path = ft_strdup(s->path_so);
	g->img[2]->path = ft_strdup(s->path_we);
	g->img[3]->path = ft_strdup(s->path_ea);
	g->img[4]->path = ft_strdup(s->path_sp);
	g->img[5]->path = NULL;
	while (i < 6)
	{
		g->img[i]->ptr = NULL;
		g->img[i]->addr = NULL;
		i++;
	}
	g->c_color = mlx_get_color_value(g->mlx_ptr, 65536 * s->c_0 + \
	256 * s->c_1 + s->c_2);
	g->f_color = mlx_get_color_value(g->mlx_ptr, 65536 * s->f_0 + \
	256 * s->f_1 + s->f_2);
}

int			ft_img_init(t_source *s, t_graph *g)
{
	int		i;

	i = 0;
	ft_img_init_(s, g);
	while (i < 5)
	{
		(g->img[i])->ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		((g->img[i]->path)), &((g->img[i])->wth), &((g->img[i])->lth));
		if (!((g->img[i])->ptr))
			return (ft_error_int("Error in image of texture or sprite."));
		(g->img[i])->addr = mlx_get_data_addr(((g->img[i])->ptr), \
		&((g->img[i])->bpp), &((g->img[i])->sl), &((g->img[i])->endian));
		i++;
	}
	if (s->put_window == 1)
		ft_resolution_correct(s, g);
	(g->img[i])->ptr = mlx_new_image(g->mlx_ptr, \
	s->win_width, s->win_length);
	if (!((g->img[i])->ptr))
		return (ft_error_int("Error in image of window."));
	(g->img[i])->addr = mlx_get_data_addr(((g->img[i])->ptr), \
	&((g->img[i])->bpp), &((g->img[i])->sl), &((g->img[i])->endian));
	return (0);
}

int			ft_img_malloc(t_graph *g)
{
	int		i;

	i = 0;
	g->img = (t_img **)malloc(sizeof(t_img *) * 7);
	if (!g->img)
		return (1);
	g->img[6] = NULL;
	while (i < 6)
	{
		g->img[i] = (t_img *)malloc(sizeof(t_img));
		if (!(g->img[i]))
			return (1);
		i++;
	}
	return (0);
}

int			ft_make_window(t_source *s, t_graph *g)
{
	if (!(g->win_ptr = mlx_new_window(g->mlx_ptr, s->win_width, \
	s->win_length, "cub3d")))
	{
		ft_free_graph(g);
		return (ft_error_int("Can't create window with mlx."));
	}
	return (0);
}

t_graph		*ft_struct_g_init(t_source *s, t_graph *g)
{
	int		ret;

	ret = 0;
	if (!(g = (t_graph *)malloc(sizeof(t_graph))))
		return (NULL);
	g->win_ptr = NULL;
	g->mlx_ptr = NULL;
	g->img = NULL;
	if (!(g->mlx_ptr = mlx_init()))
	{
		ft_free_graph(g);
		return (ft_error_null("Can't initialize mlx."));
	}
	if (ft_img_malloc(g) == 1 || ft_img_init(s, g) == 1)
	{
		ft_free_graph(g);
		return (NULL);
	}
	if (s->put_window == 1)
	{
		if (ft_make_window(s, g) == 1)
			return (NULL);
	}
	return (g);
}
