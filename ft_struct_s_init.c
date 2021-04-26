/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_s_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:39:34 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 13:27:38 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int			ft_pre_identifier_(t_source *s, char *line, int fd)
{
	if (ft_identifier(s, line) == 1)
	{
		ft_free_ptr(line);
		close(fd);
		return (1);
	}
	return (0);
}

int			ft_pre_identifier(char *scene_file, t_source *s)
{
	int		fd;
	char	*line;

	fd = open(scene_file, O_RDWR);
	if (fd < 0)
		return (ft_error_int("Can't open the .cub file."));
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_pre_identifier_(s, line, fd) == 1)
			return (1);
		s->total_line++;
		ft_free_ptr(line);
	}
	if (ft_pre_identifier_(s, line, fd) == 1)
		return (1);
	ft_free_ptr(line);
	s->total_line++;
	close(fd);
	return (0);
}

int			ft_struct_s_init_(char *scene_file, t_source *s)
{
	if (ft_pre_identifier(scene_file, s) == 1)
		return (1);
	if (ft_identifier_check(s) == 1)
		return (1);
	if (ft_map_save(s, scene_file) == 1)
		return (1);
	if (s->person_num != 1)
		return (ft_error_int("Invalid number of people in map."));
	if (ft_sp_malloc(s) == 1)
		return (1);
	ft_sprite_data(s);
	if (ft_map_check(s) == 1)
		return (ft_error_int("Invalid map."));
	return (0);
}

t_source	*ft_struct_s_init(char *scene_file, t_source *s)
{
	int		ret;
	char	*file_type;

	ret = 0;
	file_type = ft_strrchr(scene_file, '.');
	if (file_type == NULL || ft_strncmp(file_type, ".cub\0", 5) != 0)
		return (ft_error_null("Error in first argument."));
	s = (t_source *)malloc(sizeof(t_source));
	if (!s)
		return (NULL);
	ft_struct_s_init_null(s);
	if (ft_struct_s_init_(scene_file, s) == 1)
	{
		ft_free_source(s);
		return (NULL);
	}
	return (s);
}
