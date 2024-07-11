/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:06:16 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/11 16:50:13 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	create_images(t_vars *data)
{
	data->textures[P] = mlx_load_png("textures/player.png");
	data->textures[C] = mlx_load_png("textures/collectable.png");
	data->textures[W] = mlx_load_png("textures/wall.png");
	data->textures[G] = mlx_load_png("textures/ground.png");
	data->textures[E] = mlx_load_png("textures/exit.png");
	data->image[P] = mlx_texture_to_image(data->mlx, data->textures[P]);
	data->image[C] = mlx_texture_to_image(data->mlx, data->textures[C]);
	data->image[W] = mlx_texture_to_image(data->mlx, data->textures[W]);
	data->image[G] = mlx_texture_to_image(data->mlx, data->textures[G]);
	data->image[E] = mlx_texture_to_image(data->mlx, data->textures[E]);
}

void	handling_images(t_vars *data)
{
	create_images(data);
	place_g_w(data);
	place_c_e(data);
	place_p(data);
}

void	place_g_w(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			mlx_image_to_window(data->mlx, data->image[G], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	place_c_e(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->image[W], j * 32, i * 32);
			if (data->map[i][j] == 'C')
				mlx_image_to_window(data->mlx, data->image[C], j * 32, i * 32);
			if (data->map[i][j] == 'E')
				mlx_image_to_window(data->mlx, data->image[E], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	place_p(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'P')
				mlx_image_to_window(data->mlx, data->image[P], j * 32, i * 32);
			j++;
		}
		i++;
	}
}