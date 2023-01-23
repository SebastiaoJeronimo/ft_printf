/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:54:25 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/06 00:17:28 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	size_of_little;

	i = 0;
	size_of_little = ft_strlen(little);
	if (size_of_little > ft_strlen(big))
		return (0);
	if (little[i] == '\0')
		return ((char *)(big));
	while (i < len)
	{
		if (i + size_of_little > len)
			break ;
		if (ft_strncmp(&big[i], little, size_of_little) == 0)
			return ((char *)(&big[i]));
		i++;
	}
	return (0);
}
