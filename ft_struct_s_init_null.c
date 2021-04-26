/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_s_init_null.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:35:01 by shlu              #+#    #+#             */
/*   Updated: 2021/04/23 15:35:35 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_struct_s_init_null(t_source *s)
{
	s->total_line = 0;
	s->map_start_line = -1;
	s->win_width = 0;
	s->win_length = 0;
	s->path_no = NULL;
	s->path_so = NULL;
	s->path_we = NULL;
	s->path_ea = NULL;
	s->path_sp = NULL;
	s->c_0 = -1;
	s->c_1 = -1;
	s->c_2 = -1;
	s->f_0 = -1;
	s->f_1 = -1;
	s->f_2 = -1;
	s->sp_num = 0;
	s->sp = NULL;
	s->map = NULL;
	s->person_num = 0;
	s->put_window = 1;
}
