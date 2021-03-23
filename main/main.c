/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:10:35 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/08 14:10:36 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_struct(t_parse **parse)
{
	*parse = malloc(sizeof(t_parse));
	if (!(*parse))
		ft_malloc_error();
	(*parse)->player = '\0';
	(*parse)->map_index = 0;
	(*parse)->save = 0;
	(*parse)->r[0] = -1;
	(*parse)->r[1] = -1;
	(*parse)->no = NULL;
	(*parse)->so = NULL;
	(*parse)->we = NULL;
	(*parse)->ea = NULL;
	(*parse)->s = NULL;
	(*parse)->f = -1;
	(*parse)->c = -1;
}

void	ft_check_arg(int argc, char **argv, t_parse *parse)
{
	int		length;

	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error\nIncorrect number of arguments\n", 2);
		exit(1);
	}
	length = ft_strlen(argv[1]);
	if (argv[1][length - 1] != 'b' || argv[1][length - 2] != 'u' ||
		argv[1][length - 3] != 'c' || argv[1][length - 4] != '.')
	{
		ft_putstr_fd("Error\nIncorrect file format\n", 2);
		exit(1);
	}
	if (argc != 3)
		return ;
	if (ft_strncmp(argv[2], "--save", 10) != 0)
	{
		ft_putstr_fd("Error\nIncorrect second argument\n", 2);
		exit(1);
	}
	parse->save = 1;
}

void	ft_none(void *content)
{
	(void)content;
}

void	ft_create_map(t_list **head, t_parse *parse)
{
	int		length;
	char	**map;
	t_list	*tmp;
	int		i;

	length = ft_lstsize(*head);
	map = malloc(sizeof(char *) * (length + 1));
	if (!map)
		ft_malloc_error();
	tmp = *head;
	i = 0;
	while (tmp)
	{
		map[i++] = tmp->content;
		tmp = tmp->next;
	}
	map[i] = NULL;
	tmp = (*head)->next;
	ft_lstclear(head, *ft_none);
	ft_parser(map, parse);
}

int		main(int argc, char **argv)
{
	char	*line;
	t_list	*head;
	t_parse	*parse;
	int		fd;
	int		ret;

	parse = NULL;
	ft_init_struct(&parse);
	ft_check_arg(argc, argv, parse);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nUnable to open file\n", 2);
		exit(1);
	}
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			ft_malloc_error();
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	ft_create_map(&head, parse);
	return (0);
}
