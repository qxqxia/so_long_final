/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:04:34 by qxia              #+#    #+#             */
/*   Updated: 2022/04/01 09:59:08 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_event(int keycode, t_data *data)
{
	static t_pos_e	check_e = {0, -1, -1};

	if (keycode == ESC)
		fini_game(data);
	if (keycode == KEY_UP)
		move_vertical(data, -1, &check_e);
	else if (keycode == KEY_DOWN)
		move_vertical(data, 1, &check_e);
	else if (keycode == KEY_LEFT)
		move_horizontal(data, -1, &check_e);
	else if (keycode == KEY_RIGHT)
		move_horizontal(data, 1, &check_e);
	return (0);
}

int	mouse_event(t_data *data)
{
	fini_game(data);
	return (1);
}
