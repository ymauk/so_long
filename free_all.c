/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:02:41 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/12 16:46:54 by ymauk            ###   ########.fr       */
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
