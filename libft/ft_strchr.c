/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:02:32 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/24 21:00:22 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strchr(const char *s, int c)
{	
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		s++;
	}
	return (0);
}
// int	ft_strchr(char *str, int c)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == (char)c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
