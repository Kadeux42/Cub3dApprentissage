/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifier_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:35:47 by shlu              #+#    #+#             */
/*   Updated: 2021/04/23 15:35:49 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int			ft_identifier_check(t_source *s)
{
	if (s->win_width == 0 || s->win_length == 0)
		return (ft_error_int("Invalid argument for resolution."));
	if (s->path_no == NULL || s->path_so == NULL || s->path_we == NULL \
		|| s->path_ea == NULL || s->path_sp == NULL)
		return (ft_error_int("Parameter of texture or sprite insufficient."));
	if (s->c_0 == -1 || s->c_1 == -1 || s->c_2 == -1)
		return (ft_error_int("Parameter of C insufficient."));
	if (s->f_0 == -1 || s->f_1 == -1 || s->f_2 == -1)
		return (ft_error_int("Parameter of F insufficient."));
	if (s->map_start_line == -1)
		return (ft_error_int("No map avaliable."));
	return (0);
}
