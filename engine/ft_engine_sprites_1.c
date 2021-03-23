/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:07:12 by yzombie           #+#    #+#             */
/*   Updated: 2021/03/08 17:07:13 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		ft_free_sprites(t_sprite **head)
{
	t_sprite	*tmp1;
	t_sprite	*tmp2;

	tmp1 = *head;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	(*head) = NULL;
}

void		ft_add_mid_sprite(t_sprite **head, t_player *player, int x, int y)
{
	if ((*head) == NULL)
	{
		(*head) = malloc(sizeof(t_sprite));
		if (!(*head))
			ft_malloc_error();
		(*head)->x = x;
		(*head)->y = y;
		(*head)->index = player->index;
		(*head)->ang = player->ang;
		(*head)->count = sqrt(pow(((player->x) - x), 2) +
							pow(((player->y) - y), 2));
		(*head)->next = NULL;
		return ;
	}
	if ((*head)->x == x && (*head)->y == y)
		return ;
	ft_add_mid_sprite(&((*head)->next), player, x, y);
}

int			ft_list_size(t_sprite *sprites)
{
	int	count;

	count = 0;
	while (sprites != NULL)
	{
		sprites = sprites->next;
		count++;
	}
	return (count);
}

void		ft_put_ray_sprite(t_system *sys)
{
	t_sprite	*tmp;

	ft_list_sort(&(sys->sprites));
	tmp = sys->sprites;
	while (tmp != NULL)
	{
		ft_draw_sprites(sys, tmp);
		tmp = tmp->next;
	}
}
