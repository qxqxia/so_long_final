/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:34:06 by qxia              #+#    #+#             */
/*   Updated: 2022/03/31 16:03:47 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_ber(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (strncmp(&filename[i], ".ber", 5) == 0)
			return ;
		i++;
	}
	ft_putstr_fd("Error:invalide file type!\n", 2);
	exit(1);
}

void	check_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error:invalide args number!\n", 2);
		exit(1);
	}
	ft_check_ber(argv[1]);
}

int	num_coin(t_data *data)
{
	int		coin_num;
	int		i;
	int		j;

	coin_num = 0;
	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] == 'C')
				coin_num++;
			j++;
		}
		i++;
	}
	return (coin_num);
}
