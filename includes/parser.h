/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:33:26 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/09 13:33:27 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "parser_struct.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_parser_map(char **map, t_parse *parse);
void	ft_map_outline_check(char **floodfill);
char	**ft_allocate_map(char **map, int line, int max);
void	ft_free_map(char **map);
void	ft_map_content_check(char **map, char **floodfill);
void	ft_map_floodfill(char **map, char ***floodfill, int line, int i);
int		ft_map_creator(char **map, t_parse *parse);
void	ft_map_error(void);
void	ft_check_number(char c);
int		ft_skip_spaces(char **map, int line, int i);
int		ft_skip_empty_lines(char **map, int line);
int		ft_skip_number(char **map, int line, int i);
void	ft_r_parser(char **map, int line, t_parse *parse);
void	ft_f_parser(char **map, int line, t_parse *parse);
void	ft_c_parser(char **map, int line, t_parse *parse);
void	ft_no_parser(char **map, int line, t_parse *parse);
void	ft_so_parser(char **map, int line, t_parse *parse);
void	ft_we_parser(char **map, int line, t_parse *parse);
void	ft_ea_parser(char **map, int line, t_parse *parse);
void	ft_s_parser(char **map, int line, t_parse *parse);

#endif
