/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:15:09 by shlu              #+#    #+#             */
/*   Updated: 2021/02/15 22:15:12 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int				ft_map_check_side(char mid, char side)
{
	if (mid == ' ')
		if (side != '1' && side != ' ' && side != '\0')
			return (1);
	if (mid == '0' || mid == '2' || mid == 'N' || mid == 'S' || \
		mid == 'E' || mid == 'W')
		if (side == ' ' || side == '\0')
			return (1);
	return (0);
}

int				ft_map_check_no(char mid)
{
	if (mid == '0' || mid == '2' || mid == 'N' || mid == 'S' || \
		mid == 'E' || mid == 'W')
		return (1);
	return (0);
}
