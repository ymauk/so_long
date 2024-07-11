/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:56:01 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/11 16:02:57 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	counting_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows] != NULL)
		rows++;
	return (rows);
}

int	counting_columns(char **map)
{
	int	colums;

	colums = 0;
	while (map[0][colums] != '\0')
		colums++;
	return (colums - 1);
}

int	counting_columns2(char **map, int which_row)
{
	int	colums;

	colums = 0;
	while (map[which_row][colums] != '\0' && map[which_row][colums] != '\n')
		colums++;
	return (colums);
}

char	**duplicate_map(char **map, char **map_dup)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		map_dup[i] = ft_strdup(map[i]);
		i++;
	}
	map_dup[i] = NULL;
	return (map_dup);
}

void	find_player(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'C')
			{
				data->p_x = j * 32;
				data->p_y = i * 32;
				j++;
			}
			i++;
		}
	}
}
