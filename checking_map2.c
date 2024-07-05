/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:35:11 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/05 12:53:56 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	checking_valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' || map[i][j] != '1' || map[i][j] != 'C'
			|| map[i][j] != 'P' || map[i][j] != 'E')
				error_handling(4);
			j++;
		}
		i++;
	}
}

void	checking_accessibility(char **map)
{
	char	**map_dup;
	t_point	size;
	t_point	p_position;
	map_dup = (char **)malloc((counting_rows(map) + 1) * sizeof(char));
	size.x = counting_columns(map);
	size.y = count_rows(map); #funktion schreiben welche die p position in der map findet und als strukt zurúck gibt!
	flood_fill(map_dup, size, );
}

typedef struct	s_point
{
	int x;
	int y;
} t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}