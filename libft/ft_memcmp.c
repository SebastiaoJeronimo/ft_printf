/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:13:13 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/06 00:25:00 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*chr_s1;
	char		*chr_s2;

	i = 0;
	chr_s2 = (char *) s2;
	chr_s1 = (char *) s1;
	while (i < n)
	{
		if ((unsigned char) chr_s1[i] == (unsigned char) chr_s2[i])
			i++;
		else
			return ((unsigned char) chr_s1[i] - (unsigned char) chr_s2[i]);
	}
	return (0);
}
