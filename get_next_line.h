/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:39:58 by mmaterna          #+#    #+#             */
/*   Updated: 2025/02/06 09:40:06 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*save_remaining(char *str);
char	*get_line(char *str);
char	*str_join(char *s1, char *s2);

#endif