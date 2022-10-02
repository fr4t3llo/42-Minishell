/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:43:24 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/26 21:03:15 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int		i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)str1;
	s2 = (char *)str2;
	if (s1 < s2)
		return (ft_memcpy(s1, s2, n));
	if (s1 > s2)
	{
		while (i < (int)n)
		{
			s1[n - 1] = s2[n - 1];
			n--;
		}
	}
	return (s1);
}
