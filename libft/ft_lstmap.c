/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:52:46 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/06 19:25:51 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*lst_final;
	t_list	*possible_final_lst_node;

	if (lst == NULL)
		return (NULL);
	lst_final = 0;
	while (lst)
	{
		possible_final_lst_node = ft_lstnew(f(lst->content));
		if (!possible_final_lst_node)
		{
			ft_lstclear(&possible_final_lst_node, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_final, possible_final_lst_node);
		lst = lst-> next;
	}
	return (lst_final);
}

// aqui criar uma nova lista
// while (lst->next != NULL)
// criar um novo node
// aplicar newn->content = f(lst->content)
// lst = lst->next (fazer o loop)
//
