/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str_mem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:34:20 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/22 19:06:05 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding(int size, char pad_char)
{
	while (size--)
		write(1, &pad_char, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	return ((flags.width > 1) ? flags.width : 1);
}

int		ft_print_str(char *s, t_flags flags)
{
	char	pad_car;
	int		len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	pad_car = (flags.zero == 1) ? '0' : ' ';
	if (flags.dot == 1 && flags.precision < len)
		len = flags.precision;
	if (flags.width > len && flags.dash == 0)
		ft_padding(flags.width - len, pad_car);
	write(1, s, len);
	if (flags.width > len && flags.dash == 1)
		ft_padding(flags.width - len, ' ');
	return ((flags.width > len) ? flags.width : len);
}
