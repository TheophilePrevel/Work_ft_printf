/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:28:42 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/22 19:39:51 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_flags
{
	int				zero;
	int				dash;
	int				dot;
	int				precision;
	int				width;
}					t_flags;

char				*ft_strchr(const char *s, int c);
void				ft_putchar_fd(char c, int fd);
int					ft_strlen(char *s);

void				ft_padding(int size, char pad_car);
int					ft_print_char(char c, t_flags flags);
int					ft_print_str(char *s, t_flags flags);

int					ft_nbrlen(long n);
int					ft_set_width(t_flags flags, int len);
int					ft_set_prec(t_flags flags, int len);
void				ft_putint(long n);
int					ft_print_int(long n, t_flags flags);

int					ft_hexlen(unsigned int n);
void				ft_puthex(long int n, char kaze);
int					ft_print_hex(unsigned int n, t_flags flags, char kaze);

int					ft_ptlen(unsigned long n);
int					ft_print_pt(unsigned long n, t_flags flags);

int					ft_atoi_star(const char *s, int *i, va_list ap);
void				ft_parse_flags(const char *s, int *i, t_flags *flags,
					va_list ap);

int					ft_ivaie(const char *s, int *i, va_list ap);
int					ft_printf(const char *string, ...);

#endif
