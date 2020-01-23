/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:00:03 by tprevel           #+#    #+#             */
/*   Updated: 2020/01/23 14:18:05 by tprevel          ###   ########.fr       */
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

	if (flags.dot == 1 && flags.precision == 0 && n == 0 && flags.width == 0)
		return (0);
	len = ft_hexlen(n);
	prec = ft_set_prec(flags, len);
	width = ft_set_width(flags, len + prec);
	if (width != 0 && flags.dash == 0)
		ft_padding(width, ' ');
	if (prec)
		ft_padding(prec, '0');
	if (!(flags.dot == 1 && flags.precision == 0 && n == 0))
		ft_puthex(n, kaze);
	else
		write(1, " ", 1);
	if (width != 0 && flags.dash == 1)
		ft_padding(width, ' ');
	return (len + prec + width);
}
