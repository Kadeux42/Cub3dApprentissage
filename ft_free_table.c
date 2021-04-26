/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:54:26 by shlu              #+#    #+#             */
/*   Updated: 2021/02/11 17:05:31 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int		ft_free_table(char **table, int ret)
{
	int	i;

	i = 0;
	if (table)
	{
		while (*(table + i))
			i++;
		while (i > -1)
		{
			if (*(table + i))
				free(*(table + i));
			i--;
		}
		free(table);
	}
	return (ret);
}
