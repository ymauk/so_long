/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:56:01 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/17 13:44:26 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	counting_rows(t_vars *data)
{
	int	rows;

	rows = 0;
	while (data->map[rows] != NULL)
		rows++;
	return (rows);
}

int	counting_columns(t_vars *data)
{
	int	colums;

	colums = 0;
	while (data->map[0][colums] != '\0')
		colums++;
	return (colums - 1);
}

int	counting_columns2(t_vars *data, int which_row)
{
	int	colums;

	colums = 0;
	while (data->map[which_row][colums] != '\0'
		&& data->map[which_row][colums] != '\n')
		colums++;
	return (colums);
}

char	**duplicate_map(t_vars *data, char **map_dup)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		map_dup[i] = ft_strdup(data->map[i]);
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
