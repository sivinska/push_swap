/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:27:26 by sivinska          #+#    #+#             */
/*   Updated: 2018/02/13 12:21:56 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		store(int i, int j, char *buffer, char **line)
{
	char	*tmp;
	char	*tmp2;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp = ft_strnew(i - j);
	ft_strncpy(tmp, buffer + j, (i - j));
	tmp2 = *line;
	*line = ft_strjoin(tmp2, tmp);
	free(tmp2);
	free(tmp);
	if (buffer[i] == '\n')
		return (i);
	else
		return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	int			i[OPEN_MAX];
	int			ret[OPEN_MAX];

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd >= OPEN_MAX)
		return (-1);
	*line = ft_strnew(0);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strnew(BUFF_SIZE);
	if (i[fd] > 0)
	{
		i[fd] = store(i[fd], i[fd], buffer[fd], line);
		if (i[fd]++ != -1)
			return (1);
	}
	while (i[fd] == 0 && (ret[fd] = read(fd, buffer[fd], BUFF_SIZE)) > 0)
	{
		buffer[fd][ret[fd]] = '\0';
		i[fd] = store(i[fd], i[fd], buffer[fd], line);
		i[fd]++;
	}
	if (ret[fd] == -1)
		return (-1);
	return ((ret[fd] == 0 && *line[0] == 0) ? 0 : 1);
}
