/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:00:03 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/22 19:23:41 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_puthex(long int n, char kaze)
{
	if (n >= 16)
		ft_puthex(n / 16, kaze);
	if (n % 16 < 10)
		ft_putchar_fd('0' + n % 16, 1);
	else
		ft_putchar_fd(kaze + n % 16 - 10, 1);
}

int		ft_print_hex(unsigned int n, t_flags flags, char kaze)
{
	int len;
	int prec;
	int width;

	if (flags.dot == 1 && flags.precision == 0 && n == 0)
		return (0);
	len = ft_nbrlen(n);
	width = ft_set_width(flags, len);
	prec = ft_set_prec(flags, len);
	if (width != 0 && flags.dash == 0)
		ft_padding(width, ' ');
	if (prec)
		ft_padding(prec, '0');
	ft_puthex(n, kaze);
	if (width != 0 && flags.dash == 1)
		ft_padding(width, ' ');
	return (len + prec + width);
}
