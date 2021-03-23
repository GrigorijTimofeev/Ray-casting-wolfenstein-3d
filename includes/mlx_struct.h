/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:09:12 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/17 14:09:13 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STRUCT_H
# define MLX_STRUCT_H

# define SCALE 300
# define PI 3.14159

# include "sprite_struct.h"
# include "parser_struct.h"

typedef struct	s_player
{
	float		x;
	float		y;
	float		dir;
	float		ang;
	char		hor_ver;
	int			count;
	int			index;
}				t_player;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_draw_wall {
	float		wall_height;
	int			ceiling;
	int			floor;
	int			xmp_index_y;
	int			xmp_index_x;
}				t_draw_wall;

typedef struct	s_list_sort {
	int			size;
	int			i;
	int			j;
	int			max;
	t_sprite	**tmp1;
	t_sprite	*tmp2;
	t_sprite	*pred;
}				t_list_sort;

typedef struct	s_draw_sprites {
	float		wall_height;
	float		offset;
	int			ceiling;
	int			floor;
	int			xmp_index_y;
	int			xmp_index_x;
	int			win_x;
	int			win_y;
	int			start;
	int			color;
}				t_draw_sprites;

typedef struct	s_system {
	t_data		img;
	t_data		img_no;
	t_data		img_so;
	t_data		img_we;
	t_data		img_ea;
	t_data		img_sprites;
	t_player	player;
	t_parse		*parse;
	t_sprite	*sprites;
	int			*walls;
	int			index;
	void		*mlx;
	void		*win;
	int			width;
	int			heigth;
	char		**map;
	int			map_width;
	int			map_heigth;
}				t_system;

#endif
