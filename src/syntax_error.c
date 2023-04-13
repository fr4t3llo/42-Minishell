/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:00:12 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 04:12:28 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_red(char *cmd)
{
	int		i;
	int		x;
	char	**tab;

	i = 0;
	tab = ft_split(cmd, ' ');
	if (ft_check_single_dbl_qt(cmd) == 0)
	{
		if (!tab[i])
			return (2);
		while (tab[i])
			i++;
		i--;
		x = ft_strlen(tab[i]) - 1;
		if (!tab[i][x])
			return (1);
		if (ft_strcmp(&tab[i][x], "<") == 0 || ft_strcmp(&tab[i][x], ">") == 0)
			return (1);
	}
	return (0);
}

int	ft_check_single_dbl_qt(char *cmd)
{
	int		i;
	char	quote;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			quote = cmd[i];
			i++;
			while (cmd[i] != quote)
			{
				if (cmd[i] == '\0')
					return (1);
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	ft_check_three_red(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '>' && cmd[i + 1] == '>' && cmd[i + 2] == '>')
			return (1);
		else if (cmd[i] == '<' && cmd[i + 1] == '<' && cmd[i + 2] == '<')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_pipe(char *cmd)
{
	int		i;
	int		k;
	char	**splt;
	int		len;

	splt = ft_split(cmd, ' ');
	i = 0;
	k = 0;
	while (splt[k])
		k++;
	len = ft_strlen(splt[k - 1]);
	if (!splt[0])
		return (2);
	if (ft_check_single_dbl_qt(cmd) == 0)
	{
		if (splt[0][0] == '|' || splt[k - 1][len - 1] == '|')
			return (1);
	}
	return (0);
}
