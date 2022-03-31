/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:02:40 by qxia              #+#    #+#             */
/*   Updated: 2022/03/31 17:11:58 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_move_horizontal(t_data *data, t_pos pos, int n, t_pos_e *check_e)
{
	data->coin_count = num_coin(data);
	if (data->map[pos.i][pos.j + n] == 'E' && data->coin_count == 0)
	{
		fini_game(data);
	}
	if (data->map[pos.i][pos.j + n] == '0' \
			|| data->map[pos.i][pos.j + n] == 'C' \
			|| data->map[pos.i][pos.j + n] == 'E')
	{
		if (data->map[pos.i][pos.j + n] == 'E')
		{
			check_e->old_e_x = pos.j + n;
			check_e->old_e_y = pos.i;
			check_e->check_e = 0;
		}
		data->map[pos.i][pos.j + n] = 'P';
		data->map[pos.i][pos.j] = '0';
		if (check_e->old_e_x != -1 && \
				check_e->old_e_y != -1 && check_e->check_e != 0)
		{
			data->map[check_e->old_e_y][check_e->old_e_x] = 'E';
			check_e->old_e_x = -1;
			check_e->old_e_y = -1;
		}
		destroy(data);
		xpm_to_image(data);
		image_to_win(data);
		data->count_move ++;
		data->coin_count--;
		ft_putstr_fd("\rmovements total: ", 1);
		ft_putnbr_fd(data->count_move, 1);
		if (check_e->old_e_x != -1 && check_e->old_e_y != -1)
			check_e->check_e = 1;
	}
}

int	move_horizontal(t_data *data, int n, t_pos_e *check_e)
{
	t_pos	pos;

	pos.i = 0;
	while (pos.i < data->row)
	{
		pos.j = 0;
		while (pos.j < data->col)
		{
			if (data->map[pos.i][pos.j] == 'P')
			{
				check_move_horizontal(data, pos, n, check_e);
				return (1);
			}
			pos.j++;
		}
		pos.i++;
	}
	return (0);
}

void	check_move_vertical(t_data *data, t_pos pos, int n, t_pos_e *check_e)
{
	data->coin_count = num_coin(data);
	if (data->map[pos.i + n][pos.j] == 'E' && data->coin_count == 0)
	{
		fini_game(data);
	}
	if (data->map[pos.i + n][pos.j] == '0' \
			|| data->map[pos.i + n][pos.j] == 'C' \
			|| data->map[pos.i + n][pos.j] == 'E')
	{
		if (data->map[pos.i + n][pos.j] == 'E')
		{
			check_e->old_e_x = pos.j;
			check_e->old_e_y = pos.i + n;
			check_e->check_e = 0;
		}
		data->map[pos.i + n][pos.j] = 'P';
		data->map[pos.i][pos.j] = '0';
		if (check_e->old_e_x != -1 && \
				check_e->old_e_y != -1 && check_e->check_e != 0)
		{
			data->map[check_e->old_e_y][check_e->old_e_x] = 'E';
			check_e->old_e_x = -1;
			check_e->old_e_y = -1;
		}
		destroy(data);
		xpm_to_image(data);
		image_to_win(data);
		data->count_move ++;
		data->coin_count--;
		ft_putstr_fd("\rmovements total: ", 1);
		ft_putnbr_fd(data->count_move, 1);
		if (check_e->old_e_x != -1 && check_e->old_e_y != -1)
			check_e->check_e = 1;
	}	
}

int	move_vertical(t_data *data, int n, t_pos_e *check_e)
{
	t_pos	pos;

	pos.i = 0;
	pos.j = 0;
	while (data->map[pos.i][pos.j] != '\0')
	{
		if (data->map[pos.i][pos.j] == 'P')
		{
			check_move_vertical(data, pos, n, check_e);
			return (1);
		}
		if (data->map[pos.i][pos.j] == '\n')
		{
			pos.i++;
			pos.j = 0;
		}
		pos.j++;
	}
	return (0);
}
