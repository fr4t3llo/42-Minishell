/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:56:16 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 04:01:30 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset_more_then_one(char **ptr)
{
	int	i;

	i = 1;
	while (ptr[i])
	{
		if (!ft_valid_var(ptr[i]))
		{
			i++;
			continue ;
		}
		ft_unset(ptr[i]);
		i++;
	}
}

void	ft_aux_unset(t_env *tmp, t_env *tmp_next, t_env *tmp_prev)
{
	if (tmp && tmp->next && tmp->prev)
	{
		tmp_next = tmp->next;
		tmp_prev = tmp->prev;
		tmp_prev->next = tmp_next;
		tmp_next->prev = tmp_prev;
	}
}

void	ft_aux_unset_2(t_env *tmp)
{
	tmp = g_var.env;
	g_var.env = g_var.env->next;
	g_var.env->prev = NULL;
}

void	handle_pwd_2(char *var)
{
	if (ft_strcmp(var, "PWD"))
		g_var.pwd = 0;
	if (ft_strcmp(var, "OLDPWD"))
		g_var.oldpwd = 0;
}

void	ft_unset(char *cmd)
{
	t_env	*tmp_next;
	t_env	*tmp_prev;
	t_env	*tmp;

	tmp_next = NULL;
	tmp_prev = NULL;
	tmp = g_var.env;
	handle_pwd_2(cmd);
	while (tmp)
	{
		if (ft_strcmp(cmd, tmp->data) == 0)
		{
			if (tmp && tmp->next == NULL && tmp->prev == NULL)
				g_var.env = NULL;
			else if (tmp && tmp->next && tmp->prev == NULL)
				ft_aux_unset_2(tmp);
			else if (tmp && tmp->next == NULL && tmp->prev)
				tmp->prev->next = NULL;
			else
				ft_aux_unset(tmp, tmp->next, tmp->prev);
			break ;
		}
		tmp = tmp->next;
	}
}
