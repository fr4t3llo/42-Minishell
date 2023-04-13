/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:23:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 04:05:14 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_aux_pwd(char *add)
{
	t_env	*t;

	t = g_var.env;
	while (t)
	{
		if (ft_strcmp("PWD", t->data) == 0)
			t->value = ft_strdup(add);
		t = t->next;
	}
}

void	ft_pwd(char **path)
{
	char	s[1024];
	t_env	*t;
	char	*add_to_env;

	t = g_var.env;
	if (!path || !*path || ft_strncmp(path[0], "pwd", 255))
		return ;
	if (path[1] && path[1][0] == '-' && path[1][1] != '\0' && path[1][1] != '-')
	{
		printf("%s: invalid option %c\n", path[0], path[1][1]);
		printf("pwd: usage [without options] [dir]\n");
		return ;
	}
	add_to_env = getcwd(s, 1024);
	if (!add_to_env)
		add_to_env = get_from_env("PWD");
	if (add_to_env)
	{
		ft_aux_pwd(add_to_env);
		ft_putstr_fd(s, 1);
		ft_putstr_fd("\n", 1);
		g_var.status = 0;
	}
	else
		perror("pwd:");
}
