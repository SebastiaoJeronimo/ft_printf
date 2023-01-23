/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:46:30 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 22:52:15 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		size_str;
	unsigned int		i;

	i = 0;
	size_str = ft_strlen(s);
	while (i < size_str)
	{
		f(i, s + i);
		i++;
	}
}
