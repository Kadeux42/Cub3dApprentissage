/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:40:12 by shlu              #+#    #+#             */
/*   Updated: 2021/02/11 17:11:27 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_screenshot_detect(int argc, char **argv, t_cub *c)
{
	if (argc == 3)
	{
		if (ft_strncmp(*(argv + 2), "--save\0", 7) == 0)
			(c->s)->put_window = 0;
		else
		{
			ft_error_null("Wrong screenshot argument.");
			ft_free_all_struct(c);
		}
	}
}

void		ft_screenshot_handle(t_cub *c)
{
	ft_graphics(c);
	ft_screenshot(c->s, c->g);
	ft_free_all_struct(c);
}

int			main(int argc, char **argv)
{
	t_cub	*c;

	c = NULL;
	if (argc == 1 || argc > 3)
		return (ft_error_int("Wrong number of arguments."));
	c = ft_cub3d_init(*(argv + 1), argc, argv);
	if (!c)
		return (1);
	if ((c->s)->put_window == 1)
	{
		mlx_loop_hook(((c->g)->mlx_ptr), &ft_graphics, c);
		mlx_hook(c->g->win_ptr, 2, 1L << 0, &ft_key_pressed, c);
		mlx_hook(c->g->win_ptr, 3, 1L << 1, &ft_key_released, c);
		mlx_hook(c->g->win_ptr, 33, 1L << 17, &ft_free_all_struct, c);
		mlx_loop((c->g)->mlx_ptr);
	}
	return (0);
}
