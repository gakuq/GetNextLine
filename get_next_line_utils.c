/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:05:15 by mmaterna          #+#    #+#             */
/*   Updated: 2025/01/24 00:06:23 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
    size_t	i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char	*str_join(char *s1, char *s2)
{
	char *result;
    size_t len1;
	size_t len2;

    if (s1)
        len1 = ft_strlen(s1);
    else
        len1 = 0;

    len2 = ft_strlen(s2);
    result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;

    if (s1)
    {
        for (size_t i = 0; i < len1; i++)
            result[i] = s1[i];
        free(s1);
    }

    for (size_t i = 0; i < len2; i++)
        result[len1 + i] = s2[i];

    result[len1 + len2] = '\0';
    return result;
}

char	*get_line(char *str)
{
    char	*line;
    int		i;

    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    line = malloc(sizeof(char) * (i + (str[i] == '\n') + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return (line);
}

char	*save_remaining(char *str)
{
    char	*remaining;
    int		i;
    int		j;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    remaining = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (!remaining)
        return (NULL);
    i++;
    j = 0;
    while (str[i])
        remaining[j++] = str[i++];
    remaining[j] = '\0';
    free(str);
    return (remaining);
}

char	*ft_strchr(char *s, int c)
{
    while (*s)
    {
        if (*s == (unsigned char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}