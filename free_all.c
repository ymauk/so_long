/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannismauk <yannismauk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:02:41 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/14 13:11:29 by yannismauk       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	free_all(t_vars *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free (data->map[i]);
		i++;
	}
	free (data->map);
	i = 0;
	while (i < TEXTURES)
	{
		free(data->textures[i]);
		i++;
	}
}

void	free_map_dup(char **map_dup)
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