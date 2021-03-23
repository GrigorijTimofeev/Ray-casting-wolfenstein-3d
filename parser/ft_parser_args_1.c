/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_args_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:10:09 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/12 14:10:11 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		ft_f_and_c_parser_part(char **map, int line, int i)
{
	i = ft_skip_number(map, line, i);
	i = ft_skip_spaces(map, line, i);
	if (map[line][i] == ',')
		i++;
	i = ft_skip_spaces(map, line, i);
	ft_check_number(map[line][i]);
	return (i);
}

void	ft_r_parser(char **map, int line, t_parse *parse)
{
	int		i;

	if (parse->r[0] != -1 || parse->r[1] != -1)
		ft_map_error();
	i = ft_skip_spaces(map, line, 0);
	i++;
	i = ft_skip_spaces(map, line, i);
	ft_check_number(map[line][i]);
	parse->r[0] = ft_atoi(&(map[line][i]));
	i = ft_skip_number(map, line, i);
	i = ft_skip_spaces(map, line, i);
	ft_check_number(map[line][i]);
	parse->r[1] = ft_atoi(&(map[line][i]));
	i = ft_skip_number(map, line, i);
	i = ft_skip_spaces(map, line, i);
	if (map[line][i] != '\0')
		ft_map_error();
}

void	ft_f_parser(char **map, int line, t_parse *parse)
{
	int		i;
	int		r;
	int		g;
	int		b;

	if (parse->f != -1)
		ft_map_error();
	i = ft_skip_spaces(map, line, 0);
	i++;
	i = ft_skip_spaces(map, line, i);
	ft_check_number(map[line][i]);
	r = ft_atoi(&(map[line][i]));
	i = ft_f_and_c_parser_part(map, line, i);
	g = ft_atoi(&(map[line][i]));
	i = ft_f_and_c_parser_part(map, line, i);
	b = ft_atoi(&(map[line][i]));
	i = ft_skip_number(map, line, i);
	i = ft_skip_spaces(map, line, i);
	if (map[line][i] != '\0')
		ft_map_error();
	if (r > 255 || g > 255 || b > 255)
		ft_map_error();
	parse->f = r * pow(16, 4) + g * pow(16, 2) + b;
}

void	ft_c_parser(char **map, int line, t_parse *parse)
{
	int		i;
	int		r;
	int		g;
	int		b;

	if (parse->c != -1)
		ft_map_error();
	i = ft_skip_spaces(map, line, 0);
	i++;
	i = ft_skip_spaces(map, line, i);
	ft_check_number(map[line][i]);
	r = ft_atoi(&(map[line][i]));
	i = ft_f_and_c_parser_part(map, line, i);
	g = ft_atoi(&(map[line][i]));
	i = ft_f_and_c_parser_part(map, line, i);
	b = ft_atoi(&(map[line][i]));
	i = ft_skip_number(map, line, i);
	i = ft_skip_spaces(map, line, i);
	if (map[line][i] != '\0')
		ft_map_error();
	if (r > 255 || g > 255 || b > 255)
		ft_map_error();
	parse->c = r * pow(16, 4) + g * pow(16, 2) + b;
}
