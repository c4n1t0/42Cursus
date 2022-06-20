/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:11:43 by jaromero          #+#    #+#             */
/*   Updated: 2022/06/20 21:18:05 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP.H
# define FT_PUSH_SWAP .H

# include "ft_printf.h"
# include "libft.h"

int		ft_comprob_int(char **argc, int argn);
int		ft_comprob_num(char **argc, int argn);
int		ft_comprob_dupli_loop(char **argc, int count, int i, int j);
int		ft_comprob_dupl(char **argc, int count);
int		ft_push_swap_source_validator(char **argc, int argn);
int		*ft_resrv_stack(int argn, char **argc);
void	ft_print_stack(int *ptr, int count);

#endif