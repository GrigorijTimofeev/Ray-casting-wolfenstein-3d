/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:48:14 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/13 13:48:15 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_cycle_body(char **line, char **remain,
			int *was_read, char **buf)
{
	char	*temp;
	char	*ptr;

	(*buf)[*was_read] = '\0';
	if (*line == NULL)
		*line = ft_strdup(*buf);
	else
		*line = ft_strjoin_gnl(*line, *buf);
	if (!(*line))
		return (-1);
	if ((ptr = ft_strchr(*line, '\n')))
	{
		*remain = ft_strdup(++ptr);
		ptr--;
		*ptr = '\0';
		temp = *line;
		temp = ft_strdup(*line);
		if (!line || !(*remain) || !temp)
			*was_read = -1;
		free(*line);
		*line = temp;
		return (-1);
	}
	return (1);
}

int		ft_check_remain(char **remain, char **line, int i, char *temp)
{
	if (!(*remain))
		return (1);
	while ((*remain)[i] != '\0' && (*remain)[i] != '\n')
		i++;
	if ((*remain)[i] == '\n')
	{
		(*remain)[i] = '\0';
		*line = ft_strdup(*remain);
		if (!(*line))
			return (-1);
		temp = *remain;
		*remain = ft_strdup(&((*remain)[i + 1]));
		free(temp);
		if (!remain)
			return (-1);
		return (-2);
	}
	*line = ft_strdup(*remain);
	if (!(*line))
		return (-1);
	free(*remain);
	*remain = NULL;
	return (1);
}

int		ft_check(char **line, char **remain, int flag, char *buf)
{
	if (buf != NULL)
		free(buf);
	if (flag == 0)
	{
		*remain = NULL;
		if (!(*line))
			*line = ft_strdup("");
		return (0);
	}
	if (flag == -1)
	{
		if (*line != NULL)
			free(*line);
		if (*remain != NULL)
			free(*remain);
		*remain = NULL;
		return (-1);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			flag;
	static char	*remain;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
	{
		if (remain != NULL)
			free(remain);
		remain = NULL;
		return (-1);
	}
	*line = NULL;
	flag = ft_check_remain(&remain, line, 0, NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		flag = -1;
	if (flag > 0)
		while ((flag = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			if (ft_cycle_body(line, &remain, &flag, &buf) == -1)
				break ;
		}
	return (ft_check(line, &remain, flag, buf));
}
