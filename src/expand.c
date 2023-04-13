/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 04:45:00 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:45:25 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_name(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strdup("");
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
	{
		ret = ft_strjoin(ret, ft_substr(str, i, 1));
		i++;
	}
	return (ret);
}

char	*get_name_expand(char *cmd, char *ret, int *i)
{
	char	*val;
	char	*name;

	name = get_name(&cmd[*i + 1]);
	val = get_from_env(name);
	if (val)
		ret = ft_strjoin(ret, val);
	else
		ret = ft_strjoin(ret, "");
	*i += ft_strlen(name) + 1;
	return (ret);
}

char	*init_expand(int *i, int *expand)
{
	*i = 0;
	*expand = 1;
	g_var.expand = 0;
	return (ft_strdup(""));
}

char	*get_ret(char *ret, int *i)
{
	ret = ft_strjoin(ret, ft_itoa(g_var.status));
	*i += 2;
	return (ret);
}

char	*ft_expand(char *cmd)
{
	int		i;
	char	*ret;
	int		expand;

	ret = init_expand(&i, &expand);
	while (cmd[i])
	{
		expand = inverse_expand(cmd, i, expand);
		if (expand == 1 && cmd[i] == '$')
		{
			if (cmd[i + 1] == '?')
			{
				ret = get_ret(ret, &i);
				continue ;
			}
			if (ft_isalpha(cmd[i + 1]) || cmd[i + 1] == '_')
			{
				ret = get_name_expand(cmd, ret, &i);
				continue ;
			}
		}
		ret = lst_expand(ret, cmd, &i);
		i++;
	}
	return (ret);
}
