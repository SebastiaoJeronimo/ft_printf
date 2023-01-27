/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:23:39 by scosta-j          #+#    #+#             */
/*   Updated: 2023/01/27 22:44:01 by scosta-j         ###   ########.fr       */
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
			if (ft_strchr("cspdiuxX%", *string))
				print_arg(args, *string, &p);
			else
				p += (write(1, "%", 1) + write(1, string, 1));
		}
		string++;
	}
	va_end(args);
	return (p);
}

/**
 * prints a argument with a certain type
 * the type is defined by the char type
 * example if type d than prints int
*/
void	print_arg(va_list args, char type, int	*p)
{
	char			c;
	unsigned int	u;

	if (type == 'c')
	{
		c = (char ) va_arg(args, int);
		*p += write(1, &c, 1);
	}
	if (type == 's')
		*p += print_string(args);
	if (type == 'd' || type == 'i')
		*p += print_signed_int(args);
	if (type == 'u')
	{
		u = va_arg(args, unsigned int);
		*p += turning_to_base(u, "0123456789", 10);
	}
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
	if (!string)
		return (write(1, "(null)", 6));
	return (write(1, string, strlen(string)));
}

int	print_signed_int(va_list args)
{
	long		number;
	int			signal;

	signal = 0;
	number = va_arg(args, int);
	if (number < 0)
	{
		signal = write (1, "-", 1);
		number = number * -1;
	}
	return (turning_to_base(number, "0123456789", 10) + signal);
}

/**
 * recebe um unsigned atraves de va_list args
 * acabar hexadecimal
 * ver como e que numeros hexadecimais sao imprimidos
*/
int	print_hexadecimal(va_list args, char type)
{
	char				*base;
	unsigned int		num;

	num = va_arg(args, unsigned int);
	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (turning_to_base(num, base, 16));
}




