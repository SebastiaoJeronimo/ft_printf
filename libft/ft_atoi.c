/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:52:56 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/05 20:36:51 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//first check the spaces
//check if the number is negative
//calcular o resultado com a formula res = res*10 + char - '0'
int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	signal;

	signal = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -signal;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signal);
}
