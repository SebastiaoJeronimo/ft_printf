/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:54:08 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 17:16:28 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_of_src;
	size_t	size_of_dst;
	size_t	i;

	i = 0;
	size_of_dst = ft_strlen(dst);
	size_of_src = ft_strlen(src);
	if (size_of_dst > dstsize || dstsize == 0)
		return (size_of_src + dstsize);
	while ((size_of_dst + i) < (dstsize -1) && src[i])
	{
		dst [size_of_dst + i] = src[i];
		i++;
	}
	dst [size_of_dst + i] = '\0';
	return (size_of_dst + size_of_src);
}
