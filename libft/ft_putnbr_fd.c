/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:28:40 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/06 19:10:22 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_number(int number, int fd)
{
	if (number > 9)
		print_number(number / 10, fd);
	number = (number % 10) + '0';
	write(fd, &number, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!fd && fd > 0)
		return ;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	print_number(n, fd);
}
