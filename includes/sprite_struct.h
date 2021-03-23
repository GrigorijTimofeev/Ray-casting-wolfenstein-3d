/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:13:53 by yzombie           #+#    #+#             */
/*   Updated: 2021/03/10 12:13:54 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_STRUCT_H
# define SPRITE_STRUCT_H

typedef struct		s_sprite
{
	int				x;
	int				y;
	int				index;
	int				count;
	float			ang;
	struct s_sprite	*next;
}					t_sprite;

#endif
