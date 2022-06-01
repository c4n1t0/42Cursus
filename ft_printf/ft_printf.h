/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:13:10 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/01 21:01:47 by jaromero         ###   ########.fr       */
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
int		ft_calc_hex_minus(unsigned long long num, int i);
void	ft_hex_minus(unsigned long long num);
int		ft_calc_hex_mayus(unsigned long long num, int i);
void	ft_hex_mayus(unsigned long long num);

#endif