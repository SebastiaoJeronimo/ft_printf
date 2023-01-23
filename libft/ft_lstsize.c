/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:52:53 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 20:30:14 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp_lst;

	i = 0;
	temp_lst = lst;
	while (temp_lst != NULL)
	{
		temp_lst = temp_lst->next;
		i++;
	}
	return (i);
}
