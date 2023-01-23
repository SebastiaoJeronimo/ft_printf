/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:52:32 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 19:53:07 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function, too, will copy a maximum of n bytes from src to dest; 
unlike strncpy(), it will always ensure that dest is NUL-terminated. 
The return value is always the length of src regardless of whether 
it was truncated in the copy or not; 
developers must compare the returned length against n 
to determine whether truncation has occurred.*/
//check if both strings are not null
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		size_src;
	size_t	i;

	i = 0;
	size_src = ft_strlen(src);
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst [i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
