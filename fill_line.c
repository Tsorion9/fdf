/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:02:47 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/07 18:02:49 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    fill_line(t_map *map, int i, int len, t_mw *mw)
{
    int     x;
    double  y;
    int     dx;
    int     dy;

    x = map->coor[i][0];
    y = map->coor[i][1];
    dx = (map->coor[i + 1][0] - map->coor[i][0] >= 0 ? 1 : -1);
    dy = (map->coor[i + 1][1] - map->coor[i][1] >= 0 ? 1 : -1);
    len++;
    while (len--)
    {
        mlx_pixel_put(mw->mlx_ptr, mw->win_ptr, x, y, map->value[i][1]);
        x += dx;
        y += dy * (double)(abs(map->coor[i + 1][1] - map->coor[i][1])) /
            (abs(map->coor[i + 1][0] - map->coor[i][0]));
    }
}

void    fill_line1(t_map *map, int i, int len, t_mw *mw)
{
    double  x;
    int     y;
    int     dx;
    int     dy;

    x = map->coor[i][0];
    y = map->coor[i][1];
    dx = (map->coor[i + 1][0] - map->coor[i][0] >= 0 ? 1 : -1);
    dy = (map->coor[i + 1][1] - map->coor[i][1] >= 0 ? 1 : -1);
    len++;
    while (len--)
    {
        mlx_pixel_put(mw->mlx_ptr, mw->win_ptr, x, y, map->value[i][1]);
        x += dx * (double)(abs(map->coor[i + 1][0] - map->coor[i][0])) /
            (abs(map->coor[i + 1][1] - map->coor[i][1]));
        y += dy;
    }
}

void    fill_line2(t_map *map, int i, int len, t_mw *mw)
{
    int     x;
    double  y;
    int     dx;
    int     dy;

    x = map->coor[i][0];
    y = map->coor[i][1];
    dx = (map->next->coor[i][0] - map->coor[i][0] >= 0 ? 1 : -1);
    dy = (map->next->coor[i][1] - map->coor[i][1] >= 0 ? 1 : -1);
    len++;
    while (len--)
    {
        mlx_pixel_put(mw->mlx_ptr, mw->win_ptr, x, y, map->value[i][1]);
        x += dx;
        y += dy * (double)(abs(map->next->coor[i][1] - map->coor[i][1])) /
            (abs(map->next->coor[i][0] - map->coor[i][0]));
    }
}

void    fill_line3(t_map *map, int i, int len, t_mw *mw)
{
    double  x;
    int     y;
    int     dx;
    int     dy;

    x = map->coor[i][0];
    y = map->coor[i][1];
    dx = (map->next->coor[i][0] - map->coor[i][0] >= 0 ? 1 : -1);
    dy = (map->next->coor[i][1] - map->coor[i][1] >= 0 ? 1 : -1);
    len++;
    while (len--)
    {
        mlx_pixel_put(mw->mlx_ptr, mw->win_ptr, x, y, map->value[i][1]);
        x += dx * (double)(abs(map->next->coor[i][0] - map->coor[i][0])) /
            (abs(map->next->coor[i][1] - map->coor[i][1]));
        y += dy;
    }
}
