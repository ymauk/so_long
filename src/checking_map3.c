/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:02:00 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/17 13:43:29 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
			&& data->map[i][j] != 'C' && data->map[i][j] != 'P'
			&& data->map[i][j] != 'E')
				error_handling(4, data);
			j++;
		}
		i++;
	}
}
