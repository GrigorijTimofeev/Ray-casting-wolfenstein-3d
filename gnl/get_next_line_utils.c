/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:48:34 by yzombie           #+#    #+#             */
/*   Updated: 2021/01/13 13:48:35 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;
	char	find;

	find = (char)c;
	ret = (char *)s;
	while (*ret)
	{
		if (*ret == find)
			break ;
		ret++;
	}
	if (*ret == find)
		return (ret);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	i = 0;
	while (i < (int)dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	int		n;
	int		ret;

	ret = ft_strlen(d) + ft_strlen(s);
	if (dstsize - 1 == ft_strlen(d))
		return (ret);
	n = dstsize;
	while (n-- && *d)
		d++;
	if (n <= 0)
		return (dstsize + ft_strlen(s));
	while (*s && n-- != 0)
		*d++ = *s++;
	*d = '\0';
	return (ret);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = len1 + ft_strlen(s2);
	ret = malloc(sizeof(char) * (len2 + 1));
	if (ret)
	{
		ft_strlcpy(ret, s1, len1 + 1);
		ft_strlcat(ret, s2, len2 + 1);
	}
	free(s1);
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		len;

	len = ft_strlen(s1);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret)
		ft_strlcpy(ret, s1, len + 1);
	return (ret);
}
