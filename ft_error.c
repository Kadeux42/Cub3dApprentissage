/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:53:56 by shlu              #+#    #+#             */
/*   Updated: 2021/02/05 21:54:01 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	*ft_error_null(char *str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(str, 1);
	return (NULL);
}

int		ft_error_int(char *str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(str, 1);
	return (1);
}
