/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:46:34 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 03:49:18 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_n(char *cmd)
{
	int	i;

	if (!cmd)
		return (1);
	i = 0;
	if (cmd[i] == '-')
	{
		i++;
		while (cmd[i])
		{
			if (cmd[i] != 'n')
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

void	ft_echo(char **cmd)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	if (!cmd[1] || cmd[1][0] == '\0')
		return (ft_putstr_fd("\n", 1));
	while (cmd[i] && !check_n(cmd[i]))
	{
		if (cmd[i][1] != 'n')
			break ;
		check = 1;
		i++;
	}
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		if (cmd[i + 1] && cmd[i][0])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!check)
		ft_putstr_fd("\n", 1);
	g_var.status = 0;
}
