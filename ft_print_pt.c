/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:44:33 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/22 19:24:10 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptlen(unsigned long n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n = n / 16;
		len++;
	}
	return (len + 2);
}

int		ft_print_pt(unsigned long n, t_flags flag)
{
	int len;
	int prec;
	int width;

	if (flag.dot == 1 && flag.precision == 0 && n == 0)
	{
		write(1, "0x", 2);
		return (2);
	}
	len = ft_ptlen(n);
	width = ft_set_width(flag, len);
	prec = ft_set_prec(flag, len);
	if (width != 0 && flag.dash == 0)
		ft_padding(width, ' ');
	if (prec)
		ft_padding(prec, '0');
	if (n)
		write(1, "0x", 2);
	ft_puthex(n, 'a');
	if (width != 0 && flag.dash == 1)
		ft_padding(width, ' ');
	return (len + prec + width);
}
