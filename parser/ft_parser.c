/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:31:19 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/09 13:31:20 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		g_count;

int		ft_cycle_part_1(char **map, int *line, int i, t_parse *parse)
{
	if (ft_strncmp(&(map[(*line)][i]), "R", 1) == 0)
	{
		ft_r_parser(map, (*line)++, parse);
		g_count++;
		return (1);
	}
	if (ft_strncmp(&(map[(*line)][i]), "F", 1) == 0)
	{
		ft_f_parser(map, (*line)++, parse);
		g_count++;
		return (1);
	}
	if (ft_strncmp(&(map[(*line)][i]), "C", 1) == 0)
	{
		ft_c_parser(map, (*line)++, parse);
		g_count++;
		return (1);
	}
	if (ft_strncmp(&(map[(*line)][i]), "NO", 2) == 0)
	{
		ft_no_parser(map, (*line)++, parse);
		g_count++;
		return (1);
	}
	return (0);
}

int		ft_cycle_part_2(char **map, int *line, int i, t_parse *parse)
{
	if (ft_strncmp(&(map[(*line)][i]), "SO", 2) == 0)
	{
		ft_so_parser(map, (*line)++, parse);
		g_count++;
		return (1);
	}
	if (ft_strncmp(&(map[(*line)][i]), "WE", 2) == 0)
	{
		ft_we_parser(map, (*line)++, parse);
		g_count++;
		return (1);
	}
	if (ft_strncmp(&(map[(*line)][i]), "EA", 2) == 0)
	{
		ft_ea_parser(map, (*line)++, parse);
		g_count++;
		return (1);
	}
	if (ft_strncmp(&(map[(*line)][i]), "S", 1) == 0)
	{
		ft_s_parser(map, (*line)++, parse);
		g_count++;
		return (1);
	}
	return (0);
}

void	ft_parser(char **map, t_parse *parse)
{
	int		line;
	int		i;

	line = 0;
	g_count = 0;
	while (g_count != 8 && map[line] != NULL)
	{
		line = ft_skip_empty_lines(map, line);
		if (map[line] == NULL)
			ft_map_error();
		i = ft_skip_spaces(map, line, 0);
		if (ft_cycle_part_1(map, &line, i, parse))
			continue;
		if (ft_cycle_part_2(map, &line, i, parse))
			continue;
		ft_map_error();
	}
	line = ft_skip_empty_lines(map, line);
	parse->map_index = line;
	ft_parser_map(map, parse);
}
