/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_dop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:39:12 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/12 17:39:13 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_map_error(void)
{
	ft_putstr_fd("Error\nInvalid file content\n", 2);
	exit(1);
}

int		ft_skip_spaces(char **map, int line, int i)
{
	while (map[line][i] == ' ')
		i++;
	return (i);
}

int		ft_skip_empty_lines(char **map, int line)
{
	int		i;

	while (map[line] != NULL)
	{
		i = 0;
		while (map[line][i] == ' ' || map[line][i] == '	')
			i++;
		if (map[line][i] != '\0')
			return (line);
		line++;
	}
	return (line);
}

void	ft_check_number(char c)
{
	if (c < '0' || c > '9')
		ft_map_error();
}

int		ft_skip_number(char **map, int line, int i)
{
	while (map[line][i] >= '0' && map[line][i] <= '9')
		i++;
	return (i);
}
