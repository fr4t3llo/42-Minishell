/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:58:28 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/26 21:04:57 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		ptr = malloc(1);
		ptr[0] = 0;
		return (ptr);
	}
	if (len > (ft_strlen(s) - start))
		ptr = (char *)malloc(ft_strlen(s) - start + 1);
	else
		ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (s[start + ++i] && i < len)
		ptr[i] = s[start + i];
	ptr[i] = 0;
	return (ptr);
}


