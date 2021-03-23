/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_args_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:10:14 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/12 14:10:15 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_no_parser(char **map, int line, t_parse *parse)
{
	int		i;
	int		length;

	if (parse->no != NULL)
		ft_map_error();
	i = ft_skip_spaces(map, line, 0);
	i += 2;
	i = ft_skip_spaces(map, line, i);
	if (ft_strncmp(&(map[line][i]), "./", 2) == 0)
		i += 2;
	else
		ft_map_error();
	length = 0;
	while (map[line][i + length] != ' ' && map[line][i + length])
		length++;
	parse->no = ft_substr(map[line], i, length);
	while (map[line][i] != ' ' && map[line][i])
		i++;
	i = ft_skip_spaces(map, line, i);
	if (map[line][i] != '\0')
		ft_map_error();
}

void	ft_so_parser(char **map, int line, t_parse *parse)
{
	int		i;
	int		length;

	if (parse->so != NULL)
		ft_map_error();
	i = ft_skip_spaces(map, line, 0);
	i += 2;
	i = ft_skip_spaces(map, line, i);
	if (ft_strncmp(&(map[line][i]), "./", 2) == 0)
		i += 2;
	else
		ft_map_error();
	length = 0;
	while (map[line][i + length] != ' ' && map[line][i + length])
		length++;
	parse->so = ft_substr(map[line], i, length);
	while (map[line][i] != ' ' && map[line][i])
		i++;
	i = ft_skip_spaces(map, line, i);
	if (map[line][i] != '\0')
		ft_map_error();
}

void	ft_we_parser(char **map, int line, t_parse *parse)
{
	int		i;
	int		length;

	if (parse->we != NULL)
		ft_map_error();
	i = ft_skip_spaces(map, line, 0);
	i += 2;
	i = ft_skip_spaces(map, line, i);
	if (ft_strncmp(&(map[line][i]), "./", 2) == 0)
		i += 2;
	else
		ft_map_error();
	length = 0;
	while (map[line][i + length] != ' ' && map[line][i + length])
		length++;
	parse->we = ft_substr(map[line], i, length);
	while (map[line][i] != ' ' && map[line][i])
		i++;
	i = ft_skip_spaces(map, line, i);
	if (map[line][i] != '\0')
		ft_map_error();
}

void	ft_ea_parser(char **map, int line, t_parse *parse)
{
	int		i;
	int		length;

	if (parse->ea != NULL)
		ft_map_error();
	i = ft_skip_spaces(map, line, 0);
	i += 2;
	i = ft_skip_spaces(map, line, i);
	if (ft_strncmp(&(map[line][i]), "./", 2) == 0)
		i += 2;
	else
		ft_map_error();
	length = 0;
	while (map[line][i + length] != ' ' && map[line][i + length])
		length++;
	parse->ea = ft_substr(map[line], i, length);
	while (map[line][i] != ' ' && map[line][i])
		i++;
	i = ft_skip_spaces(map, line, i);
	if (map[line][i] != '\0')
		ft_map_error();
}

void	ft_s_parser(char **map, int line, t_parse *parse)
{
	int		i;
	int		length;

	if (parse->s != NULL)
		ft_map_error();
	i = ft_skip_spaces(map, line, 0);
	i++;
	i = ft_skip_spaces(map, line, i);
	if (ft_strncmp(&(map[line][i]), "./", 2) == 0)
		i += 2;
	else
		ft_map_error();
	length = 0;
	while (map[line][i + length] != ' ' && map[line][i + length])
		length++;
	parse->s = ft_substr(map[line], i, length);
	while (map[line][i] != ' ' && map[line][i])
		i++;
	i = ft_skip_spaces(map, line, i);
	if (map[line][i] != '\0')
		ft_map_error();
}
