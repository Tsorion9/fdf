/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:05:27 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/04 18:05:28 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map       *create_map(int **value, int size)
{
    t_map       *map;

    map = (t_map*)malloc(sizeof(t_map));
    map->value = value;
    map->size = size;
    map->next = NULL;
    return (map);
}

t_map       *add_to_map(t_map *map, int **value, int size)
{
    t_map       *head;

    head = map;
    if (map == NULL)
    {
        map = create_map(value, size);
        return (map);
    }
    else
    {
        while (map->next != NULL)
            map = map->next;
        map->next = create_map(value, size);
    }
    return (head);
}
