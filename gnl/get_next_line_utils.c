/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:53:58 by qxia              #+#    #+#             */
/*   Updated: 2022/03/18 14:17:52 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}	

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	len;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = i + j + 1;
	s = malloc(sizeof(char) * (i + j + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && i < len && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && i < len && s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	free ((char *)s1);
	return (s);
}
