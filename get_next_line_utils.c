/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:03:38 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/14 15:30:21 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(char *ptr, size_t new)
{
	char	*res;
	size_t	i;

	res = malloc(new);
	if (!res)
		return (NULL);
	i = 0;
	while (ptr[i] && i < new)
	{
		res[i] = ptr[i];
		i++;
	}
	while (i < new)
	{
		res[i] = '\0';
		i++;
	}
	free(ptr);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			ssrc;
	unsigned int	i;

	ssrc = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (ssrc);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ssrc);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
