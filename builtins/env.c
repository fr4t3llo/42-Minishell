/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:46:51 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/21 19:35:34 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(void)
{
	t_env	*env;

	env = g_var.env;
	while (env)
	{
		if (env->value)
			printf("%s=%s\n", env->data, env->value);
		env = env->next;
	}
}

void	ft_if_path(void)
{
	char	*s;

	s = getcwd(NULL, 0);
	add_garbage(s);
	ft_change_pwd_and_old("OLDPWD", s);
}
