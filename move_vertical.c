/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qinxia <qinxia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 00:53:00 by qinxia            #+#    #+#             */
/*   Updated: 2022/04/01 00:53:00 by qinxia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void position_move_v(t_data *data, t_pos pos, int n, t_pos_e *check_e)
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
		ft_putstr_fd("\rmovements total: ", 1);
		ft_putnbr_fd(++(data->count_move), 1);
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
		position_move_v(data, pos, n, check_e);
		data->coin_count--;
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