/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:33:26 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/09 13:33:27 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		ft_deaw_ceiling_and_floor(t_system *sys)
{
	int		x;
	int		y;

	y = 0;
	while (y < sys->heigth / 2)
	{
		x = -1;
		while (++x < sys->width)
			my_mlx_pixel_put(&(sys->img), x, y, sys->parse->c);
		y++;
	}
	while (y < sys->heigth)
	{
		x = -1;
		while (++x < sys->width)
			my_mlx_pixel_put(&(sys->img), x, y, sys->parse->f);
		y++;
	}
}

void		ft_draw_wall_body(t_system *sys, t_player *ray, t_draw_wall *all)
{
	ray->count++;
	all->wall_height = 170000 / (ray->count * cos(ray->ang - sys->player.dir));
	all->wall_height *= (float)sys->width / 640;
	all->ceiling = (sys->heigth - all->wall_height) / 2;
	all->floor = all->ceiling + all->wall_height;
	if (ray->hor_ver == 'v')
		all->xmp_index_x = fmod(ray->x, SCALE) * 64 / SCALE;
	else
		all->xmp_index_x = fmod(ray->y, SCALE) * 64 / SCALE;
	ray->dir = 0;
	while (all->ceiling < 0)
	{
		ray->dir++;
		all->ceiling++;
	}
	ray->dir *= 64 / all->wall_height;
	ray->count = 0;
}

void		ft_draw_wall_cycle_body(t_system *sys, t_player ray,
				int line_index, t_draw_wall *all)
{
	if (ray.hor_ver == 'v' && sin(ray.ang) >= 0)
		my_mlx_pixel_put(&(sys->img), line_index, all->ceiling,
			ft_get_img_color(&(sys->img_so),
			abs(63 - all->xmp_index_x), all->xmp_index_y));
	else if (ray.hor_ver == 'v' && sin(ray.ang) < 0)
		my_mlx_pixel_put(&(sys->img), line_index, all->ceiling,
			ft_get_img_color(&(sys->img_no),
			all->xmp_index_x, all->xmp_index_y));
	else if (ray.hor_ver == 'h' && cos(ray.ang) < 0)
		my_mlx_pixel_put(&(sys->img), line_index, all->ceiling,
			ft_get_img_color(&(sys->img_we),
			abs(63 - all->xmp_index_x), all->xmp_index_y));
	else if (ray.hor_ver == 'h' && cos(ray.ang) >= 0)
		my_mlx_pixel_put(&(sys->img), line_index, all->ceiling,
			ft_get_img_color(&(sys->img_ea),
			all->xmp_index_x, all->xmp_index_y));
}

void		ft_draw_wall(t_system *sys, t_player ray, int line_index)
{
	t_draw_wall	all;

	ft_draw_wall_body(sys, &ray, &all);
	while (all.ceiling <= all.floor && all.ceiling < sys->heigth)
	{
		all.xmp_index_y = ray.count * 64 / all.wall_height + ray.dir;
		if (all.xmp_index_y < 0)
			all.xmp_index_y = 0;
		if (all.xmp_index_x < 0)
			all.xmp_index_x = 0;
		if (all.xmp_index_y >= 64)
			all.xmp_index_y = 63;
		if (all.xmp_index_x >= 64)
			all.xmp_index_x = 63;
		ft_draw_wall_cycle_body(sys, ray, line_index, &all);
		ray.count++;
		all.ceiling++;
	}
}

int			ft_map_creator(char **map, t_parse *parse)
{
	t_system	sys;

	sys.mlx = mlx_init();
	ft_check_resolution(&sys, parse);
	sys.width = parse->r[0];
	sys.heigth = parse->r[1];
	sys.img.img = mlx_new_image(sys.mlx, parse->r[0], parse->r[1]);
	sys.img.addr = mlx_get_data_addr(sys.img.img, &sys.img.bits_per_pixel,
								&sys.img.line_length, &sys.img.endian);
	sys.parse = parse;
	sys.sprites = NULL;
	ft_init_textures(&sys);
	ft_init_map(&sys, map);
	ft_init_player(&(sys.player), parse, map);
	ft_first_frame(&sys);
	mlx_hook(sys.win, 17, 0L, window_exit, &sys);
	mlx_hook(sys.win, 2, (1L << 0), key_hook, &sys);
	mlx_loop(sys.mlx);
	return (1);
}
