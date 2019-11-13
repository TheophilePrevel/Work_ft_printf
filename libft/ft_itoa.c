/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:04:51 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/09 16:47:22 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_int_sizing(long n)
{
	int out;

	out = 0;
	while (n / 10 != 0)
	{
		out++;
		n = n / 10;
	}
	return (++out);
}

char		*ft_itoa(int n)
{
	char	*out;
	long	nbr;
	int		nbr_size;
	int		i;
	int		sign_factor;

	i = 0;
	nbr = n;
	nbr = (nbr < 0) ? -nbr : nbr;
	sign_factor = (n < 0) ? 1 : 0;
	nbr_size = ft_int_sizing(nbr);
	if ((out = malloc(sizeof(char) * (nbr_size + 1 + sign_factor))) == NULL)
		return (NULL);
	if (n < 0)
		out[0] = '-';
	while (nbr / 10 != 0)
	{
		out[nbr_size - 1 - i + sign_factor] = '0' + (nbr % 10);
		nbr = nbr / 10;
		i++;
	}
	out[nbr_size - 1 - i++ + sign_factor] = '0' + (nbr % 10);
	out[i + sign_factor] = '\0';
	return (out);
}
