/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:21:27 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/07 20:51:23 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    iso(int *x, int *y, int z, t_map *map)
{
    int  previous_x;
    int  previous_y;

    map = NULL;
    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z * 15 + (previous_x + previous_y) * sin(0.523599);
}

void        create_coor(t_map *map)
{
    int     i;

    while (map != NULL)
    {
        map->coor = (int**)malloc(sizeof(int*) * (map->size + 1));
        map->coor[map->size] = NULL;
        i = 0;
        while (map->value[i] != NULL)
        {
            map->coor[i] = (int*)malloc(sizeof(int) * 2);
            i++;
        }
        map = map->next;
    }
}

void        set_coor_iso(t_map *map, int step)
{
    int     i;
    int     j;

    create_coor(map);
    j = 0;
    while (map != NULL)
    {
        i = 0;
        while (i < map->size)
        {
            map->coor[i][0] = step * (i + 1) + 750;
            map->coor[i][1] = step * (j + 1) + 250;
            iso(&(map->coor[i][0]), &(map->coor[i][1]), map->value[i][0], map);
            i++;
        }
        map = map->next;
        j++;
    }
}
