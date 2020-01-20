/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:00:21 by tprevel           #+#    #+#             */
/*   Updated: 2020/01/20 18:34:48 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(long int n)
{
	int	len;

	len = (n < 0) ? 2 : 1;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		ft_set_width(t_flags flags, int len)
{
	int out;

	if (flags.zero == 1 && flags.dot == 0 && flags.dash == 0)
		return (0);
	else
		out = (flags.width > len) ? flags.width - len : 0;
	return (out);
}

int		ft_set_prec(t_flags flags, int len)
{
	int out;

	if (flags.zero == 1 && flags.dot == 0 && flags.dash == 0)
		out = (flags.width > len) ? flags.width - len : 0;
	else
		out = (flags.precision > len) ? flags.precision - len : 0;
	return (out);
}

void	ft_putint(long int n)
{
	if (n > 0)
		n = -n;
	if (n < -9)
		ft_putint(n / 10);
	ft_putchar_fd('0' - n % 10, 1);
}

int		ft_print_int(long int n, t_flags flags)
{
	int len;
	int prec;
	int width;

	if (flags.dot == 1 && flags.precision == 0 && n == 0)
		return (0);
	len = ft_nbrlen(n);
	prec = ft_set_prec(flags, len - ((n < 0) * (flags.dot == 1)));
	width = ft_set_width(flags, len + prec);
	if (width != 0 && flags.dash == 0)
		ft_padding(width, ' ');
	if (n < 0)
		write(1, "-", 1);
	if (prec)
		ft_padding(prec, '0');
	ft_putint(n);
	if (width != 0 && flags.dash == 1)
		ft_padding(width, ' ');
	return (len + prec + width);
}
