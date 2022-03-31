/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:53:49 by qxia              #+#    #+#             */
/*   Updated: 2022/03/31 17:06:30 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1000
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define ESC 53
# define MLX_ERROR 1

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	**map;
	void	*sprite;
	void	*floor;
	void	*collect;
	void	*wall;
	int		coin_count;
	int		count_move;
	void	*door;
	int		row;
	int		col;
}t_data;

typedef struct s_pos
{
	int	i;
	int	j;
}t_pos;

typedef struct s_pos_e
{
	int	check_e;
	int	old_e_x;
	int	old_e_y;
}t_pos_e;

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	xpm_to_image(t_data *data);
void	image_to_win(t_data *data);
int		parse_map(t_data *data, char *file);
int		move_horizontal(t_data *data, int n, t_pos_e *check_e);
int		move_vertical(t_data *data, int n, t_pos_e *check_e);
int		key_event(int keycode, t_data *data);
int		mouse_event(t_data *data);
void	destroy(t_data *data);
void	free_map(t_data *data);
void	fini_game(t_data *data);
int		main(int argc, char **argv);
int		num_coin(t_data *data);
void	check_arguments(int argc, char **argv);
int		check_map(t_data *data);
char	*ft_map_error(int error_code);
void	ft_exit_error(int error_code, t_data *data);

#endif
