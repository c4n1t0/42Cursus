/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:13:10 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/03 17:19:06 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *ptr, ...);
int		ft_putnbr(int n, int i);
int		ft_putstr(char *s, int j);
int		ft_putchar(char c, int i);
int		ft_unsigned_putnbr(unsigned int n, int i);
int		ft_calc_hex_void(unsigned long long num, int i);
void	ft_hex_minus(unsigned int num);
int		ft_calc_hex(unsigned int num, int i, char *p);
void	ft_hex_mayus(unsigned int num);
int		ft_num_neg(int n);
int		ft_conditions(char *p, int i, va_list args);

#endif