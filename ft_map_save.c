/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:56:07 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 15:02:43 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int				ft_map_save_(t_source *s, char *line)
{
	static int	doc_line = 0;
	static int	map_line = 0;

	if (doc_line++ >= (s->map_start_line))
	{
		if (ft_map_id(line, s) == 1)
			return (1);
		*(s->map + map_line++) = ft_strdup(line);
	}
	return (0);
}

int				ft_map_save_gate(t_source *s, char *line, int fd, \
				int map_total_line)
{
	static int	i = 0;

	if (i == 0)
	{
		while (i <= map_total_line)
			*(s->map + i++) = NULL;
	}
	if (ft_map_save_(s, line) == 1)
	{
		ft_free_ptr(line);
		close(fd);
		return (1);
	}
	return (0);
}

int				ft_map_save(t_source *s, char *scene_file)
{
	int		fd;
	int		map_total_line;
	char	*line;

	map_total_line = s->total_line - s->map_start_line;
	fd = open(scene_file, O_RDWR);
	if (fd < 0 || map_total_line < 3)
		return (ft_error_int("Invalid map."));
	if (!(s->map = (char **)malloc(sizeof(char *) * (map_total_line + 1))))
	{
		close(fd);
		return (1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_map_save_gate(s, line, fd, map_total_line) == 1)
			return (1);
		ft_free_ptr(line);
	}
	ft_map_save_(s, line);
	ft_free_ptr(line);
	close(fd);
	return (0);
}
