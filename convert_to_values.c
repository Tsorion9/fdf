/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:05:09 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/04 18:05:11 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int         count_of_digits(char *line, int i)
{
    int     count;

    count = 0;
    while (line[i] != '\0')
    {
        count++;
        i++;
    }
    return (count);
}

int         hexadecimal_to_decimal(char *line, int i)
{
    int     current_pow;
    int     res;

    current_pow = count_of_digits(line, i) - 1;
    res = 0;
    while (line[i] != '\0')
    {
        if (line[i] >= 48 && line[i] <= 59)
            res = res + ((line[i] - 48) * pow(16, current_pow));
        else
            res = res + ((line[i] - 55) * pow(16, current_pow));
        current_pow--;
        i++;
    }
    return (res);
}

int         *convert_value(char *line)
{
    int     *value;
    int     i;

    value = (int*)malloc(sizeof(int) * 2);
    i = 0;
    if (ft_strchr(line, ',') != NULL)
    {
        while (line[i] != 'x')
            i++;
        value[0] = ft_atoi(line);
        value[1] = hexadecimal_to_decimal(line, i + 1);
    }
    else
    {
        value[0] = ft_atoi(line);
        value[1] = 16777215;
    }
    return (value);
}

int         size_line(char **line_split)
{
    int     i;

    i = 0;
    while (line_split[i] != NULL)
        i++;
    return (i);
}

int         **convert_to_values(char **line_split)
{
    int     **value;
    int     i;

    value = (int**)malloc(sizeof(int*) * (size_line(line_split) + 1));
    value[size_line(line_split)] = NULL;
    i = 0;
    while (line_split[i] != NULL)
    {
        value[i] = convert_value(line_split[i]);
        i++;
    }
    return (value);
}
