/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_aux_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:59:54 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:45:31 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*lst_expand(char *ret, char *cmd, int *i)
{
	ret = ft_strjoin(ret, ft_substr(cmd, *i, 1));
	if (cmd[*i] == '$' && cmd[*i + 1] == '$')
		ret = ft_strjoin(ret, ft_substr(cmd, (*i)++, 1));
	return (ret);
}

int	inverse_expand(char *cmd, int i, int expand)
{
	if (cmd[i] == '\"')
		g_var.expand = !g_var.expand;
	if (g_var.expand == 0)
	{
		if (cmd[i] == '\'')
			return (!expand);
	}
	return (expand);
}

int	ft_valid_var(char *c)
{
	if (isalpha(c[0]) || c[0] == '_')
		return (1);
	ft_puterror(c, ": not a valid identifier\n");
	return (0);
}
