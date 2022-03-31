/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:15:15 by qxia              #+#    #+#             */
/*   Updated: 2022/03/17 15:38:39 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_lue(char	*str)
{
	char	*res;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*new_line(char *save)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	while (save[i])
		s[j++] = save[i++];
	free (save);
	s[j] = '\0';
	return (s);
}

int	is_newline(char	*save)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_save(int fd, char *buf)
{
	int			read_n;
	char		*line;
	static char	*save;

	read_n = 1;
	while (read_n != 0 && !is_newline(save))
	{
		read_n = read(fd, buf, BUFFER_SIZE);
		if (read_n < 0)
		{
			free (buf);
			return (NULL);
		}
		buf[read_n] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	line = line_lue(save);
	save = new_line(save);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = get_save(fd, buf);
	return (line);
}
