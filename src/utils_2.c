/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:06:25 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:46:06 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*lexter_to_string(t_lexm *lxm)
{
	char	*ret;

	ret = ft_strdup("");
	while (lxm)
	{
		ret = ft_strjoin(ret, ft_strjoin(lxm->cmd, " "));
		lxm = lxm->next;
	}
	return (ret);
}

char	*ft_lexer_1(int *i, char *cmd, char	*to_expand)
{
	char	qouts;

	qouts = cmd[*i];
	to_expand = ft_strjoin(to_expand, ft_substr(cmd, *i, 1));
	(*i)++;
	while (cmd[*i] && cmd[*i] != qouts)
	{
		to_expand = ft_strjoin(to_expand, ft_substr(cmd, *i, 1));
		(*i)++;
	}
	to_expand = ft_strjoin(to_expand, ft_substr(cmd, *i, 1));
	(*i)++;
	return (to_expand);
}

void	ft_lexer_2(int *i, char *cmd, t_lexm	**lexer)
{
	if (cmd[(*i) + 1] == cmd[*i])
	{
		add_to_lexer(lexer, ft_substr(cmd, *i, 2));
		(*i)++;
	}
	else
		add_to_lexer(lexer, ft_substr(cmd, *i, 1));
}

void	set_to_expand(t_lexm	**lexer, char **to_expand)
{
	if (to_expand[0] != '\0')
	{
		add_to_lexer(lexer, *to_expand);
		*to_expand = ft_strdup("");
	}
}

void	ft_shllvl(void)
{
	t_env	*tmp;

	if (get_from_env("SHLVL"))
	{
		tmp = g_var.env;
		while (tmp)
		{
			if (ft_strcmp(tmp->data, "SHLVL") == 0)
			{
				tmp->value = ft_itoa(ft_atoi(tmp->value) + 1);
				break ;
			}
			tmp = tmp->next;
		}
	}
	else
		ft_aux_export(ft_strdup("SHLVL"), ft_strdup("1"));
}
