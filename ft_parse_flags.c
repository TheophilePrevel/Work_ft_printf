/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:20:03 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/18 12:56:09 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_end_flag(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		is_valid_flag(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%' || c == ' ')
		return (1);
	if (c == '-' || c == '.' || c == '*')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi_star(const char *s, int *i, va_list args)
{
	int	num;

	num = 0;
	if (s[*i] == '.')
		(*i)++;
	if (s[*i] == '*')
	{
		num = va_arg(args, unsigned int);
		return (num);
	}
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		num = num * 10 + (s[*i] - '0');
		(*i)++;
	}
	(*i)--;
	return (num);
}

void	ft_neg_star(struct s_flgs *flags)
{
	if (flags->precision < 0)
	{
		flags->dot = 0;
		flags->precision = 0;
	}
	else if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
	}
	return ;
}

void	ft_parse_flags(const char *s, int *i, struct s_flgs *flags, va_list ap)
{
	flags->zero = 0;
	flags->dash = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->width = 0;
	while (ft_strchr("-.* 0123456789", s[*i]))
	{
		if (s[*i] == '0')
			flags->zero = 1;
		else if (s[*i] == '-')
			flags->dash = 1;
		else if (s[*i] == '.')
		{
			flags->dot = 1;
			flags->precision = ft_atoi_star(s, i, ap);
		}
		else if (s[*i] == '*' || (s[*i] >= '1' && s[*i] <= '9'))
			flags->width = ft_atoi_star(s, i, ap);
		if (flags->precision < 0 || flags->width < 0)
			ft_neg_star(flags);
		(*i)++;
	}
}
