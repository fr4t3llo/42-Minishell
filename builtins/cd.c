/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:40:28 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/12 16:51:57 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char	*ft_get_cd(char *cmd)
// {
// 	char	**tab;

// 	tab = ft_split(cmd, ' ');
// 	return (tab[0]);
// }

int	ft_get_cd_without_arg(char *cmd)
{
	char	**tab;

	tab = ft_split(cmd, ' ');
	if (!tab[1])
		return (1);
	else
		return (0);
}

char	*ft_get_home(void)
{
	char	*home;

	home = getenv("HOME");
	return (home);
}

void	ft_cd(char *cmd)
{
	char	*home;

	home = ft_get_home();
	if (!cmd)
		return ;
	// if (ft_get_cd_without_arg(cmd) == 1)
	// {
	// 	if (chdir(home) == 0)
	// 		return ;
	// }
	// else if (ft_get_cd_without_arg(cmd) == 0)
	// {
	// 	if (chdir(cmd) == 0)
	// 		return ;
	// }
	if (chdir(cmd) == 0)
		return ;
	ft_puterror(cmd, ": No such file or directory\n");
}
