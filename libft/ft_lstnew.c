/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:05:39 by yzombie           #+#    #+#             */
/*   Updated: 2020/11/08 14:05:39 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_malloc_error(void)
{
	ft_putstr_fd("Error\nMalloc error\n", 2);
	exit(1);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		ft_malloc_error();
	new->content = content;
	new->next = NULL;
	return (new);
}
