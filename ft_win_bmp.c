/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:30:53 by shlu              #+#    #+#             */
/*   Updated: 2021/02/14 12:30:56 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void		ft_win_size_xy(int fd, unsigned int x, unsigned int y)
{
	char	screen_xy[4];

	screen_xy[0] = (unsigned char)(x & 0xff);
	screen_xy[1] = (unsigned char)(x >> 8 & 0xff);
	screen_xy[2] = (unsigned char)(x >> 16 & 0xff);
	screen_xy[3] = (unsigned char)(x >> 24 & 0xff);
	write(fd, screen_xy, 4);
	screen_xy[0] = (unsigned char)(y & 0xff);
	screen_xy[1] = (unsigned char)(y >> 8 & 0xff);
	screen_xy[2] = (unsigned char)(y >> 16 & 0xff);
	screen_xy[3] = (unsigned char)(y >> 24 & 0xff);
	write(fd, screen_xy, 4);
}

void		ft_win_header(int fd)
{
	char	zero;
	char	fill;
	char	z5[5];

	z5[0] = '\0';
	z5[1] = '\0';
	z5[2] = '\0';
	z5[3] = '\0';
	z5[4] = '\0';
	zero = '\0';
	fill = 1;
	write(fd, &fill, 1);
	write(fd, &zero, 1);
	fill = 0x18;
	write(fd, &fill, 1);
	write(fd, &z5, 5);
	fill = 0x10;
	write(fd, &fill, 1);
	write(fd, z5, 5);
	write(fd, z5, 5);
	write(fd, z5, 5);
	write(fd, z5, 4);
}

void		ft_win_addr(int fd, unsigned char *addr, int size, int win_w)
{
	char	str[4];
	int		i;
	int		len;

	len = (4 - ((win_w) * 3) % 4) % 4;
	ft_memset(str, 0, 4);
	i = 0;
	while (i < size)
	{
		write(fd, addr, win_w * 3);
		if (len)
			write(fd, str, len);
		i += win_w * 3;
		addr += win_w * 3;
	}
}

int			ft_win_bmp(int win_w, int win_l, char *file_name, \
						unsigned char *addr)
{
	int		fd;
	int		img_size;

	fd = open(file_name, O_CREAT | O_RDWR, S_IRWXU | S_IRGRP | S_IROTH);
	if (fd == 0)
		return (1);
	img_size = win_w * win_l * 3 + win_l * (win_w % 4);
	ft_win_signature(fd);
	ft_win_img_size(fd, 0x36 + img_size);
	ft_win_app_sign(fd, 0x7543, 0x4433);
	ft_win_offset(fd, 0x36);
	ft_win_dup(fd, 0x28);
	ft_win_size_xy(fd, win_w, win_l);
	ft_win_header(fd);
	ft_win_addr(fd, addr, img_size, win_w);
	close(fd);
	return (0);
}
