/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:46:47 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 01:13:07 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_execute_bulletin(char *cmd)
{
	char	**cmd2;

	cmd2 = ft_split(cmd, ' ');
	return (cmd2[0]);
}

int	ft_check_change_dir(char *cmd)
{
	char	str[1024];

	if (ft_strncmp(cmd, ".", 255) && !getcwd(str, 1024))
		ft_putstr_fd("cd: error retrieving current directory: \
	getcwd: cannot access parent directories", 2);
	return (chdir(cmd));
}
