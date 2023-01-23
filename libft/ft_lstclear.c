/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:52:29 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 20:31:38 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l_temp;

	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		l_temp = (*lst)->next;
		del ((*lst)->content);
		free(*lst);
		*lst = l_temp;
	}
	*lst = NULL;
}
