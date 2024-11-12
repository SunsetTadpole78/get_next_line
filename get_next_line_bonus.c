/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:27:29 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/12 11:01:29 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*create_line(int byte_read, char **old, char **buffer)
{
	char	*temp;
	char	*res;

	if (byte_read <= 0 && !(*old) && (*buffer)[0] == '\0')
	{
		free(*buffer);
		return (NULL);
	}
	temp = recover_old(*buffer, *old);
	free(*buffer);
	if (!temp)
		return (NULL);
	res = seperate(temp, &(*old));
	free(temp);
	if (!res[0])
	{
		free(res);
		return (NULL);
	}
	if (!(*old) && byte_read == -1)
		free(*old);
	return (res);
}

void	*on_error(char **buffer, char **old)
{
	free(*buffer);
	*buffer = NULL;
	if (*old)
	{
		free(*old);
		*old = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			byte_read;
	char		*buffer;
	static char	*old[1024];
	int			pos;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	pos = 0;
	while (1)
	{
		byte_read = read(fd, buffer + pos, BUFFER_SIZE);
		if (byte_read == -1)
			return (on_error(&buffer, &(old[fd])));
		buffer[byte_read + pos] = '\0';
		if (byte_read == 0 || ft_strchr(buffer, '\n'))
			break ;
		pos += byte_read;
		buffer = ft_realloc(buffer, pos + BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
	}
	return (create_line(byte_read, &(old[fd]), &buffer));
}

char	*recover_old(char *buffer, char *old)
{
	char	*res;

	if (!old)
		return (ft_strdup(buffer));
	res = malloc(ft_strlen(buffer) + ft_strlen(old) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, old, ft_strlen(old) + 1);
	ft_strlcpy(res + ft_strlen(old), buffer, ft_strlen(buffer) + 1);
	return (res);
}

char	*seperate(char *buffer, char **old)
{
	int		i;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	res = ft_strdup(buffer);
	if (!res)
		return (NULL);
	res[i] = '\0';
	if (*old)
	{
		free(*old);
		*old = NULL;
	}
	if (buffer[i])
		*old = ft_strdup(buffer + i);
	return (res);
}
