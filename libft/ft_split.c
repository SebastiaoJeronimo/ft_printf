/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:21:25 by scosta-j          #+#    #+#             */
/*   Updated: 2022/12/07 17:00:37 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * computes the number of splitted strings 
 * that are going to be created by the split function
*/
static	int	nr_words(char const *s, char c)
{
	int		result;
	int		pos;
	int		state;

	result = 0;
	pos = 0;
	state = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			state = 0;
		else
		{
			if (state == 0)
			{
				result++;
				state = 1;
			}	
		}
		pos++;
	}
	return (result);
}

/**
 * computes the splited substring lenght
*/
static	int	word_length(const char *s, char c)
{
	int		size;

	size = 0;
	while (s[size] != c && s[size] != '\0')
		size++;
	return (size);
}

/**
 * 1 compute the number of words based on the splitting caracters
 * 	1.1 this is to create an array of pointers to each word
 * 	1.2 plus one in calloc to put the \0 
 * 2 run trough the man string and when you find a non separator char
 * 	have an aux index for the copy in this case is pos this aux index 
 * 	corresponds to one of the split strings index in the main string
 * 	have an aux index for the n of the word splitted
 * 	2.1 when you do so compute the lenght of that word 
 * 	  2.1.1 allocate space for it (+1 for \0 and test if it fails)
 * 	2.2 copy the word to the allocated array using the aux index 
 * 	2.3 update both indexs
*/
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		pos;
	int		pos_res;
	int		word_size;

	pos = 0;
	pos_res = 0;
	result = (char **)ft_calloc(nr_words(s, c) + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (s[pos])
	{
		if (s[pos] == c)
			pos++;
		else
		{
			word_size = word_length(&s[pos], c);
			result[pos_res] = (char *)ft_calloc(word_size + 1, sizeof(char));
			ft_strlcpy(result[pos_res], &s[pos], word_size + 1);
			pos_res++;
			pos = pos + word_size;
		}
	}
	return (result);
}
