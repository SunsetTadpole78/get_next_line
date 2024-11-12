/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:35:15 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/12 10:07:58 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_realloc(char *ptr, size_t size);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*recover_old(char *buffer, char *old);
char	*seperate(char *buffer, char **old);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*create_line(int byte_read, char **old, char **buffer);

#endif
