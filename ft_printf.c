/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:52:40 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/13 16:19:42 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		func_branch(const char *s, int *i, va_list a)
{
	struct s_flgs	flags;
	int				out;

	(*i)++;
	ft_parse_flags(s, i, &flags, ap);
	if (s[*i] == 'c')
		out = ft_print_char(va_arg(ap, int), flags);
	else if (s[*i] == 's')
		out = ft_print_str(va_arg(ap, char *), flags);
	else if (s[*i] == 'p')
		out = ft_print_mem(va_arg(ap, unsigned long), flags);
	else if (s[*i] == 'd' || s[*i] == 'i')
		out = ft_print_nbr(va_arg(ap, int), flags);
	else if (s[*i] == 'u')
		out = ft_print_nbr(va_arg(ap, unsigned int), flags);
	else if (s[*i] == 'x' || s[*i] == 'X')
		out = ft_print_hex(va_arg(ap, unsigned int), flags, s[*i]);
	else if (s[*i] == 'o')
		out = ft_print_oct(va_arg(ap, unsigned int), flags);
	else
		out = ft_print_other(s[*i], flags);
	if (s[*i] != '\0')
		(*i)++;
	return (out);
}

int		ft_printf(const char *string, ...)
{
	va_list	ap;
	int		i;
	int		out;

	va_start(ap, string);
	i = 0;
	out = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			out += func_branch(string, &i, ap);
		else
		{
			write(1, &string[i++], 1);
			out++;
		}
	}
	va_end(ap);
	return (out);
}
