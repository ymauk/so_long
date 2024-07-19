/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:02:41 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/19 10:03:43 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_all_b(t_vars *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free (data->map[i]);
			i++;
		}
		free (data->map);
		i = 0;
		while (i < TEXTURES)
		{
			if (data->textures[i] != NULL)
			{
				mlx_delete_texture(data->textures[i]);
			}
			i++;
		}
	}
}

void	free_map_dup_b(char **map_dup)
{
	int	i;

	i = 0;
	while (map_dup[i] != NULL)
	{
		free (map_dup[i]);
		i++;
	}
	free (map_dup);
}
