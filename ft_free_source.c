/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:54:13 by shlu              #+#    #+#             */
/*   Updated: 2021/02/12 12:59:35 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	ft_free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_free_sp(t_source *s)
{
	int	i;

	i = 0;
	while (s->sp[i++])
		ft_free_ptr(s->sp[i - 1]);
	ft_free_ptr(s->sp);
}

void	ft_free_source(t_source *s)
{
	if (s)
	{
		if (s->path_no)
			ft_free_ptr(s->path_no);
		if (s->path_so)
			ft_free_ptr(s->path_so);
		if (s->path_we)
			ft_free_ptr(s->path_we);
		if (s->path_ea)
			ft_free_ptr(s->path_ea);
		if (s->path_sp)
			ft_free_ptr(s->path_sp);
		if (s->sp)
			ft_free_sp(s);
		if (s->map)
			ft_free_table(s->map, 0);
		ft_free_ptr(s);
	}
}
