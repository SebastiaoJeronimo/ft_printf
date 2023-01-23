/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:30:29 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/06 17:40:03 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned int		size_str;
	unsigned int		i;

	i = 0;
	size_str = ft_strlen(s);
	str = (char *) malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	str[ft_strlen(s)] = '\0';
	while (i < size_str)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
