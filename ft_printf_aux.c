/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:47:47 by scosta-j          #+#    #+#             */
/*   Updated: 2023/01/27 22:59:03 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * acabar pointer 
 * ver como e que pointers sao imprimidos
*/
int	print_pointer(va_list args)
{
	unsigned long long		hex;

	hex = va_arg(args, unsigned long long int);
	if (!hex)
		return (write (1, "(nil)", 5));
	return (write (1, "0x", 2) + turning_to_base(hex, "0123456789abcdef", 16));
}

/*
 * turns into hexadecimal and prints
 */
int	turning_to_base(unsigned long int number, char *base, int base_len)
{
	int						size;
	unsigned long long int	aux;
	char					*hexa_s;

	size = compute_size_rec(number, base_len);
	aux = number;
	hexa_s = (char *) malloc(size + 1);
	hexa_s[size] = '\0';
	while (size > 0)
	{
		hexa_s[size - 1] = base[number % base_len];
		number = number / base_len;
		size--;
	}
	size = write(1, hexa_s, compute_size_rec(aux, base_len));
	free(hexa_s);
	return (size);
}


int	compute_size_rec(unsigned long long int n, int base)
{
	if (n > (unsigned long long int)(base - 1))
		return (compute_size_rec(n / base, base) + 1);
	return (1);
}
