/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:04:41 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/04 18:04:43 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        free_linesplit(char **line_split)
{
    int     i;

    if (line_split == NULL)
        return ;
    i = 0;
    while (line_split[i] != NULL)
    {
        free(line_split[i]);
        i++;
    }
    free(line_split);
}

void        free_value(int **value)
{
    int     i;

    if (value == NULL)
        return ;
    i = 0;
    while (value[i] != NULL)
    {
        free(value[i]);
        i++;
    }
    free(value);
}

void        free_map(t_map *map)
{
    t_map       *prev_map;
    t_map       *head;

    if (map == NULL)
        return ;
    head = map;
    map = map->next;
    while (head != NULL)
    {
        if (head->next == NULL)
        {
            free_value(head->value);
            free(head);
            return ;
        }
        prev_map = head;
        map = head;
        while (map->next != NULL)
            map = map->next;
        while (prev_map->next != map)
            prev_map = prev_map->next;
        free_value(map->value);
        free(map);
        prev_map->next = NULL;
    }
}