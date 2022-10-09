/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:40:28 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/09 12:07:59 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_cd(char *cmd)
{
	char	**tab;

	tab = ft_split(cmd, ' ');
	return (tab[0]);
}

char	*ft_get_home()
{
	char	*home;

	home = getenv("HOME");
	return (home);
}

/*
	char	*ft_get_path(char *cmd)
	{
		int			i;
		int			j;
		char		*path;
		char		**tab;

		path = NULL;
		i = 0;
		j = 0;
		path = (char *)malloc(sizeof(char) * ft_strlen(cmd));
		if (!path)
			return (NULL);
		tab = ft_split(cmd, ' ');
		if (ft_strcmp(tab[0], "cd") == 0)
			ft_strcpy(path, tab[1]);
		return (path);
	}
*/

void	ft_cd(char *cmd)
{
	if (!cmd)
		return ;
	if (chdir(cmd) == 0)
		return ;
	ft_puterror(cmd, ": No such file or directory\n");
}

// int main()
// {
//     t_env *t = NULL;
//     printf("[%s]\n", getenv("HOME"));
//     return (0);
// }
