/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:08:29 by shlu              #+#    #+#             */
/*   Updated: 2021/02/13 18:08:35 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int			ft_struct_init(t_cub *c, char *scene_file, int argc, char **argv)
{
	c->lkeys = NULL;
	c->s = ft_struct_s_init(scene_file, c->s);
	if (!(c->s))
	{
		ft_putendl_fd("Error in .cub file.", 1);
		return (1);
	}
	ft_screenshot_detect(argc, argv, c);
	c->g = ft_struct_g_init(c->s, c->g);
	if (!(c->g))
	{
		ft_putendl_fd("Error in structure graph.", 1);
		return (1);
	}
	c->r = ft_struct_r_init(c->s, c->r);
	if (!(c->r))
	{
		ft_putendl_fd("Error in structure ray.", 1);
		return (1);
	}
	if ((c->s)->put_window == 0)
		ft_screenshot_handle(c);
	return (0);
}

void		init_lkeys(t_cub *c)
{
	int	*first_node;

	c->lkeys = NULL;
	first_node = malloc(sizeof(int));
	*first_node = -1;
	ft_lstadd_back(&c->lkeys, ft_lstnew(first_node));
}

t_cub		*ft_cub3d_init(char *scene_file, int argc, char **argv)
{
	t_cub	*c;
	int		ret;

	ret = 0;
	c = NULL;
	c = (t_cub *)malloc(sizeof(t_cub));
	if (!c)
	{
		ft_error_null("Error in struct cub.\n");
		return (NULL);
	}
	c->s = NULL;
	c->g = NULL;
	c->r = NULL;
	c->lkeys = NULL;
	if (ft_struct_init(c, scene_file, argc, argv) == 1)
	{
		ft_free_all_struct(c);
		return (NULL);
	}
	init_lkeys(c);
	return (c);
}
