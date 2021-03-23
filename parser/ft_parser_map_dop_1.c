/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map_dop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:05:56 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/16 13:05:58 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_free_map(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_map_floodfill(char **map, char ***floodfill, int line, int i)
{
	if (line < 0 || i < 0 || !map[line] || !map[line][i])
		return ;
	if ((*floodfill)[line][i] == '+')
		return ;
	if (map[line][i] != '1')
	{
		(*floodfill)[line][i] = '+';
		ft_map_floodfill(map, floodfill, line + 1, i);
		ft_map_floodfill(map, floodfill, line - 1, i);
		ft_map_floodfill(map, floodfill, line, i + 1);
		ft_map_floodfill(map, floodfill, line, i - 1);
	}
}

char	*ft_allocate_array_cycle(char **map, int line_tmp, int i, int max)
{
	int		j;
	char	*ret;

	ret = malloc(sizeof(char) * (max + 1));
	if (!ret)
		ft_malloc_error();
	j = ft_strlen(map[line_tmp + i]);
	ft_memcpy(ret, map[line_tmp + i], j);
	while (j < max)
	{
		ret[j] = ' ';
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	**ft_allocate_map(char **map, int line, int max)
{
	char	**ret;
	int		line_tmp;
	int		i;

	line_tmp = line;
	while (map[line])
		line++;
	line -= line_tmp;
	ret = malloc(sizeof(char *) * (line + 1));
	if (!ret)
		ft_malloc_error();
	i = -1;
	while (++i < line)
	{
		ret[i] = ft_allocate_array_cycle(map, line_tmp, i, max);
	}
	ret[i] = NULL;
	return (ret);
}

void	ft_map_outline_check(char **floodfill)
{
	int		i;
	int		line;

	line = 0;
	while (floodfill[line])
	{
		i = 0;
		while (floodfill[line][i])
		{
			if (floodfill[line][i] == '+' && (!floodfill[line + 1] ||
				!floodfill[line][i + 1] || line == 0 || i == 0))
				ft_map_error();
			i++;
		}
		line++;
	}
	return ;
}
