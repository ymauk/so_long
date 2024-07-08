/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:02:00 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/08 15:14:06 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	checking_valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
			&& map[i][j] != 'P' && map[i][j] != 'E')
				error_handling(4, map);
			j++;
		}
		i++;
	}
}