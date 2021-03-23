/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:58:54 by yzombie           #+#    #+#             */
/*   Updated: 2021/03/20 18:58:55 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		ft_trace_sprite(t_system *sys, t_player p,
				float step_x, float step_y)
{
	int		x;
	int		y;
	int		py;
	int		px;

	while (p.x / SCALE < sys->map_width && p.y /
		SCALE < sys->map_heigth && p.x >= 0 && p.y >= 0)
	{
		if (sys->map[(int)(p.y / SCALE)][(int)(p.x / SCALE)] == '2')
		{
			x = (int)(p.x / SCALE) * SCALE + SCALE / 2;
			y = (int)(p.y / SCALE) * SCALE + SCALE / 2;
			py = p.y + step_y / 2;
			px = p.x + step_x / 2;
			if (py > y - 3 && py < y + 3 && px > x - 3 && px < x + 3)
				ft_add_mid_sprite(&(sys->sprites), &(sys->player), x, y);
		}
		p.x += step_x;
		p.y += step_y;
	}
}

void		ft_trace(t_system *sys, t_player *p, float step_x, float step_y)
{
	while (sys->map[(int)(p->y / SCALE)][(int)(p->x / SCALE)] != '1')
	{
		p->x += step_x;
		p->y += step_y;
		if (!(p->x / SCALE < sys->map_width && p->y /
			SCALE < sys->map_heigth && p->x >= 0 && p->y >= 0))
			break ;
	}
}

int			ft_trace_check(t_system *sys, t_player *ray, t_player p)
{
	if (p.x / SCALE < sys->map_width && p.y /
		SCALE < sys->map_heigth && p.x >= 0 && p.y >= 0)
		if (ray->x / SCALE < sys->map_width && ray->y /
		SCALE < sys->map_heigth && ray->x >= 0 && ray->y >= 0)
			if (sys->map[(int)(ray->y / SCALE)][(int)(ray->x / SCALE)] != '1')
				return (1);
	return (0);
}

t_player	ft_trace_y(t_system *sys, t_player *ray, float ang)
{
	t_player	p;
	int			step_y;
	float		step_x;

	if (sin(ang) > 0)
	{
		p.y = (int)(ray->y / SCALE) * SCALE + SCALE;
		step_y = SCALE;
	}
	else
	{
		p.y = (int)(ray->y / SCALE) * SCALE - 0.01;
		step_y = -SCALE;
	}
	p.x = ray->x - (ray->y - p.y) / tan(ang);
	step_x = step_y / tan(ang);
	if (ft_trace_check(sys, ray, p) == 1)
	{
		ft_trace_sprite(sys, p, step_x, step_y);
		ft_trace(sys, &p, step_x, step_y);
	}
	p.hor_ver = 'v';
	return (p);
}

t_player	ft_trace_x(t_system *sys, t_player *ray, float ang)
{
	t_player	p;
	int			step_x;
	float		step_y;

	if (cos(ang) > 0)
	{
		p.x = (int)(ray->x / SCALE) * SCALE + SCALE;
		step_x = SCALE;
	}
	else
	{
		p.x = (int)(ray->x / SCALE) * SCALE - 0.01;
		step_x = -SCALE;
	}
	p.y = ray->y - (ray->x - p.x) * tan(ang);
	step_y = step_x * tan(ang);
	if (ft_trace_check(sys, ray, p) == 1)
	{
		ft_trace_sprite(sys, p, step_x, step_y);
		ft_trace(sys, &p, step_x, step_y);
	}
	p.hor_ver = 'h';
	return (p);
}
