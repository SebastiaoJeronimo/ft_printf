/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:11:09 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/06 17:30:36 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*char_dst;
	char		*char_src;

	char_src = (char *) src;
	char_dst = (char *) dest;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
	char_dst[i] = char_src[i];
	i++;
	}
	return (dest);
}
