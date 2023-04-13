/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:55:31 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 04:08:48 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(char **cmd)
{
	if (!cmd[1])
	{
		printf("exit\n");
		exit(0);
	}
	else if (cmd[1] && is_num(cmd[1]) && !cmd[2])
	{
		printf("exit\n");
		exit(ft_atoi(cmd[1]));
	}
	else if (cmd[2] && is_num(cmd[1]))
	{
		ft_putstr_fd("exit\nFRATELLO😈: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": too many arguments\n", 2);
	}
	else if (is_num(cmd[1]) == 0 || cmd[2] || (is_num(cmd[2]) == 0 && cmd[2]))
	{
		ft_putstr_fd("exit\nFRATELLO😈: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	return (1);
}
