/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 18:00:20 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/07 18:02:33 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    gorizontal_line(t_map *map, int i, t_mw *mw)
{
    int     lenx;
    int     leny;
    int     len;

    lenx = abs(map->coor[i + 1][0] - map->coor[i][0]);
    leny = abs(map->coor[i + 1][1] - map->coor[i][1]);
    len = fmax(lenx, leny);
    if (leny < lenx)
        fill_line(map, i, len, mw);
    else
        fill_line1(map, i, len, mw);
}

void    vertical_line(t_map *map, int i, t_mw *mw)
{
    int     lenx;
    int     leny;
    int     len;

    lenx = abs(map->next->coor[i][0] - map->coor[i][0]);
    leny = abs(map->next->coor[i][1] - map->coor[i][1]);
    len = fmax(lenx, leny);
    if (leny < lenx)
        fill_line2(map, i, len, mw);
    else
        fill_line3(map, i, len, mw);
}

void        fill_iso(t_mw *mw, t_map *map)
{
    int     i;
    int     j;

    j = 0;
    while (map != NULL)
    {
        i = 0;
        while (i < map->size)
        {
            if (i != map->size -1)
                gorizontal_line(map, i, mw);
            if (map->next != NULL)
                vertical_line(map, i, mw);
            i++;
        }
        j++;
        map = map->next;
    }
}
