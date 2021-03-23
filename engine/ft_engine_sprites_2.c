/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_sprites_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:26:18 by yzombie           #+#    #+#             */
/*   Updated: 2021/03/21 13:26:19 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		ft_draw_sprites_cycle_body(t_system *sys, t_draw_sprites *all)
{
	while (all->ceiling <= all->floor && all->ceiling < sys->heigth)
	{
		all->xmp_index_y = all->win_y * 64 / all->wall_height + all->offset;
		if (all->xmp_index_y < 0)
			all->xmp_index_y = 0;
		if (all->xmp_index_x < 0)
			all->xmp_index_x = 0;
		if (all->xmp_index_y >= 64)
			all->xmp_index_y = 63;
		if (all->xmp_index_x >= 64)
			all->xmp_index_x = 63;
		all->color = ft_get_img_color(&(sys->img_sprites),
			all->xmp_index_x, all->xmp_index_y);
		if (all->color != 9961608)
			my_mlx_pixel_put(&(sys->img), all->win_x, all->ceiling, all->color);
		all->win_y++;
		all->ceiling++;
	}
}

void		ft_draw_sprites_calculations(t_system *sys,
				t_sprite *sprite, t_draw_sprites *all)
{
	sprite->count++;
	all->wall_height = 170000 / (sprite->count
		* cos(sprite->ang - sys->player.dir));
	all->wall_height *= (float)sys->width / 640;
	all->ceiling = (sys->heigth - all->wall_height) / 2;
	all->floor = all->ceiling + all->wall_height;
	all->offset = 0;
	while (all->ceiling < 0)
	{
		all->offset++;
		all->ceiling++;
	}
	all->offset *= 64 / all->wall_height;
	all->start = all->ceiling;
	all->win_x = sprite->index - all->wall_height / 2;
	if (all->win_x < 0)
		all->win_x = 0;
}

void		ft_draw_sprites(t_system *sys, t_sprite *sprite)
{
	t_draw_sprites all;

	ft_draw_sprites_calculations(sys, sprite, &all);
	while (all.win_x < sprite->index
		+ all.wall_height / 2 && all.win_x < sys->width)
	{
		if (sys->walls[all.win_x] < sprite->count)
		{
			all.win_x++;
			continue;
		}
		all.ceiling = all.start;
		all.win_y = 0;
		all.xmp_index_x = (all.win_x - (sprite->index
			- all.wall_height / 2)) * 64 / all.wall_height;
		ft_draw_sprites_cycle_body(sys, &all);
		all.win_x++;
	}
}

void		ft_sort_body(t_list_sort *all)
{
	while (all->tmp2 != NULL)
	{
		if (all->tmp2->count > all->max)
		{
			all->max = all->tmp2->count;
			all->pred->next = all->tmp2->next;
			all->tmp2->next = (*all->tmp1);
			(*all->tmp1) = all->tmp2;
			all->tmp2 = all->tmp2->next;
			all->pred = (*all->tmp1);
			continue;
		}
		all->tmp2 = all->tmp2->next;
		all->pred = all->pred->next;
	}
}

void		ft_list_sort(t_sprite **sprites)
{
	t_list_sort all;

	all.size = ft_list_size(*sprites);
	all.i = 1;
	while (all.i <= all.size)
	{
		all.tmp1 = sprites;
		all.j = 0;
		while (++all.j < all.i)
			all.tmp1 = &((*all.tmp1)->next);
		all.max = (*all.tmp1)->count;
		all.tmp2 = (*all.tmp1)->next;
		all.pred = (*all.tmp1);
		ft_sort_body(&all);
		all.i++;
	}
}
