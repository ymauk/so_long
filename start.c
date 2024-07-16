/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:10:36 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/16 09:09:49 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	start(int argc, char **argv, t_vars *data)
{
	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			error_handling(0, data);
		map(argv, data);
		checking_map(data);
	}
	else
		error_handling(0, data);
}
