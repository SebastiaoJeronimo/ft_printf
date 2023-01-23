/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:13:34 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 20:30:04 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uns_chr_s;
	unsigned char	uns_c;
	size_t			i;

	i = 0;
	uns_c = (unsigned char) c;
	uns_chr_s = (unsigned char *) s;
	while (i < n)
	{
		if (uns_chr_s[i] == uns_c)
			return (&uns_chr_s[i]);
		i++;
	}
	return (0);
}
