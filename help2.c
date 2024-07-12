/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:49:28 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/12 16:06:59 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	window_size(char **created_map, t_window *size_w)
{
	size_w->x = counting_columns(created_map);
	size_w->y = counting_rows(created_map);
}

void	collectable_exit(t_vars *data, int x, int y)
{
	t_window	size_w;

	size_w.x = x * 32;
	size_w.y = y * 32;
	if (data->map[y][x] == 'C')
	{
		data->c_counter += 1;
		data->map[y][x] = '0';
		data->texture = mlx_load_png("./textures/ground.png");
		if (!data->texture)
			error_handling(7, data->map);
		data->img = mlx_texture_to_image(data->mlx, data->texture);
		if (!data->img)
			error_handling(8, data->map);
		if (mlx_image_to_window(data->mlx, data->img, size_w.x, size_w.y) > 0)
			error_handling(9, data->map);
		check_z_instances(data);
	}
	if (data->map[y][x] == 'E' && data->c_counter == data->amount_c)
	{
		display_text(data);
	}
}

void	check_z_instances(t_vars *data)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (data->image[P]->instances[i].z < data->image[G]->instances[0].z)
		i++;
	z = data->image[P]->instances[i].z + 1;
	data->image[P]->instances[0].z = z;
}

void	display_text(t_vars *data)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = ((counting_columns(data->map) + 125) / 2);
	y1 = (counting_rows(data->map));
	x2 = (counting_columns(data->map) + 115 / 2);
	y2 = y1 + 30;
	place_g_w(data);
	mlx_put_string(data->mlx, "Congratulations, you won :)", x1, y2);
	mlx_put_string(data->mlx, "Please press enter to exit!", x2, y2 + 60);
}
