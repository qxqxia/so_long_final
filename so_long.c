/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:16:54 by qxia              #+#    #+#             */
/*   Updated: 2022/03/31 16:50:22 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_line(t_data *data, char *file)
{
	int		fd;
	int		num_line;
	char	*str;

	num_line = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	data->col = ft_strlen(str) - 1;
	while (str)
	{
		num_line++;
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	close(fd);
	data->row = num_line;
}

int	parse_map(t_data *data, char *file)
{
	int	i;
	int	fd;

	read_line(data, file);
	i = 0;
	fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->row));
	if (!data->map || fd < 0)
	{
		ft_putstr_fd("Error:map is not exist\n", 2);
		free_map(data);
		return (1);
	}
	data->map[i] = get_next_line(fd);
	while (data->map[i])
	{
		i++;
		data->map[i] = get_next_line(fd);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_arguments(argc, argv);
	data.map = NULL;
	parse_map(&data, argv[1]);
	if (check_map(&data) != 0)
		return (-1);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, \
			data.col * 32, data.row * 32, "so_long");
	xpm_to_image(&data);
	image_to_win(&data);
	mlx_key_hook(data.win_ptr, key_event, &data);
	mlx_hook(data.win_ptr, 17, 1L << 2, mouse_event, &data);
	mlx_loop(data.mlx_ptr);
}
