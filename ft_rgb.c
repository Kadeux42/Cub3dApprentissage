/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:39:21 by shlu              #+#    #+#             */
/*   Updated: 2021/04/19 11:28:07 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int				ft_put_rgb(t_source *s, int id, char **table)
{
	if (id == 'c')
	{
		s->c_0 = ft_atoi(table[0]);
		s->c_1 = ft_atoi(table[1]);
		s->c_2 = ft_atoi(table[2]);
		if (s->c_0 < 0 || s->c_1 < 0 || s->c_2 < 0)
			return (ft_error_int("Argument of ceiling is out of RGB range."));
		if (s->c_0 > 255 || s->c_1 > 255 || s->c_2 > 255)
			return (ft_error_int("Argument of ceiling is out of RGB range."));
	}
	else if (id == 'f')
	{
		s->f_0 = ft_atoi(table[0]);
		s->f_1 = ft_atoi(table[1]);
		s->f_2 = ft_atoi(table[2]);
		if (s->f_0 < 0 || s->f_1 < 0 || s->f_2 < 0)
			return (ft_error_int("Argument of floor is out of RGB range."));
		if (s->f_0 > 255 || s->f_1 > 255 || s->f_2 > 255)
			return (ft_error_int("Argument of floor is out of RGB range."));
	}
	else
		return (1);
	return (0);
}

int				ft_table_isnum(char **table, int id)
{
	int			i;
	int			j;

	i = 0;
	while (*(table + i))
	{
		j = 0;
		while (*(*(table + i) + j) != '\0')
		{
			if ('0' <= *(*(table + i) + j) && *(*(table + i) + j) <= '9')
				j++;
			else
			{
				if (id == 'c')
					ft_error_int("Argument is invalid in ceiling.");
				if (id == 'f')
					ft_error_int("Argument is invalid in floor.");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int				ft_rgb_(t_source *s, char **table, int id)
{
	int			i;
	char		**correct;

	i = 0;
	if (!(correct = (char **)malloc(sizeof(char *) * 4)))
	{
		ft_free_table(table, 3);
		return (1);
	}
	*(correct + 3) = NULL;
	while (*(table + i) != NULL)
	{
		*(correct + i) = ft_strtrim(*(table + i), " ");
		i++;
	}
	if (ft_table_isnum(correct, id) == 1 || ft_put_rgb(s, id, correct) == 1)
	{
		ft_free_table(table, i);
		ft_free_table(correct, i);
		return (1);
	}
	ft_free_table(correct, i);
	return (0);
}

int				ft_rgb(t_source *s, char *line, int id)
{
	char		**table;
	static int	c = 0;
	static int	f = 0;
	int			i;

	i = 0;
	if (id == 'c')
		c++;
	else
		f++;
	if (c >= 2 || f >= 2)
		return (ft_error_int("Multiple assignments for C or F."));
	while (*(line + i) == 32)
		i++;
	table = ft_split((line + i), ',');
	i = 0;
	while (*(table + i))
		i++;
	if (i == 3)
		if (ft_rgb_(s, table, id) == 1)
			return (1);
	if (ft_free_table(table, i) != 3)
		return (ft_error_int("Wrong number of arguments for C or F."));
	else
		return (0);
}
