/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:52:41 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 20:31:10 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_tmp;

	lst_tmp = lst;
	if (lst_tmp == NULL)
		return (0);
	while (lst_tmp->next != NULL)
		lst_tmp = lst_tmp->next;
	return (lst_tmp);
}
