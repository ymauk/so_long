/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:05:20 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/14 16:10:15 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/Libft/libft.h"
# include "lib/printf/ft_printf.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/libmlx/include/MLX42/MLX42.h"

# define TEXTURES			5
# define G					0
# define P					1
# define W					2
# define C					3
# define E					4

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
	mlx_texture_t	*textures[TEXTURES];

	mlx_image_t		*image[TEXTURES];
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	mlx_key_data_t	keydata;
	mlx_image_t		*player_img;

	char			**map;
	int				counter;
	int				p_x;
	int				p_y;
	int				amount_c;
	int				c_counter;

}	t_vars;

void		map(char **argv, t_vars *data);
int			count_rows(int fd);
int			count_rows2(char *part_buffer, int counter, int i);

void		checking_map(t_vars *data);
void		checking_contain(t_vars *data);
int			checking_contain2(t_vars *data, char ecp);
void		checking_rectangle(t_vars *data);
void		checking_walls(t_vars *data);

void		checking_accessibility(t_vars *data);
t_point		find_p_position(t_vars *data);
void		flood_fill(char **tab, t_point size, t_point begin);
void		fill(char **tab, t_point size, t_point cur, char to_fill);
void		check_flood_fill(char **map_dup, t_vars *data);

void		checking_valid_characters(t_vars *data);

int			counting_rows(t_vars *data);
int			counting_columns(t_vars *data);
int			counting_columns2(t_vars *data, int which_row);
char		**duplicate_map(t_vars *data, char **map_dup);
void		find_player(t_vars *data);

void		error_handling(int number_error, t_vars *data);

void		free_all(t_vars *data);
void		free_map_dup(char **map_dup);

void		window_size(t_vars *data, t_window *size_w);
void		collectable_exit(t_vars *data, int x, int y);
void		check_z_instances(t_vars *data);
void		display_text(t_vars *data);

void		handling_images(t_vars *data);
void		place_c_e(t_vars *data);
void		place_g_w(t_vars *data);
void		place_p(t_vars *data);

void		start(int argc, char **argv, t_vars *data);

void		keyhook(mlx_key_data_t keydata, void *param);
void		move_up(t_vars *data);
void		move_down(t_vars *data);
void		move_left(t_vars *data);
void		move_right(t_vars *data);

#endif