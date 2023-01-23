/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:52:37 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 20:31:19 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*l_temp;

	l_temp = lst;
	if (!lst)
		return ;
	while (l_temp)
	{
		f(l_temp->content);
		l_temp = l_temp->next;
	}
}
