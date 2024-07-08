/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:35:11 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/08 15:12:12 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	checking_accessibility(char **map)
{
	char	**map_dup;
	t_point	size;
	t_point	p_position;
	int		rows_check;

	p_position = find_p_position(map);
	map_dup = (char **)malloc((counting_rows(map) + 1) * sizeof(char *));
	rows_check = counting_rows(map);
	if (map_dup == NULL)
		error_handling(6, map);
	map_dup = duplicate_map(map, map_dup);
	size.x = counting_columns(map);
	size.y = counting_rows(map);
	flood_fill(map_dup, size, p_position);
	check_flood_fill(map_dup, map);
	free_map(map_dup);
}

t_point	find_p_position(char **map)
{
	t_point	p_position;
	int		i;
	int		j;

	p_position.x = -1;
	p_position.y = -1;
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
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

void	check_flood_fill(char **map_dup, char **map)
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
				free_map(map_dup);
				error_handling(5, map);
			}
			j++;
		}
		i++;
	}
}
