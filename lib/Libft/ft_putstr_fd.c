/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:lib/Libft/ft_putstr_fd.c
/*   Created: 2024/03/13 12:54:57 by ymauk             #+#    #+#             */
/*   Updated: 2024/03/21 11:52:10 by ymauk            ###   ########.fr       */
=======
/*   Created: 2024/07/08 15:02:41 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/14 17:19:31 by ymauk            ###   ########.fr       */
>>>>>>> 14Juli 17:34 Aktuellster Stand:free_map.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD:lib/Libft/ft_putstr_fd.c
void	ft_putstr_fd(char *s, int fd)
=======
void	free_map(t_vars *data)
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

void	free_map_dup(char **map)
>>>>>>> 14Juli 17:34 Aktuellster Stand:free_map.c
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return ;
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
