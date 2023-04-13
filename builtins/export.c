/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:55:51 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:46:27 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_from_env(char *var)
{
	t_env	*tmp;

	tmp = g_var.env;
	while (tmp)
	{
		if (!ft_strcmp(var, tmp->data))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	handle_pwd(char *var)
{
	if (ft_strcmp(var, "PWD"))
		g_var.pwd = 1;
	if (ft_strcmp(var, "OLDPWD"))
		g_var.oldpwd = 1;
}

void	ft_aux_export(char *var, char *val)
{
	t_env	*new;
	t_env	*tmp;

	handle_pwd(var);
	tmp = g_var.env;
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return ;
	add_garbage(new);
	new->data = var;
	new->value = val;
	new->next = NULL;
	if (!g_var.env)
	{
		new->prev = NULL;
		g_var.env = new;
	}
	else
	{
		tmp = g_var.env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	ft_aux_final(t_variable *t, char *cmd)
{
	t->var = cmd;
	t->val = NULL;
}

void	ft_export(char **cmd)
{
	t_variable	t;

	t.i = 0;
	while (cmd[++t.i])
	{
		t.to_exp = cmd[t.i];
		if (ft_strstr(t.to_exp, "="))
		{
			t.val = ft_strstr(t.to_exp, "=") + 1;
			t.len = ft_strlen(t.to_exp) - ft_strlen(t.val) - 1;
			t.var = ft_substr(t.to_exp, 0, t.len);
			if (t.var[ft_strlen(t.var) - 1] == '+')
			{
				t.var = ft_substr(t.var, 0, ft_strlen(t.var) - 1);
				if (get_from_env(t.var))
					t.val = ft_strjoin(get_from_env(t.var), t.val);
			}
		}
		else
			ft_aux_final(&t, cmd[t.i]);
		if (!ft_valid_var(t.var))
			continue ;
		ft_unset(t.var);
		ft_aux_export(t.var, t.val);
	}
}
