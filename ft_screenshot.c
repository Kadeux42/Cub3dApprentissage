/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:30:21 by shlu              #+#    #+#             */
/*   Updated: 2021/02/14 12:30:32 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

unsigned char		*ft_bmp_addr(t_source *s, char *addr, int data_size)
{
	unsigned char	*data;
	int				i;
	int				j;
	int				k;
	int				rls;

	if (!(data = (unsigned char *)malloc(sizeof(unsigned char) * data_size)))
		return (NULL);
	i = 0;
	j = s->win_width * s->win_length * 3 - 1;
	rls = s->win_width * 4;
	k = 0;
	while (k < s->win_length)
	{
		i = rls - 1;
		while (i >= 0)
		{
			data[j--] = addr[k * rls + --i];
			data[j--] = addr[k * rls + --i];
			data[j--] = addr[k * rls + --i];
			i--;
		}
		k++;
	}
	return (data);
}

int					ft_screenshot(t_source *s, t_graph *g)
{
	int				data_size;
	unsigned char	*addr;

	data_size = s->win_width * s->win_length * 4 \
		+ s->win_length * (s->win_width % 4);
	addr = ft_bmp_addr(s, ((g->img)[5])->addr, data_size);
	if (addr == NULL)
		return (ft_error_int("Problem with the screenshot.\n"));
	ft_win_bmp(s->win_width, s->win_length, "screenshot.bmp", addr);
	ft_free_ptr(addr);
	return (0);
}
