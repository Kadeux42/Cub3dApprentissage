/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:15:09 by shlu              #+#    #+#             */
/*   Updated: 2021/02/15 22:15:12 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int				ft_map_check_next_line(t_source *s, size_t x, size_t y)
{
	if (s->map[y + 1])
	{
		if (ft_strlen(s->map[y + 1]) >= x)
		{
			if (ft_map_check_side(s->map[y][x], s->map[y + 1][x]))
				return (1);
		}
		else
		{
			if (ft_map_check_no(s->map[y][x]) == 1)
				return (1);
		}
	}
	else
	{
		if (ft_map_check_no(s->map[y][x]) == 1)
			return (1);
	}
	return (0);
}

int				ft_map_check_last_line(t_source *s, size_t x, size_t y)
{
	if (ft_strlen(s->map[y - 1]) >= x)
	{
		if (ft_map_check_side(s->map[y][x], s->map[y - 1][x]) == 1)
			return (1);
	}
	else
	{
		if (ft_map_check_no(s->map[y][x]) == 1)
			return (1);
	}
	return (0);
}

int				ft_map_check_last_column(t_source *s, size_t x, size_t y)
{
	if (s->map[y][x] == 'N' || s->map[y][x] == 'S' || \
			s->map[y][x] == 'W' || s->map[y][x] == 'E')
	{
		s->px = x + .5;
		s->py = y + .5;
	}
	if (x != 0)
	{
		if (ft_map_check_side(s->map[y][x], s->map[y][x - 1]) == 1)
			return (1);
	}
	else
	{
		if (ft_map_check_no(s->map[y][x]) == 1)
			return (1);
	}
	return (0);
}

int				ft_map_check_first_line(t_source *s)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (s->map[y][x] != '\0')
	{
		if (s->map[y][x] == '0' || s->map[y][x] == '2' || s->map[y][x] == 'N' \
			|| s->map[y][x] == 'S' || s->map[y][x] == 'W' \
			|| s->map[y][x] == 'E')
			return (1);
		x++;
	}
	return (0);
}

int				ft_map_check(t_source *s)
{
	size_t		x;
	size_t		y;

	y = 1;
	if (ft_map_check_first_line(s))
		return (1);
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x] != '\0')
		{
			if (ft_map_check_side(s->map[y][x], s->map[y][x + 1]))
				return (1);
			if (ft_map_check_last_column(s, x, y) == 1)
				return (1);
			if (ft_map_check_last_line(s, x, y) == 1)
				return (1);
			if (ft_map_check_next_line(s, x, y) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
