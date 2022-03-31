/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fini_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:05:08 by qxia              #+#    #+#             */
/*   Updated: 2022/03/31 16:56:23 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->collect);
	mlx_destroy_image(data->mlx_ptr, data->sprite);
	mlx_destroy_image(data->mlx_ptr, data->door);
	mlx_destroy_image(data->mlx_ptr, data->floor);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->row)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	exit(0);
}

void	fini_game(t_data *data)
{
	free_map(data);
	destroy(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
}
