/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:49:28 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/11 15:14:35 by ymauk            ###   ########.fr       */
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

// void	collectable_exit(t_vars *data, int x, int y)
// {
// 	t_window	size_w;

// 	size_w.x = x * 32;
// 	size_w.y = y * 32;
// 	if (data->map[y][x] == 'C')
// 	{
// 		data->c_counter++;
// 		data->texture = mlx_load_png("./textures/ground.png");
// 		if (!data->texture)
// 			error_handling(7, data->map);
// 		data->img = mlx_texture_to_image(data->mlx, data->texture);
// 		if (!data->img)
// 			error_handling(8, data->map);
// 		if (mlx_image_to_window(data->mlx, data->img, size_w.x, size_w.y) > 0)
// 			error_handling(9, data->map);
// 		check_z_instances(data);
// 	}
// }
// void	check_z_instances(t_vars *data)
// {
// 	int	i;
// 	int	z;

// 	i = 0;
// 	z = 0;
// 	while (data->img[G]->instances[i].z < data->img[PLAYER]->instances[0].z)
// 		i++;
// 	z = data->img[S]->instances[i].z + 1;
// 	data->img[P]->instances[0].z = z;
// }