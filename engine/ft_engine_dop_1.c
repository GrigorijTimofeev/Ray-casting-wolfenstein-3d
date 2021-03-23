/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics_dop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:57:35 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/19 11:57:36 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	ft_textures_error(void)
{
	ft_putstr_fd("Error\nInvalid path to texture\n", 2);
	exit(1);
}

int		ft_get_img_color(t_data *data, int x, int y)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	return (*(unsigned int*)dst);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int*)dst = colour;
}

int		window_exit(t_system *sys)
{
	(void)sys;
	exit(0);
	return (0);
}

void	ft_init_map(t_system *sys, char **map)
{
	int			map_width;
	int			map_heigth;

	sys->map = map;
	map_width = 0;
	map_heigth = 0;
	while (sys->map[0][map_width])
		map_width++;
	while (sys->map[map_heigth])
		map_heigth++;
	sys->walls = malloc(sizeof(int) * sys->width);
	if (!sys->walls)
		ft_malloc_error();
}
