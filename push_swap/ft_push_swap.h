/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:11:43 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/21 23:50:23 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_printf.h"
# include <stddef.h>
# include <stdlib.h>
//#include "libft.h"

int		ft_push_swap_source_validator(char **argc, int argn);
int		ft_comprob_dupl(char **argc, int count);
int		ft_comprob_dupli_loop(char **argc, int count, int i, int j);
int		ft_comprob_num(char **argc, int argn);
int		ft_comprob_int(char **argc, int argn);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_swap_a_SA(int *ptr);
int		*ft_push_A(int *ptrA, int *ptrB, int count_a, int count_b);
void	ft_rotate_a_ra(int *ptr, int count_a);
void	ft_reverse_rotate_a_rra(int *ptr, int count_a);

#endif