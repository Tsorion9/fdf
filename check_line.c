/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:04:54 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/04 18:57:47 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int         check_hexadecimal(char *value, int i)
{
    int     size;

    size = 0;
    while (((value[i] >= 48 && value[i] <= 57) || (value[i] >= 65 && value[i] <= 70)) 
        && value[i] != '\0')
    {
        size++;
        i++;
    }
    if (size == 0 || size > 6 || value[i] != '\0')
        return (0);
    return (1);
}

int         check_value(char *value)
{
    int     i;

    i = 0;
    if (value[i] == '-')
        i++;
    while (value[i] >= 48 && value[i] <= 57 && value[i] != '\0')
        i++;
    if ((value[0] != '-') && (i == 0 || i > 3))
        return (0);
    if ((value[0] == '-') && (i == 1 || i > 4))
        return (0);
    else if (value[i] == '\0')
        return (1);
    if (value[i] != ',')
        return (0);
    if (value[i + 1] != '0')
        return (0);
    if (value[i + 2] != 'x')
        return (0);
    i = i + 3;
    if (check_hexadecimal(value, i) == 0)
        return (0);
    return (1);
}

int         check_line(char **line_split)
{
    int     i;

    if (line_split == NULL)
        return (0);
    i = 0;
    while (line_split[i] != NULL)
    {
        if (check_value(line_split[i]) == 0)
            return (0);
        i++;
    }
    if (i < 2)
        return (0);
    return (1);
}
