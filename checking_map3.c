/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannismauk <yannismauk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:02:00 by ymauk             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/14 13:11:14 by yannismauk       ###   ########.fr       */
=======
/*   Updated: 2024/07/14 17:07:58 by ymauk            ###   ########.fr       */
>>>>>>> 14Juli 17:34 Aktuellster Stand
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	checking_valid_characters(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
<<<<<<< HEAD
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
			&& data->map[i][j] != 'C' && data->map[i][j] != 'P'
			&& data->map[i][j] != 'E')
=======
			if (data->map[i][j] != '0' && data->map[i][j] != '1' &&
				data->map[i][j] != 'C' && data->map[i][j] != 'P'
				&& data->map[i][j] != 'E')
>>>>>>> 14Juli 17:34 Aktuellster Stand
				error_handling(4, data);
			j++;
		}
		i++;
	}
}