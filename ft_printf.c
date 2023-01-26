/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:23:39 by scosta-j          #+#    #+#             */
/*   Updated: 2023/01/26 23:23:39 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * dar cast a string para (char *) para podermos alterar
 * usar strchr para verificar se o tipo pertence ou nao aos covered
 *
 * // ver se va_list e um array de apontadores para os argumentos
 * // e se va_arg e um apontador para um argumento
 * 
 * va_args notes
 *
 * 1 start by initializing a va_list variable
 * va_list args (arguments of ...)
 * va_list is the type provided by stdarg.h
 *
 * 2 create va_start
 * va_start(args, ?)
 * ? -> in here you put the argument right before the ...
 *
 * 3 to return a value from the parameters you just call va_args
 * va_args(args, type you want to return)
 * (args is the variable name of va_list)
 *
 * examples:
 * 	va_list args
 *
 *	int x = va_arg(args, int);
 * 	char c = va_arg(args , char)
 *
 * 4 to close the list of variable arguments you use va_end(args)
 * args is the va_list created
 *
 * //what does printf return??
 * returns the lenght of the string printed (p)
 */
int	ft_printf(const char *a, ...)
{
	va_list	args;
	char	*string;
	int		p;

	va_start(args, a);
	string = (char *)a;
	p = 0;
	while (*string)
	{
		if (*string != '%')
			p += write(1, string, 1);
		else
		{
			string++;
			percent_operations(*string, args, &p);
		}
		string++;
	}
	va_end(args);
	return (p);
}

/**
 * TODO check if after % its over
 *
 * checks if its one of the cases covered in ft_printf
 * if it is then prints the arg value
 * if its not then prints the percent then the caracter
*/
void	percent_operations(char c, va_list args, int *p)
{
	if (ft_strchr("cs pdiuxX%", c))
		print_arg(args, c, p);
	else
	{
		*p += write(1, "%", 1);
		*p += write(1, &c, 1);
	}
}

/**
 * prints a argument with a certain type
 * the type is defined by the char type
 * example if type d than prints int
*/
void	print_arg(va_list args, char type, int	*p)
{
	if (type == 'c') //ver se isto ta bem
	{
		char c = (char ) va_arg(args, int);
		*p += write(1, &c, 1);
	}
	if (type == 's')
		*p += print_string(args);
	if (type == 'd' || type == 'i')
		*p += print_signed_int(args);
	if (type == 'u')
		*p += print_unsigned(args);
	if (type == 'x' || type == 'X')
		*p += print_hexadecimal(args, type);
	if (type == 'p')
		*p += print_pointer(args);
	if (type == '%')
		*p += write(1, "%", 1);
}

int	print_string(va_list args)
{
	char	*string;

	string = va_arg(args, char *);
	return (write(1, string, strlen(string)));
}

int	print_signed_int(va_list args)
{
	char	*num_str;
	int		number;
	int		len_aux;

	number = va_arg(args, int);
	num_str = ft_itoa(number);
	len_aux = write(1, num_str, ft_strlen(num_str));
	free(num_str);
	return (len_aux);
}

/**
 * Acabar unisigned
 * recursiva provavelmente
*/
int	print_unsigned(va_list args)
{
	unsigned int	num;
	unsigned int	aux;
	int				size;
	char			*string;

	num = va_arg(args, unsigned int);
	aux = num;
	size = compute_size_u(num);
	string = (char *) malloc(size +1);
	string[size] = '\0';
	while (size > 0)
	{
		string[size - 1] = num % 10 + '0';
		num = num / 10;
		size--;
	}
	size = write(1, string, compute_size_u(aux));
	free(string);
	return (size);
}

int	compute_size_u(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

/**
 * recebe um unsigned atraves de va_list args
 * acabar hexadecimal
 * ver como e que numeros hexadecimais sao imprimidos
*/
int	print_hexadecimal(va_list args, char type)
{
	char				*base;
	int					num;
	int					signal;

	signal = 0;
	num = va_arg(args, int);
	if (num < 0)
		signal = 1;
	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (signal)
	{
		write (1, "-", 1);
		num = num * -1;
	}
	return (turning_hexa((unsigned long long int) num, base) + signal);
}

int	compute_size_hex(unsigned long long int n)
{
	int	size;

	size = 0;
	while (n > 15)
	{
	size++;
	n = n / 16;
	}
	return (size + 1);
}

/*
 * turns into hexadecimal and prints
 */
int turning_hexa(unsigned long long int a, char *base)
{
	int						size;
	unsigned long long int	aux;
	char					*hexa_s;

	size = compute_size_hex(a);
	aux = a;
	hexa_s = (char *) malloc(size + 1);
	hexa_s[size] = '\0';
	while (size > 0)
	{
		hexa_s[size - 1] = base[a % 16];
		a = a / 16;
		size--;
	}
	size = write(1, hexa_s, compute_size_hex(aux));
	free(hexa_s);
	return (size);
}

/**
 * acabar pointer 
 * ver como e que pointers sao imprimidos
*/
int	print_pointer(va_list args)
{
	unsigned long long		hex;

	hex = va_arg(args, unsigned long long int);
	write (1, "0x", 2);
	return (2 + turning_hexa(hex, "0123456789abcdef"));
}
