/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:06:16 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/09 16:52:41 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


void	handling_images(t_vars *data, char **map, t_window *size_w)
{
	place_ground(map, size_w, data);
	place_image(map, '1', size_w, data);
	place_image(map, 'E', size_w, data);
	place_image(map, 'C', size_w, data);
	place_image(map, 'P', size_w, data);
}

void	place_ground(char **map, t_window *size_w, t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			size_w->x = j * 32;
			size_w->y = i * 32;
			exc_image(data, size_w, map, '0');
			j++;
		}
		i++;
	}
}

void	place_image(char **map, char comp, t_window *size_w, t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == comp)
			{
				size_w->x = j * 32;
				size_w->y = i * 32;
				exc_image(data, size_w, map, comp);
			}
			j++;
		}
		i++;
	}
}

void	exc_image(t_vars *data, t_window *size_w, char **map, char comp)
{
	char	*image;

	if (comp == '1')
		image = "./textures/wall.png";
	else if (comp == '0')
		image = "./textures/ground.png";
	else if (comp == 'C')
		image = "./textures/collectable.png";
	else if (comp == 'E')
		image = "./textures/exit.png";
	else if (comp == 'P')
		image = "./textures/player.png";
	data->texture = mlx_load_png(image);
	if (!data->texture)
		error_handling(7, map);
	data->img = mlx_texture_to_image(data->mlx, data->texture);
	if (!data->img)
		error_handling(8, map);
	if (mlx_image_to_window(data->mlx, data->img, size_w->x, size_w->y) > 0)
		error_handling(9, map);
}

