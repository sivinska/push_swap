/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:26:50 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/17 14:35:34 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		store_line(int i, int j, char *buf, char **line)
{
	char			*tmp;
	char			*tmp2;

	while (buf[i] && buf[i] != '\n')
		i++;
	tmp = ft_strnew(i - j);
	ft_strncpy(tmp, buf + j, (i - j));
	tmp2 = *line;
	*line = ft_strjoin(tmp2, tmp);
	free(tmp2);
	free(tmp);
	return (buf[i] == '\n' ? i : -1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_b a;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(0);
	if (!a.buf[fd])
		a.buf[fd] = ft_strnew(BUFF_SIZE);
	if (a.i[fd] > 0)
	{
		a.i[fd] = store_line(a.i[fd], a.i[fd], a.buf[fd], line);
		if (a.i[fd]++ != -1)
			return (1);
	}
	while (a.i[fd] == 0 && (a.ret[fd] = read(fd, a.buf[fd], BUFF_SIZE)) != 0
		&& a.ret[fd] != -1)
	{
		a.buf[fd][a.ret[fd]] = 0;
		a.i[fd] = store_line(a.i[fd], a.i[fd], a.buf[fd], line);
		a.i[fd]++;
	}
	if (a.ret[fd] == -1)
		return (-1);
	return (a.ret[fd] == 0 && *line[0] == 0 ? 0 : 1);
}
