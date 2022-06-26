/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:11:43 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/26 20:32:30 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"

int		ft_push_swap_source_validator(char **argc, int argn);
int		ft_comprob_dupl(char **argc, int count);
int		ft_comprob_dupli_loop(char **argc, int count, int i, int j);
int		ft_comprob_num(char **argc, int argn);
int		ft_comprob_int(char **argc, int argn);
void	ft_swap_a_sa(int *ptr);
void	ft_push_a(int *ptrA, int *ptrB, int count_a);
void	ft_rotate_a_ra(int *ptr, int count_a);
void	ft_reverse_rotate_a_rra(int *ptr, int count_a);
void	ft_swap_b_sb(int *ptr);
void	ft_push_b(int *ptrA, int *ptrB, int count_b);
void	ft_rotate_b_rb(int *ptr, int count_b);
void	ft_reverse_rotate_b_rrb(int *ptr, int count_b);
int		ft_swap_validator(int *ptr, int len);
int		*ft_resrv_stack(int argn, char **argc);
int		ft_push_swap(int *ptrA, int *ptrB, int count_a);

void	ft_print_stack(int *ptr, int count);

#endif