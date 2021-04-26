/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_bmp_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:06:34 by shlu              #+#    #+#             */
/*   Updated: 2021/02/14 14:06:38 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_win_signature(int fd)
{
	char	str[2];

	str[0] = (char)(0x42);
	str[1] = (char)(0x4d);
	write(fd, str, 2);
}

void		ft_win_img_size(int fd, int size)
{
	char	str[4];

	str[0] = (char)(size & 0xff);
	str[1] = (char)(size >> 8 & 0xff);
	str[2] = (char)(size >> 16 & 0xff);
	str[3] = (char)(size >> 24 & 0xff);
	write(fd, str, 4);
}

void		ft_win_app_sign(int fd, int sign1, int sign2)
{
	char	str[2];

	str[0] = (unsigned char)(sign1 & 0xff);
	str[1] = (unsigned char)(sign1 >> 8 & 0xff);
	write(fd, str, 2);
	str[0] = (unsigned char)(sign2 & 0xff);
	str[1] = (unsigned char)(sign2 >> 8 & 0xff);
	write(fd, str, 2);
}

void		ft_win_offset(int fd, unsigned int off)
{
	char	str[4];

	str[0] = (char)(off & 0xff);
	str[1] = (char)(off >> 8 & 0xff);
	str[2] = (char)(off >> 16 & 0xff);
	str[3] = (char)(off >> 24 & 0xff);
	write(fd, str, 4);
}

void		ft_win_dup(int fd, int dup)
{
	char	str[4];

	str[0] = (unsigned char)(dup & 0xff);
	str[1] = (unsigned char)(dup >> 8 & 0xff);
	str[2] = (unsigned char)(dup >> 16 & 0xff);
	str[3] = (unsigned char)(dup >> 24 & 0xff);
	write(fd, str, 4);
}
