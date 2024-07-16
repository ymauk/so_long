/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:49:28 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/16 11:05:30 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	window_size(t_vars *data, t_window *size_w)
{
	size_w->x = counting_columns(data);
	size_w->y = counting_rows(data);
}

void	collectable_exit(t_vars *data, int x, int y)
{
	if (data->map[y][x] == 'C')
	{
		data->c_counter += 1;
		mlx_image_to_window(data->mlx, data->image[G], x * 32, y * 32);
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
	while (data->image[G]->instances[i].z < data->image[P]->instances[0].z)
		i++;
	z = data->image[G]->instances[i].z + 1;
	data->image[P]->instances[0].z = z;
}

void	display_text(t_vars *data)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = ((counting_columns(data) + 125) / 2);
	y1 = (counting_rows(data));
	x2 = (counting_columns(data) + 115 / 2);
	y2 = y1 + 30;
	place_g_w(data);
	mlx_put_string(data->mlx, "Congratulations, you won :)", x1, y2);
	mlx_put_string(data->mlx, "Please press enter to exit!", x2, y2 + 60);
}


// data->c_counter += 1;
// 		data->map[y][x] = '0';
// 		data->texture = mlx_load_png("./textures/ground.png");
// 		if (!data->texture)
// 			error_handling(7, data);
// 		data->img = mlx_texture_to_image(data->mlx, data->texture);
// 		if (!data->img)
// 			error_handling(8, data);
// 		if (mlx_image_to_window(data->mlx, data->img, size_w.x, size_w.y) > 0)
// 			error_handling(9, data);
// 		check_z_instances(data);