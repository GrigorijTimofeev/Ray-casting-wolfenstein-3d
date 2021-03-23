/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:01:14 by yzombie           #+#    #+#             */
/*   Updated: 2021/03/16 16:01:15 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	ft_file_error(void)
{
	ft_putstr_fd("Error\nFile creation error\n", 2);
	exit(1);
}

void	ft_put_header(unsigned char *file, unsigned char *info, t_system *sys)
{
	int		size;

	size = sys->width * sys->heigth * sys->img.bits_per_pixel / 8;
	file[0] = 'B';
	file[1] = 'M';
	file[2] = size;
	file[3] = size >> 8;
	file[4] = size >> 16;
	file[5] = size >> 24;
	file[10] = 54;
	info[0] = 40;
	info[4] = sys->width;
	info[5] = sys->width >> 8;
	info[6] = sys->width >> 16;
	info[7] = sys->width >> 24;
	info[8] = sys->heigth;
	info[9] = sys->heigth >> 8;
	info[10] = sys->heigth >> 16;
	info[11] = sys->heigth >> 24;
	info[12] = 1;
	info[14] = sys->img.bits_per_pixel;
}

void	ft_put_pixels(int fd, t_system *sys)
{
	int				w;
	int				h;
	int				colour;
	unsigned char	hex[4];

	h = sys->heigth - 1;
	while (h >= 0)
	{
		w = 0;
		while (w < sys->width)
		{
			colour = ft_get_img_color(&(sys->img), w, h);
			ft_bzero(hex, 4);
			hex[0] = colour;
			hex[1] = colour >> 8;
			hex[2] = colour >> 16;
			write(fd, &hex, 4);
			w++;
		}
		h--;
	}
	write(fd, "00", 2);
}

void	ft_put_img_to_bmp(t_system *sys)
{
	unsigned char	file[14];
	unsigned char	info[40];
	int				fd;

	ft_bzero(info, 40);
	ft_bzero(file, 14);
	ft_put_header(file, info, sys);
	if ((fd = open("image.bmp", O_RDWR | O_CREAT | O_TRUNC, 0777)) < 0)
		ft_file_error();
	write(fd, &file, 14);
	write(fd, &info, 40);
	ft_put_pixels(fd, sys);
	close(fd);
	exit(0);
}
