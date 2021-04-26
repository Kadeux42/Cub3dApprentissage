/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:37:30 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 15:02:52 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int				ft_map_id_(char *line, t_source *s, int i)
{
	if (*(line + i) == '0' || *(line + i) == '1' || *(line + i) == ' ')
		i++;
	else if (*(line + i) == '2')
	{
		i++;
		s->sp_num++;
	}
	return (i);
}

int				ft_map_id(char *line, t_source *s)
{
	int			i;

	i = 0;
	while (*(line + i) != '\0')
	{
		if (ft_map_id_(line, s, i) > i)
			i++;
		else if (*(line + i) == 'N' || *(line + i) == 'S' \
				|| *(line + i) == 'E' || *(line + i) == 'W')
		{
			s->person_num += 1;
			s->orientation = *(line + i);
			i++;
		}
		else
			return (ft_error_int("Wrong component in map."));
	}
	return (0);
}
