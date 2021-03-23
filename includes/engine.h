/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:33:26 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/09 13:33:27 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "mlx_struct.h"
# include "parser_struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

void		ft_map_error(void);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_init_player(t_player *player, t_parse *parse, char **map);
int			window_exit(t_system *sys);
void		ft_init_map(t_system *sys, char **map);
int			ft_get_img_color(t_data *data, int x, int y);
void		ft_textures_error();
void		ft_put_ray_sprite(t_system *sys);
void		ft_add_mid_sprite(t_sprite **head, t_player *player, int x, int y);
void		ft_free_sprites(t_sprite **head);
void		ft_put_img_to_bmp(t_system *sys);
int			key_hook(int keycode, t_system *sys);
void		ft_init_textures(t_system *sys);
void		ft_first_frame(t_system *sys);
void		ft_put_ray(t_system *sys);
void		ft_deaw_ceiling_and_floor(t_system *sys);
t_player	ft_trace_x(t_system *sys, t_player *ray, float ang);
t_player	ft_trace_y(t_system *sys, t_player *ray, float ang);
void		ft_draw_wall(t_system *sys, t_player ray, int line_index);
void		ft_list_sort(t_sprite **sprites);
void		ft_draw_sprites(t_system *sys, t_sprite *sprite);
int			ft_list_size(t_sprite *sprites);
void		ft_check_resolution(t_system *sys, t_parse *parse);

#endif
