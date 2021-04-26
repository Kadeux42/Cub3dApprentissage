/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:39:34 by shlu              #+#    #+#             */
/*   Updated: 2021/02/17 19:20:12 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int		ft_identifier(t_source *s, char *line)
{
	if (!line)
		return (1);
	else
	{
		if (ft_strnstr(line, "R \0", 3))
			return (ft_r(s, (line + 2)));
		else if (ft_strnstr(line, "NO \0", 4))
			return (ft_path(s, (line + 3), 'n'));
		else if (ft_strnstr(line, "SO \0", 4))
			return (ft_path(s, (line + 3), 's'));
		else if (ft_strnstr(line, "WE \0", 4))
			return (ft_path(s, (line + 3), 'w'));
		else if (ft_strnstr(line, "EA \0", 4))
			return (ft_path(s, (line + 3), 'e'));
		else if (ft_strnstr(line, "S \0", 3))
			return (ft_path(s, (line + 2), 'p'));
		else if (ft_strnstr(line, "F \0", 3))
			return (ft_rgb(s, (line + 2), 'f'));
		else if (ft_strnstr(line, "C \0", 3))
			return (ft_rgb(s, (line + 2), 'c'));
		else if (ft_strncmp(line, "\0", 1) == 0)
			return (0);
		else
			return (ft_map_count_line(s));
	}
}
