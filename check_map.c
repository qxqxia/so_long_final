/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:41:29 by qxia              #+#    #+#             */
/*   Updated: 2022/03/31 17:10:36 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_coin(t_data *data)
{
	if (num_coin(data) < 1)
	{
		ft_putstr_fd("Error: incorrect collectible.\n", 2);
		free_map(data);
		return (-1);
	}
	return (0);
}

static int	check_player_exit(t_data *data)
{
	int		player_count;
	int		exit_count;
	int		i;
	int		j;

	player_count = 0;
	exit_count = 0;
	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] == 'P')
				player_count++;
			if (data->map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		ft_putstr_fd("Error: only one player is allowed.\n", 2);
		free_map(data);
		return (-1);
	}
	if (exit_count < 1)
	{
		ft_putstr_fd("Error: incorrect exit.\n", 2);
		free_map(data);
		return (-1);
	}
	return (0);
}

static int	check_wall_and_width(t_data *data)
{
	int		w;
	int		i;
	int		j;

	i = 0;
	if (data->col == 0)
	{
		ft_putstr_fd("Error: first line is empty\n", 2);
		free_map(data);
		return (-1);
	}
	while (i < data->row)
	{
		w = (int)ft_strlen(data->map[i]) - 1;
		if (w == 0)
		{
			ft_putstr_fd("Error: map contains empty line.\n", 2);
			free_map(data);
			return (-1);
		}
		if (data->col != w)
		{
			ft_putstr_fd("Error: map shape is not right.\n", 2);
			free_map(data);
			return (-1);
		}
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] != '1' \
					&& (j == 0 || i == 0 \
						|| (i == data->row - 1) || (j == data->col - 1)))
			{
				ft_putstr_fd("Error: map is not surounded by walls.\n", 2);
				free_map(data);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_char(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] != '1' && \
				data->map[i][j] != '0' && \
				data->map[i][j] != 'P' && \
				data->map[i][j] != 'E' && \
				data->map[i][j] != 'C')
			{
				ft_putstr_fd("Error: map contains unexpected character.\n", 2);
				free_map(data);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(t_data *data)
{
	if (check_wall_and_width(data) != 0 \
			|| check_char(data) != 0 \
			|| check_player_exit(data) != 0 \
			|| check_coin(data) != 0)
		return (-1);
	return (0);
}
