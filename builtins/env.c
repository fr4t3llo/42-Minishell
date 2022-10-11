/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:46:51 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/11 18:45:33 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env()
{
	t_env *env;

	env = g_var.env;
	while (env)
	{
		if (env->value)
			printf("%s=%s\n", env->data, env->value);
		env = env->next;
	}
}
