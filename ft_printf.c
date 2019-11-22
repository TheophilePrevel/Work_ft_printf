/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:52:40 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/22 19:07:49 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ivaie(const char *s, int *i, va_list ap)
{
	t_flags	flags;
	int		out;

	(*i)++;
	out = 0;
	ft_parse_flags(s, i, &flags, ap);
	if (s[*i] == 'c')
		out = ft_print_char(va_arg(ap, int), flags);
	else if (s[*i] == 's')
		out = ft_print_str(va_arg(ap, char *), flags);
	else if (s[*i] == 'p')
		out = ft_print_pt(va_arg(ap, unsigned long), flags);
	else if (s[*i] == 'd' || s[*i] == 'i')
		out = ft_print_int((long int)va_arg(ap, int), flags);
	else if (s[*i] == 'u')
		out = ft_print_int((long int)va_arg(ap, unsigned int), flags);
	else if (s[*i] == 'x')
		out = ft_print_hex(va_arg(ap, unsigned int), flags, 'a');
	else if (s[*i] == 'X')
		out = ft_print_hex(va_arg(ap, unsigned int), flags, 'A');
	else if (s[*i] == '%')
		out = ft_print_char('%', flags);
	if (s[*i] != '\0')
		(*i)++;
	return (out);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		out;

	va_start(ap, str);
	i = 0;
	out = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			out += ft_ivaie(str, &i, ap);
		else
		{
			write(1, &str[i++], 1);
			out++;
		}
	}
	va_end(ap);
	return (out);
}
