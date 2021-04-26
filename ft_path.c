/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:38:36 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 13:02:50 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int			ft_path_(t_source *s, char *line, int id, int j)
{
	if (id == 'n' && s->path_no == NULL)
		s->path_no = ft_strdup(line + j);
	else if (id == 's' && s->path_so == NULL)
		s->path_so = ft_strdup(line + j);
	else if (id == 'w' && s->path_we == NULL)
		s->path_we = ft_strdup(line + j);
	else if (id == 'e' && s->path_ea == NULL)
		s->path_ea = ft_strdup(line + j);
	else if (id == 'p' && s->path_sp == NULL)
		s->path_sp = ft_strdup(line + j);
	else
		return (1);
	return (0);
}

int			ft_path(t_source *s, char *line, int id)
{
	char	**table;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(line + j) == 32)
		j++;
	table = ft_split((line + j), ' ');
	while (table[i])
		i++;
	if (i == 1)
	{
		if (ft_path_(s, line, id, j) == 1)
		{
			ft_free_table(table, i);
			return (ft_error_int("Multiple assignments for texture."));
		}
	}
	if (ft_free_table(table, i) != 1)
		return (ft_error_int("Wrong number of arguements for texture."));
	else
		return (0);
}
