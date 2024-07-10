/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:05:20 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/09 16:45:53 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/Libft/libft.h"
# include "lib/printf/ft_printf.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/libmlx/include/MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_window
{
	int	x;
	int	y;
}	t_window;

typedef struct s_vars
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

}	t_vars;

char		**map(char **argv);
int			count_rows(int fd);
int			count_rows2(char *part_buffer, int counter, int i);

void		checking_map(char **map);
void		checking_contain(char **map);
int			checking_contain2(char **map, char ecp);
void		checking_rectangle(char **map);
void		checking_walls(char **map);

void		checking_accessibility(char **map);
t_point		find_p_position(char **map);
void		flood_fill(char **tab, t_point size, t_point begin);
void		fill(char **tab, t_point size, t_point cur, char to_fill);
void		check_flood_fill(char **map_dup, char **map);

void		checking_valid_characters(char **map);

int			counting_rows(char **map);
int			counting_columns(char **map);
int			counting_columns2(char **map, int which_row);
char		**duplicate_map(char **map, char **map_dup);

void		error_handling(int number_error, char **map);

void		free_map(char **map);

void		window_size(char **created_map, t_window *size_w);

void		handling_images(t_vars *data, char **map, t_window *size_w);
void		place_image(char **map, char comp, t_window *size_w, t_vars *data);
void		exc_image(t_vars *data, t_window *size_w, char **map, char comp);
void		place_ground(char **map, t_window *size_w, t_vars *data);

#endif