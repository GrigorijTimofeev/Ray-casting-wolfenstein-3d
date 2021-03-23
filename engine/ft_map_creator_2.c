/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:58:33 by yzombie           #+#    #+#             */
/*   Updated: 2021/03/20 18:58:34 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		key_hook_continue(int keycode, t_system *sys, int speed)
{
	if (keycode == 1)
	{
		sys->player.x += cos(sys->player.dir - PI) * speed;
		sys->player.y += sin(sys->player.dir - PI) * speed;
	}
	if (keycode == 123)
		sys->player.dir -= 0.08;
	if (keycode == 124)
		sys->player.dir += 0.08;
	if (keycode == 53)
		exit(0);
	ft_deaw_ceiling_and_floor(sys);
	ft_put_ray(sys);
	ft_put_ray_sprite(sys);
	ft_free_sprites(&(sys->sprites));
	mlx_put_image_to_window(sys->mlx, sys->win, sys->img.img, 0, 0);
	mlx_do_sync(sys->mlx);
}

int			key_hook(int keycode, t_system *sys)
{
	int		speed;

	speed = 50;
	if (keycode == 0)
	{
		sys->player.x += cos(sys->player.dir - PI / 2) * speed;
		sys->player.y += sin(sys->player.dir - PI / 2) * speed;
	}
	if (keycode == 2)
	{
		sys->player.x -= cos(sys->player.dir - PI / 2) * speed;
		sys->player.y -= sin(sys->player.dir - PI / 2) * speed;
	}
	if (keycode == 13)
	{
		sys->player.x -= cos(sys->player.dir - PI) * speed;
		sys->player.y -= sin(sys->player.dir - PI) * speed;
	}
	key_hook_continue(keycode, sys, speed);
	return (0);
}

void		ft_first_frame(t_system *sys)
{
	ft_deaw_ceiling_and_floor(sys);
	ft_put_ray(sys);
	ft_put_ray_sprite(sys);
	ft_free_sprites(&(sys->sprites));
	if (sys->parse->save == 1)
		ft_put_img_to_bmp(sys);
	sys->win = mlx_new_window(sys->mlx, sys->width, sys->heigth, "cub.3d");
	mlx_put_image_to_window(sys->mlx, sys->win, sys->img.img, 0, 0);
	mlx_do_sync(sys->mlx);
}

void		ft_init_textures_2(t_system *sys)
{
	sys->img_ea.img = mlx_xpm_file_to_image(
		sys->mlx, sys->parse->ea, &sys->img_ea.line_length,
		&sys->img_ea.endian);
	if (!sys->img_ea.img)
		ft_textures_error();
	sys->img_ea.addr = mlx_get_data_addr(
		sys->img_ea.img, &sys->img_ea.bits_per_pixel,
		&sys->img_ea.line_length, &sys->img_ea.endian);
	sys->img_we.img = mlx_xpm_file_to_image(
		sys->mlx, sys->parse->we,
		&sys->img_we.line_length, &sys->img_we.endian);
	if (!sys->img_we.img)
		ft_textures_error();
	sys->img_we.addr = mlx_get_data_addr(
		sys->img_we.img, &sys->img_we.bits_per_pixel,
		&sys->img_we.line_length, &sys->img_we.endian);
	sys->img_sprites.img = mlx_xpm_file_to_image(
		sys->mlx, sys->parse->s,
		&sys->img_sprites.line_length, &sys->img_sprites.endian);
	if (!sys->img_sprites.img)
		ft_textures_error();
	sys->img_sprites.addr = mlx_get_data_addr(
		sys->img_sprites.img, &sys->img_sprites.bits_per_pixel,
		&sys->img_sprites.line_length, &sys->img_sprites.endian);
}

void		ft_init_textures(t_system *sys)
{
	sys->img_no.img = mlx_xpm_file_to_image(
		sys->mlx, sys->parse->no,
		&sys->img_no.line_length, &sys->img_no.endian);
	if (!sys->img_no.img)
		ft_textures_error();
	sys->img_no.addr = mlx_get_data_addr(
		sys->img_no.img, &sys->img_no.bits_per_pixel,
		&sys->img_no.line_length, &sys->img_no.endian);
	sys->img_so.img = mlx_xpm_file_to_image(
		sys->mlx, sys->parse->so,
		&sys->img_so.line_length, &sys->img_so.endian);
	if (!sys->img_so.img)
		ft_textures_error();
	sys->img_so.addr = mlx_get_data_addr(
		sys->img_so.img, &sys->img_so.bits_per_pixel,
		&sys->img_so.line_length, &sys->img_so.endian);
	ft_init_textures_2(sys);
}
