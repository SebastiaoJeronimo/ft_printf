/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:05:51 by scosta-j          #+#    #+#             */
/*   Updated: 2023/01/27 22:59:38 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *a, ...);
void	percent_operations(char c, va_list args, int *p);
void	print_arg(va_list args, char type, int	*p);
int		print_string(va_list args);
int		print_signed_int(va_list args);
int		print_unsigned(va_list args);
int		print_hexadecimal(va_list args, char type);
int		turning_to_base(unsigned long int a, char *base, int base_len);
int		print_pointer(va_list args);
int		compute_size_rec(unsigned long long int n, int base);

#endif