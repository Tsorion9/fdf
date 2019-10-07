/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:09:19 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/07 21:02:57 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

typedef struct		s_mw
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mw;

typedef struct		s_map
{
	int				**value;
	int				**coor;
	int				size;
	struct s_map	*next;
}					t_map;

typedef struct		s_mw_map
{
	t_mw	*mw;
	t_map	*map;
}					t_mw_map;

t_map				*check_val(int fd);
t_map				*add_to_map(t_map *map, int **value, int size);
t_map				*create_map(int **value, int size);
int					check_line(char **line_split);
int					check_value(char *value);
int					check_hexadecimal(char *value, int i);
int					**convert_to_values(char **line_split);
int					size_line(char **line_split);
int					*convert_value(char *line);
int					hexadecimal_to_decimal(char *line, int i);
int					count_of_digits(char *line, int i);
void				free_map(t_map *map);
void				free_linesplit(char **line_split);
void				free_value(int **value);
int					check_size_map(t_map *map);
void        		fill_iso(t_mw *mw, t_map *map);
void    			vertical_line(t_map *map, int i, t_mw *mw);
void    			gorizontal_line(t_map *map, int i, t_mw *mw);
void    			iso(int *x, int *y, int z, t_map *map);
void        		set_coor_iso(t_map *map, int step);
void        		create_coor(t_map *map);
void				fill_line(t_map *map, int i, int len, t_mw *mw);
void				fill_line1(t_map *map, int i, int len, t_mw *mw);
void				fill_line2(t_map *map, int i, int len, t_mw *mw);
void				fill_line3(t_map *map, int i, int len, t_mw *mw);
int					average_height(t_map *map);
int					rotation(int key, void *param);
void				rotation_z(t_map *map);
void				rotation_y(t_map *map);
void				rotation_x(t_map *map);
void				change_coor_z(int *x, int *y);
void				change_coor_y(int *x, int *z);
void				change_coor_x(int *y, int *z);
