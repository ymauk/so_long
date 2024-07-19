/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:06:16 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/19 09:12:14 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_images(t_vars *data)
{
	data->textures[P] = mlx_load_png("textures/player.png");
	if (!data->textures[P])
		error_handling(7, data);
	data->textures[C] = mlx_load_png("textures/collectable.png");
	if (!data->textures[C])
		error_handling(7, data);
	data->textures[W] = mlx_load_png("textures/wall.png");
	if (!data->textures[W])
		error_handling(7, data);
	data->textures[G] = mlx_load_png("textures/ground.png");
	if (!data->textures[G])
		error_handling(7, data);
	data->textures[E] = mlx_load_png("textures/exit.png");
	if (!data->textures[E])
		error_handling(7, data);
	data->image[P] = mlx_texture_to_image(data->mlx, data->textures[P]);
	if (!data->image[P])
		error_handling(8, data);
	data->image[C] = mlx_texture_to_image(data->mlx, data->textures[C]);
	if (!data->image[C])
		error_handling(8, data);
	data->image[W] = mlx_texture_to_image(data->mlx, data->textures[W]);
	if (!data->image[W])
		error_handling(8, data);
	data->image[G] = mlx_texture_to_image(data->mlx, data->textures[G]);
	if (!data->image[G])
		error_handling(8, data);
	data->image[E] = mlx_texture_to_image(data->mlx, data->textures[E]);
	if (!data->image[E])
		error_handling(8, data);
}

void	handling_images(t_vars *data)
{
	int	i;

	i = 0;
	if (data->map == NULL)
		error_handling(6, data);
	create_images(data);
	while (i < TEXTURES)
	{
		if (data->textures[i] == NULL)
			error_handling(6, data);
		i++;
	}
	printf("1%s\n", data->map[0]);
	printf("1%s\n", data->map[1]);
	printf("1%s\n", data->map[2]);
	printf("1%s\n", data->map[3]);
	printf("1%s\n", data->map[4]);
	printf("1%s\n", data->map[5]);
	place_g_w(data);
	place_c_e(data);
	place_p(data);
}

void	place_g_w(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	if (data == NULL || data->map == NULL || data->image[G] == NULL)
		error_handling(6, data);
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			if (data->mlx == NULL || data->image[G] == NULL)
				error_handling(9, data);
			if (mlx_image_to_window(data->mlx, data->image[G], j * 32, i * 32) == -1)
				error_handling(9, data);
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
			{
				mlx_image_to_window(data->mlx, data->image[C], j * 32, i * 32);
				data->amount_c += 1;
			}
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
			{
				mlx_image_to_window(data->mlx, data->image[P], j * 32, i * 32);
				data->p_x = j * 32;
				data->p_y = i * 32;
			}
			j++;
		}
		i++;
	}
}
