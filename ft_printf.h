/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:28:42 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/18 17:32:49 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "/libft/libft.h"

struct	s_flags
{
	int zero;
	int dash;
	int dot;
	int precision;
	int width;
}		t_flags;

int		ft_memlen(unsigned long n);
int		ft_putmem_prewid(unsigned long n, t_flags flags);
int		ft_putmem_wid(unsigned long n, t_flags flags);
int		ft_putmem_pre(unsigned long n, t_flags flags);
int		ft_putmem(unsigned long n, int start);

int		ft_nbrlen(long n);
int		ft_putnbr_prewid(long n, t_flags flags);
int		ft_putnbr_pre(long n, t_flags flags);
int		ft_putnbr_wid(long n, t_flags flags);
int		ft_putnbr(long n);

int		ft_hexlen(unsigned int n);
int		ft_puthex_prewid(unsigned int n, t_flags flags, int cap);
int		ft_puthex_pre(unsigned int n, t_flags flags, int cap);
int		ft_puthex_wid(unsigned int n, t_flags flags, int cap);
int		ft_puthex(unsigned int n, int cap);

void	ft_padding(int size, char pad_car);
int		ft_print_char(char c, t_flags flags);
int		ft_print_str(char *s, t_flags flags);
int		ft_print_mem(unsigned long n, t_flags flags);
int		ft_print_nbr(long n, t_flags flags);
int		ft_print_hex(unsigned int n, t_flags flags, char c);
int		ft_print_other(char c, t_flags flags);

int		ft_atoi_star(const char *s, int *i, va_list ap);
void	ft_parse_flags(const char *s, int *i, t_flags *flags, va_list ap);

int		ft_ifs_forest(const char *s, int *i, va_list ap);
int		ft_printf(const char *string, ...);
#endif
