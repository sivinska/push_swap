/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_len_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:54:16 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/24 14:54:27 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_nbr_len_push(long long int n)
{
	int				ret;
	long long int	nbr;

	ret = 1;
	if (n < 0)
	{
		nbr = -n;
		ret = ret + 1;
	}
	else
		nbr = n;
	while (nbr /= 10)
		ret++;
	return (ret);
}
