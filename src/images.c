/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:58:46 by qxia              #+#    #+#             */
/*   Updated: 2022/04/01 11:36:30 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_to_image(t_data *data)
{
	int	img_width;
	int	img_height;

	data->sprite = mlx_xpm_file_to_image(data->mlx_ptr,
			"image/pikachu.xpm", &img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"image/tree.xpm", &img_width, &img_height);
	data->door = mlx_xpm_file_to_image(data->mlx_ptr,
			"image/door.xpm", &img_width, &img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"image/floor.xpm", &img_width, &img_height);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"image/collect.xpm", &img_width, &img_height);
}

void	*pointer_image(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
		return (data->sprite);
	else if (data->map[i][j] == '1')
		return (data->wall);
	else if (data->map[i][j] == 'C')
		return (data->collect);
	else if (data->map[i][j] == 'E')
		return (data->door);
	return (0);
}

void	image_to_win(t_data *data)
{
	void	*p;
	int		i;
	int		j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			mlx_put_image_to_window(data->mlx_ptr, \
					data->win_ptr, data->floor, 32 * j, 32 * i);
			p = pointer_image(data, i, j);
			if (p)
				mlx_put_image_to_window(data->mlx_ptr, \
						data->win_ptr, p, 32 * j, 32 * i);
			j++;
		}
		i++;
	}
}
