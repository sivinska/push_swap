/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:27:12 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/05 09:27:20 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 8

typedef	struct	s_struct
{
	int			i[2147483648];
	int			ret[2147483648];
	char		*buf[2147483648];
}				t_b;

int				get_next_line(const int fd, char **line);

#endif
