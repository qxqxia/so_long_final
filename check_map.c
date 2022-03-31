/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qinxia <qinxia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:41:29 by qxia              #+#    #+#             */
/*   Updated: 2022/04/01 00:43:03 by qinxia           ###   ########.fr       */
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

static int	check_player(t_data *data)
{
	static int		player_count;
	int		i;
	int		j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] == 'P')
				player_count++;
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
	return (0);
}

static int	check_exit(t_data *data)
{
	static int		exit_count;
	int		i;
	int		j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count < 1)
	{
		ft_putstr_fd("Error: incorrect exit.\n", 2);
		free_map(data);
		return (-1);
	}
	return (0);
}

static int	check_wall(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] != '1' && (j == 0 || i == 0 \
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

static int	check_width(t_data *data)
{
	int		w;
	int		i;

	i = 0;
	while (i < data->row)
	{
		w = (int)ft_strlen(data->map[i]) - 1;
		if (w == 0 || data->col != w)
		{
			ft_putstr_fd("Error: map empty line or shape error.\n", 2);
			free_map(data);
			return (-1);
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
			if (data->map[i][j] != '1' && data->map[i][j] != '0' && \
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
	if (check_width(data) != 0 \
			|| check_wall(data) != 0 \
			|| check_char(data) != 0 \
			|| check_player(data) != 0 \
			|| check_exit(data) != 0 \
			|| check_coin(data) != 0)
		return (-1);
	return (0);
}