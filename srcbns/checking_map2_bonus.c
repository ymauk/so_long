/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:35:11 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/19 10:06:26 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	checking_accessibility_b(t_vars *data)
{
	char	**map_dup;
	t_point	size;
	t_point	p_position;

	p_position = find_p_position_b(data);
	map_dup = (char **)malloc((counting_rows_b(data) + 1) * sizeof(char *));
	if (map_dup == NULL)
		error_handling_b(6, data);
	map_dup = duplicate_map_b(data, map_dup);
	size.x = counting_columns_b(data);
	size.y = counting_rows_b(data);
	flood_fill_b(map_dup, size, p_position);
	check_flood_fill_b(map_dup, data);
	free_map_dup_b(map_dup);
}

t_point	find_p_position_b(t_vars *data)
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

void	flood_fill_b(char **tab, t_point size, t_point begin)
{
	fill_b(tab, size, begin, tab[begin.y][begin.x]);
}

void	fill_b(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] == '1'
		|| tab[cur.y][cur.x] == 'F')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill_b(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill_b(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill_b(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill_b(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	check_flood_fill_b(char **map_dup, t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (map_dup[i] != NULL)
	{
		j = 0;
		while (map_dup[i][j] != '\0' && map_dup[i][j] != '\n')
		{
			if (map_dup[i][j] != 'F' && map_dup[i][j] != '1'
				&& map_dup[i][j] != '0')
			{
				free_map_dup_b(map_dup);
				error_handling_b(5, data);
			}
			j++;
		}
		i++;
	}
}
