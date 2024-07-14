/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannismauk <yannismauk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:35:11 by ymauk             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/14 13:10:55 by yannismauk       ###   ########.fr       */
=======
/*   Updated: 2024/07/14 17:15:05 by ymauk            ###   ########.fr       */
>>>>>>> 14Juli 17:34 Aktuellster Stand
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	checking_accessibility(t_vars *data)
{
	char	**map_dup;
	t_point	size;
	t_point	p_position;

	p_position = find_p_position(data);
	map_dup = (char **)malloc((counting_rows(data) + 1) * sizeof(char *));
<<<<<<< HEAD
=======
	rows_check = counting_rows(data);
>>>>>>> 14Juli 17:34 Aktuellster Stand
	if (map_dup == NULL)
		error_handling(6, data);
	map_dup = duplicate_map(data, map_dup);
	size.x = counting_columns(data);
	size.y = counting_rows(data);
	flood_fill(map_dup, size, p_position);
	check_flood_fill(map_dup, data);
<<<<<<< HEAD
=======
	free_map_dup(map_dup);
>>>>>>> 14Juli 17:34 Aktuellster Stand
}

t_point	find_p_position(t_vars *data)
{
	t_point	p_position;
	int		i;
	int		j;

	p_position.x = -1;
	p_position.y = -1;
	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				p_position.x = j;
				p_position.y = i;
			}
			j++;
		}
		i++;
	}
	return (p_position);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] == '1'
		|| tab[cur.y][cur.x] == 'F')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	check_flood_fill(char **map_dup, t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (map_dup[i] != NULL)
	{
		j = 0;
		while (map_dup[i][j] != '\0' && map_dup[i][j] != '\n')
		{
			if (map_dup[i][j] != 'F' && map_dup[i][j] != '1')
			{
				free_map_dup(map_dup);
				error_handling(5, data);
			}
			j++;
		}
		i++;
	}
}
