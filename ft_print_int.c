/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:00:21 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/20 17:36:44 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(int n)
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

int		ft_set_width(t_flag flag, int len)
{
	int out;

	if (flag->zero == 1 && flag->dot == 0 && flag->dash == 0)
		return (0);
	else
		out = (flag->width > len) ? flag->width - len : 0;
	return (out);
}

int		ft_set_prec(t_flag flag, int len)
{
	int out;

	if (flag->zero == 1 && flag->dot == 0 && flag->dash == 0)
		out = (flag->width > len) ? flag->width - len : 0;
	else
		out = (flag->precision > len) ? flag->precision - len : 0;
	return (out);
}

void	ft_putint(int n)
{
	if (n > 0)
		n = -n;
	if (n < -9)
		ft_putint(n / 10);
	ft_putchar('0' - n % 10);
}

int		ft_print_int(int n, t_flag flag)
{
	int len;
	int prec;
	int width;

	if (flag->dot == 1 && flag->precision == 0 && n == 0)
		return (0);
	len = ft_nbrlen(n);
	width = ft_set_width(flag, len);
	prec = ft_set_prec(flag, len);
	if(width != 0 && flag->dash == 0)
		ft_padding(width, ' ');
	if (n < 0)
		write(1, '-', 1);
	if (prec && (flag->dot == 1 || flag->zero == 1))
		ft_padding(prec, '0');
	ft_putint(n);
	if(width != 0 && flag->dash == 1)
		ft_padding(width, ' ');
		return (len + prec + width);
}
