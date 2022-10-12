/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 04:45:00 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/12 16:50:05 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_expand(char *cmd)
{
	int i;
	char *ptr;

	i = 0;
	ptr = ft_strdup("");
	if (cmd[0] == '~')
	{
		if (cmd[1] == '/' || cmd[1] == ' ' || cmd[1] == '\0')
		{
			ptr = ft_strjoin(ptr, getenv("HOME"));
			if (cmd[1])
				i++;
			i++;
		}
	}
	while (cmd[i])
	{
		if (cmd[i] == '$')
		{
			i++;
			while (cmd[i])
		}
	}
	return (0);
}