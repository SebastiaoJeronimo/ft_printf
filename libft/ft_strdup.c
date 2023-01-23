/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:04:55 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 22:33:51 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

//aloca memoria para guardar uma copia da cadeia de caracteres src 
char	*ft_strdup(const char *src)
{
	char	*ptr;

	ptr = malloc(ft_strlen(src) + 1);
	if (!ptr)
		return (0);
	ft_strcpy(ptr, src);
	return (ptr);
}
