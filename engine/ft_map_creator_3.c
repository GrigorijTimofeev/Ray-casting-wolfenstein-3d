/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:58:47 by yzombie           #+#    #+#             */
/*   Updated: 2021/03/20 18:58:48 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		ft_more_sprite_rays(t_system *sys, t_player *ray)
{
	float index;
	float ang;

	index = sys->player.index + 0.2;
	ang = atan((index - (sys->width / 2)) /
			(float)((sys->width / 2) / 0.57735)) + ray->dir;
	ft_trace_y(sys, ray, ang);
	ft_trace_x(sys, ray, ang);
	index += 0.2;
	ang = atan((index - (sys->width / 2)) /
			(float)((sys->width / 2) / 0.57735)) + ray->dir;
	ft_trace_y(sys, ray, ang);
	ft_trace_x(sys, ray, ang);
	index += 0.2;
	ang = atan((index - (sys->width / 2)) /
			(float)((sys->width / 2) / 0.57735)) + ray->dir;
	ft_trace_y(sys, ray, ang);
	ft_trace_x(sys, ray, ang);
	index += 0.2;
	ang = atan((index - (sys->width / 2)) /
			(float)((sys->width / 2) / 0.57735)) + ray->dir;
	ft_trace_y(sys, ray, ang);
	ft_trace_x(sys, ray, ang);
}

void		ft_ray_cycle_body(t_player *ray, t_player *p1,
				t_player *p2, t_player **tmp)
{
	if ((fabs(ray->x - p1->x) + fabs(ray->y - p1->y)) >
		(fabs(ray->x - p2->x) + fabs(ray->y - p2->y)))
		(*tmp) = p2;
	else
		(*tmp) = p1;
	(*tmp)->count = sqrt(pow(((ray->x) - (*tmp)->x), 2) +
				pow(((ray->y) - (*tmp)->y), 2));
	(*tmp)->ang = ray->ang;
}

void		ft_outgoing_rays(t_system *sys, t_player *ray)
{
	sys->player.index = sys->width;
	while (sys->player.index < sys->width + 700)
	{
		ray->ang = atan((sys->player.index - (sys->width / 2)) /
					(float)((sys->width / 2) / 0.57735)) + ray->dir;
		sys->player.ang = ray->ang;
		ft_trace_y(sys, ray, ray->ang);
		ft_trace_x(sys, ray, ray->ang);
		sys->player.index++;
	}
	sys->player.index = -700;
	while (sys->player.index < 0)
	{
		ray->ang = atan((sys->player.index - (sys->width / 2)) /
					(float)((sys->width / 2) / 0.57735)) + ray->dir;
		sys->player.ang = ray->ang;
		ft_trace_y(sys, ray, ray->ang);
		ft_trace_x(sys, ray, ray->ang);
		sys->player.index++;
	}
}

void		ft_put_ray(t_system *sys)
{
	t_player	ray;
	t_player	p1;
	t_player	p2;
	t_player	*tmp;

	tmp = NULL;
	ray = sys->player;
	sys->player.index = -1;
	if ((ray.x) / SCALE < sys->map_width - 1 && (ray.y) /
		SCALE < sys->map_heigth - 1 && ray.x >= 0 && ray.y >= 0)
		while (++sys->player.index != sys->width)
		{
			ray.ang = atan((sys->player.index - (sys->width / 2)) /
					(float)((sys->width / 2) / 0.57735)) + ray.dir;
			sys->player.ang = ray.ang;
			p1 = ft_trace_y(sys, &ray, ray.ang);
			p2 = ft_trace_x(sys, &ray, ray.ang);
			ft_more_sprite_rays(sys, &ray);
			ft_ray_cycle_body(&ray, &p1, &p2, &tmp);
			sys->walls[sys->player.index] = tmp->count;
			if ((tmp->x) / SCALE < sys->map_width && (tmp->y) /
				SCALE < sys->map_heigth && tmp->x >= 0 && tmp->y >= 0)
				ft_draw_wall(sys, *tmp, sys->player.index);
		}
	ft_outgoing_rays(sys, &ray);
}
