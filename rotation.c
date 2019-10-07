/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:11:56 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/07 21:02:11 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_map *map)
{
	int		i;
	int		j;

	j = 0;
	while (map != NULL)
	{
		i = 0;
		while (map->value[i] != NULL)
		{
			change_coor_x(&(map->coor[i][1]), &(map->value[i][0]));
			i++;
		}
		map = map->next;
	}
}

void	rotation_y(t_map *map)
{
	int		i;

	while (map != NULL)
	{
		i = 0;
		while (map->value[i] != NULL)
		{
			change_coor_y(&(map->coor[i][0]), &(map->value[i][0]));
			i++;
		}
		map = map->next;
	}
}

void	rotation_z(t_map *map)
{
	int		i;

	while (map != NULL)
	{
		i = 0;
		while (map->value[i] != NULL)
		{
			change_coor_z(&(map->coor[i][0]), &(map->coor[i][1]));
			i++;
		}
		map = map->next;
	}
}

int		rotation(int key, void *param)
{
	t_mw_map	*mw_map = (t_mw_map*)param;

	if (key == 7)
	{
		mlx_clear_window(mw_map->mw->mlx_ptr, mw_map->mw->win_ptr);
		rotation_x(mw_map->map);
		fill_iso(mw_map->mw, mw_map->map);
	}
	if (key == 16)
	{
		mlx_clear_window(mw_map->mw->mlx_ptr, mw_map->mw->win_ptr);
		rotation_y(mw_map->map);
		fill_iso(mw_map->mw, mw_map->map);
	}
	if (key == 6)
	{
		mlx_clear_window(mw_map->mw->mlx_ptr, mw_map->mw->win_ptr);
		rotation_z(mw_map->map);
		fill_iso(mw_map->mw, mw_map->map);
	}
    if (key == 53)
	{
		mlx_destroy_window(mw_map->mw->mlx_ptr, mw_map->mw->win_ptr);
		exit(1);
	}
	return (0);
}
