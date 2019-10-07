/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:05:33 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/05 12:55:31 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int         check_size_map(t_map *map)
{
    while (map->next != NULL)
    {
        if (map->size != map->next->size)
            return (0);
        map = map->next;
    }
    return (1);
}

t_map       *check_val(int fd)
{
    t_map   *map;
    char    *line;
    char    **line_split;
    int     **value;

    map = NULL;
    while (get_next_line(fd, &line) > 0)
    {
        if (check_line(line_split = ft_strsplit(line, ' ')) == 0)
        {
            free_linesplit(line_split);
            free_map(map);
            free(line);
            return (NULL);
        }
        value = convert_to_values(line_split);
        map = add_to_map(map, value, size_line(line_split));
        free_linesplit(line_split);
        free(line);
    }
    if (check_size_map(map) == 0)
    {
        free_map(map);
        return (NULL);
    }
    return (map);
}
