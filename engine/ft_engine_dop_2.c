/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_dop_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:33:32 by yzombie           #+#    #+#             */
/*   Updated: 2021/03/20 18:33:33 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	ft_check_resolution(t_system *sys, t_parse *parse)
{
	t_point		screen;

	mlx_get_screen_size(sys->mlx, &(screen.x), &(screen.y));
	if (parse->r[0] <= 0 || parse->r[1] <= 0)
		ft_map_error();
	if (parse->r[0] > screen.x)
		parse->r[0] = screen.x;
	if (parse->r[1] > screen.y)
		parse->r[1] = screen.y;
}

void	ft_init_direction(t_player *player, t_parse *parse)
{
	if (parse->player == 'N')
		player->dir = PI * 3 / 2;
	if (parse->player == 'E')
		player->dir = 0;
	if (parse->player == 'W')
		player->dir = PI;
	if (parse->player == 'S')
		player->dir = PI / 2;
}

void	ft_init_player(t_player *player, t_parse *parse, char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == parse->player)
				break ;
			x++;
		}
		if (map[y][x] == parse->player)
			break ;
		y++;
	}
	player->x = x * SCALE + SCALE / 2;
	player->y = y * SCALE + SCALE / 2;
	ft_init_direction(player, parse);
}
