/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:33:42 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/24 14:54:33 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_nbr_len(long long int n)
{
	int				ret;
	long long int	nbr;

	ret = 1;
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	while (nbr /= 10)
		ret++;
	return (ret);
}
