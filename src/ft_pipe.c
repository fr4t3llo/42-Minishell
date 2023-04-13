/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:17:45 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:45:34 by matef            ###   ########.fr       */
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

char	*ft_pipe_1(char *pipe, char *cmd, int *i)
{
	char	c;

	pipe = ft_strjoin(pipe, ft_substr(cmd, *i, 1));
	c = cmd[(*i)++];
	while (cmd[*i] && cmd[*i] != c)
	{
		pipe = ft_strjoin(pipe, ft_substr(cmd, *i, 1));
		(*i)++;
	}
	pipe = ft_strjoin(pipe, ft_substr(cmd, *i, 1));
	return (pipe);
}

char	*ft_pipe_2(t_pipe	**t, char *pipe)
{
	ft_lstadd_back(t, pipe);
	return (ft_strdup(""));
}

void	ft_pipe(char *cmd)
{
	int		i;
	char	*pipe;
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
				pipe = ft_pipe_1(pipe, cmd, &i);
			else
				pipe = ft_strjoin(pipe, ft_substr(cmd, i, 1));
		}
		else if (cmd[i] == '|')
			pipe = ft_pipe_2(&t, pipe);
		i++;
	}
	ft_lstadd_back(&t, pipe);
	ft_start_exe(t);
}
