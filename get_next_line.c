/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:05:11 by mmaterna          #+#    #+#             */
/*   Updated: 2025/01/23 23:51:02 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
    static char	*saved = NULL;
    char		*buffer;
    char		*line;
    int			bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while ((saved == NULL || !ft_strchr(saved, '\n')) && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        saved = str_join(saved, buffer);
        if (!saved)
        {
            free(buffer);
            return (NULL);
        }
    }
    free(buffer);
    line = get_line(saved);
    saved = save_remaining(saved);
    return (line);
}

// int	main()
// {
//     char	*line;
//     int		i;
//     int		fd1;
//     int		fd2;
//     int		fd3;

//     fd1 = open("tests/test.txt", O_RDONLY);
//     fd2 = open("tests/test2.txt", O_RDONLY);
//     fd3 = open("tests/test3.txt", O_RDONLY);
//     i = 1;
//     while (i < 7)
//     {
//         line = get_next_line(fd1);
//         printf("line [%02d]: %s\n", i, line);
//         free(line);
//         line = get_next_line(fd2);
//         printf("line [%02d]: %s\n", i, line);
//         free(line);
//         line = get_next_line(fd3);
//         printf("line [%02d]: %s\n", i, line);
//         free(line);
//         i++;
//     }
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     return (0);
// }