/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:35:15 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/14 09:28:36 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/* ______________________________ BUFFER_SIZE ______________________________ */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* ____________________________ get_next_line.c ____________________________ */

char	*get_next_line(int fd);
char	*create_line(int byte_read, char **stashed, char **buffer);
char	*recover_stashed(char *buffer, char *stashed);
char	*seperate(char *buffer, char **stashed);
void	*on_error(char **buffer, char **stashed);

/* _________________________ get_next_line_utils.c _________________________ */

void	*ft_realloc(char *ptr, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
