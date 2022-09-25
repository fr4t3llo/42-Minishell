/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:17:45 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/25 23:32:02 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_pipe(char *cmd)
{
	int		i;
	int		j;
	int		k;
	char	**pipe;
	int		len;

	len = 0;
	i = 0;
	j = 0;
	k = 0;
	if (!cmd)
		return (NULL);
	pipe = (char **)malloc(sizeof(char *) * 100);
	if (!pipe)
		return (NULL);
	while (len < 100)
	{
		pipe[len] = (char *)malloc(sizeof(char) * 100);
		if (!pipe[len])
			return (NULL);
		len++;
	}
	while (cmd[i])
	{
		if (cmd[i] != '|')
		{
			pipe[j][k] = cmd[i];
			k++;
		}
		else if (cmd[i] == '|')
		{
			pipe[j][k] = '\0';
			j++;
			k = 0;	
		}
		i++;
	}
	return (pipe);
}
