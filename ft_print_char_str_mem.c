/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managers_I.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:34:20 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/18 17:17:57 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding(int size, char pad_car)
{
	while (size--)
		write(1, pad_char, 1);
}

int		ft_print_char(char c, t_flags flags)
{
	char	pad_car;

	pad_car = (flags.zero == 1) ? '0' : ' ';
	if (flags.width > 1 && flags.dash == 0)
		ft_padding(flags.width - 1, pad_car);
	write(1, &c, 1);
	if (flags.width > 1 && flags.dash == 1)
		ft_padding(flags.width - 1, ' ');
	return ((flags.width > 1) flags.width : 1);
}

int		ft_print_str(char *s, struct t_flags flags)
{
	char	pad_car;
	int		len;

	len = ft_strlen(s);
	if (s == NULL)
		s = "(null)";
	pad_car = (flags.zero == 1) ? '0' : ' ';
	if (flags.dot == 1 && flags.precision < len)
		len = flags.precision;
	if (flags.width > len && flags.dash == 0)
		ft_padding(flags.width - len, pad_car);
	write(1, &s, len);
	if (flags.width > len && flags.dash == 1)
		ft_padding(flags.width - len, ' ');
	return ((flags.width > len) flags.width : len);
}

int		ft_print_mem(unsigned long n, struct s_flgs flags)
{
	int	i;

	i = 0;
	if (flags.dot == 1 && flags.precision == 0 && n == 0)
	{
		while (flags.minus == 0 && i++ < flags.width - 2)
			write(1, " ", 1);
		write(1, "0x", 2);
		while (flags.minus == 1 && i++ < flags.width - 2)
			write(1, " ", 1);
		return (i + 1);
	}
	if (flags.width > 0 && flags.dot == 1)
		return (ft_putmem_prewid(n, flags));
	if (flags.width > 0 && flags.zero == 0)
		return (ft_putmem_wid(n, flags));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_putmem_pre(n, flags));
	else
		return (ft_putmem(n, 1));
}
