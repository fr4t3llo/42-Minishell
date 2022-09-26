/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:17:45 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/26 22:09:51 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip_and_copy(char *line, int *k)
{
	int		i;
	char	c;

	i = *k;
	if (line[i] == '\"' || line[i] == '\'')
	{
		c = line[i];
		i++;
		while (line[i] != c && line[i] != '\0')
			i++;
	}
	*k = i;
}


void	ft_pipe(char *cmd)
{
	int		i;
	char	*pipe;
	char	c;
	t_pipe	*t;

	i = 0;
	if (!cmd)
		return ;
	pipe = ft_strdup("");
	t = NULL;
	while (cmd[i])
	{
		if (cmd[i] != '|')
		{
			if (cmd[i] == '\"' || cmd[i] == '\'')
			{
				pipe = ft_strjoin(pipe, ft_substr(cmd, i, 1));
				c = cmd[i++];
				while (cmd[i] && cmd[i] != c)
				{
					pipe = ft_strjoin(pipe, ft_substr(cmd, i, 1));
					i++;
				}
				pipe = ft_strjoin(pipe, ft_substr(cmd, i, 1));
			}
			else
				pipe = ft_strjoin(pipe, ft_substr(cmd, i, 1));
		}
		else if (cmd[i] == '|')
		{
			ft_lstadd_back(&t, pipe);
			pipe = ft_strdup("");
		}
		i++;
	}
	ft_lstadd_back(&t, pipe);
	ft_start_exe(t);
}
