/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:12:05 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/07 21:02:21 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_coor_x(int *y, int *z)
{
	int		previous_y;

	previous_y = *y;
	*y = cos(0.05) * previous_y + sin(0.05) * *z;
	*z = -sin(0.05) * previous_y + cos(0.05) * *z;
}

void	change_coor_y(int *x, int *z)
{
	int		previous_x;

	previous_x = *x;
	*x = previous_x * cos(0.05) + *z * sin(0.05);
	*z = -previous_x * sin(0.05) + *z * cos(0.05);
}

void	change_coor_z(int *x, int *y)
{
	int		previous_x;
	int		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = cos(0.05) * previous_x - \
		sin(0.05) * previous_y;
	*y = sin(0.05) * previous_x + \
		cos(0.05) * previous_y;
}
