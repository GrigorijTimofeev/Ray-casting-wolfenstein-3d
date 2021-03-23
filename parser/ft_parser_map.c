/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:11:04 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/14 14:11:05 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parse	*g_parse;
int		g_line;
int		g_i;
int		g_max;

void	ft_map_char_cycle(char **map, int line, int i, int *flag)
{
	while (map[line][++i])
	{
		if (map[line][i] == 'N' || map[line][i] == 'S' ||
			map[line][i] == 'E' || map[line][i] == 'W')
			if (g_parse->player != 0)
				ft_map_error();
			else
			{
				g_parse->player = map[line][i];
				g_line = line;
				g_i = i;
			}
		else if (map[line][i] == '0' ||
			map[line][i] == '1' || map[line][i] == '2')
			*flag = 1;
		else if (map[line][i] != ' ')
			ft_map_error();
	}
}

void	ft_map_char_check(char **map, int line)
{
	int		i;
	int		flag;

	while (map[line])
	{
		i = -1;
		flag = 0;
		ft_map_char_cycle(map, line, i, &flag);
		if (flag == 0)
		{
			line = ft_skip_empty_lines(map, line);
			if (map[line] != NULL)
				ft_map_error();
			break ;
		}
		line++;
	}
	if (g_parse->player == 0)
		ft_map_error();
}

char	**ft_allocate_array_2(int line, int max)
{
	char	**ret;
	int		line_tmp;
	int		i;

	ret = malloc(sizeof(char *) * (line + 1));
	if (!ret)
		ft_malloc_error();
	line_tmp = 0;
	while (line_tmp < line)
	{
		ret[line_tmp] = malloc(sizeof(char) * (max + 1));
		if (!ret[line_tmp])
			ft_malloc_error();
		i = -1;
		while (++i < max)
			ret[line_tmp][i] = '.';
		ret[line_tmp][i] = '\0';
		line_tmp++;
	}
	ret[line_tmp] = NULL;
	return (ret);
}

char	**ft_allocate_array(char **map, int line)
{
	int		line_tmp;
	int		max;
	int		i;

	line_tmp = line;
	max = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
			i++;
		if (i > max)
			max = i;
		line++;
	}
	g_max = max;
	line -= line_tmp;
	return (ft_allocate_array_2(line, max));
}

void	ft_parser_map(char **map, t_parse *parse)
{
	char	**floodfill;
	char	**map_tmp;

	g_parse = parse;
	ft_map_char_check(map, parse->map_index);
	g_line -= parse->map_index;
	floodfill = ft_allocate_array(map, parse->map_index);
	map_tmp = ft_allocate_map(map, parse->map_index, g_max);
	ft_free_map(map);
	ft_map_floodfill(map_tmp, &floodfill, g_line, g_i);
	ft_map_outline_check(floodfill);
	ft_map_content_check(map_tmp, floodfill);
	ft_map_creator(map_tmp, parse);
}
