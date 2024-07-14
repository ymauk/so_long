/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannismauk <yannismauk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:10:36 by ymauk             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/14 12:33:39 by yannismauk       ###   ########.fr       */
=======
/*   Updated: 2024/07/14 17:01:18 by ymauk            ###   ########.fr       */
>>>>>>> 14Juli 17:34 Aktuellster Stand
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	start(int argc, char **argv, t_vars *data)
{
<<<<<<< HEAD

	data->map = NULL;
=======
>>>>>>> 14Juli 17:34 Aktuellster Stand
	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			error_handling(0, data);
<<<<<<< HEAD
=======
		map(argv, data);
>>>>>>> 14Juli 17:34 Aktuellster Stand
		checking_map(data);
	}
	else
		error_handling(0, data);
}
