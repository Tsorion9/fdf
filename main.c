/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:05:20 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/07 20:18:58 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_map_width(t_map *map)
{
	int		width;

	width = 0;
	while (map != NULL)
	{
		map = map->next;
		width++;
	}
	return (width);
}

int		average_height(t_map *map)
{
	int		quantity;
	int		height;
	int		i;

	quantity = 0;
	height = 0;
	while (map != NULL)
	{
		i = 0;
		while (map->value[i] != NULL)
		{
			if (map->value[i][0] != 0)
			{
				height += map->value[i][0];
				quantity++;
			}
			i++;
		}
		map = map->next;
	}
	if (quantity == 0)
		return (4);
	return (height / quantity);
}

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_mw	*mw;
	int		fd;
	t_map	*map;

	map = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (0);
		else
		{
			map = check_val(fd);
			if (map == NULL)
				ft_putstr("not val\n");
			else
				ft_putstr("val\n");
		}
	}
	set_coor_iso(map, 20);
	mw = (t_mw*)malloc(sizeof(t_mw));
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
	mw->mlx_ptr = mlx_ptr;
	mw->win_ptr = win_ptr;
	fill_iso(mw, map);
	t_mw_map *mw_map;
	mw_map = (t_mw_map*)malloc(sizeof(t_mw_map));
	mw_map->mw = mw;
	mw_map->map = map;
	mlx_key_hook(win_ptr, rotation, mw_map);
	mlx_loop(mlx_ptr);
	return (0);
}
