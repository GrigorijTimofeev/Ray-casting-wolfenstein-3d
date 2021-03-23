/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map_dop_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:38:31 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/16 15:38:32 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_map_content_check(char **map, char **floodfill)
{
	int		line;
	int		i;

	line = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (floodfill[line][i] == '+' && map[line][i] != '0' &&
			map[line][i] != '2' && map[line][i] != 'E' &&
			map[line][i] != 'W' && map[line][i] != 'S' &&
			map[line][i] != 'N' && map[line][i] != '2')
				ft_map_error();
			i++;
		}
		line++;
	}
}
