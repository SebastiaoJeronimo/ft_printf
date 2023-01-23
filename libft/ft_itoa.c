/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:25:35 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/06 21:20:06 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compute_size(int n)
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

void	transform(char *ptr, int size, int signal, int number)
{
	while (size > 0)
	{
		ptr[signal + size - 1] = (number % 10) + '0';
		number = number / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		signal;
	int		size_aux;
	int		a;

	signal = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		signal = 1;
		n = n * -1;
	}
	a = n;
	size_aux = compute_size(n);
	ptr = (char *) malloc((compute_size(n) + signal + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if (signal == 1)
		ptr[0] = '-';
	transform(ptr, size_aux, signal, a);
	ptr[signal + compute_size(n)] = '\0';
	return (ptr);
}
