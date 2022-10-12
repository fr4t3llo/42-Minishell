/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:28:31 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/12 16:49:12 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_before(char *line, int index)
{
	int	i;

	i = index;
	while (i)
	{
		if (line[i] != ' ')
			return (i);
		i--;
	}
	return (index);
}

int	ft_get_after(char *line, int index)
{
	int	i;

	i = index;
	while (line[i])
	{
		if (line[i] != ' ')
			return (i);
		i++;
	}
	return (index);
}

void	skip_single_dbl_quote(char *line, int *k)
{
	int		i;
	char	c;

	i = *k;
	if (line[i] == '\"' || line[i] == '\'')
	{
		c = line[i];
		i++;
		while (line[i] != c && line[i] != '\0')
			i++;
	}
	*k = i;
}

int	ft_complete(char *cmd, int i)
{
	if (cmd[i] == '|')
	{
		if (ft_strchr("|", cmd[ft_get_after(cmd, i + 1)]) == 1)
			return (1);
		if (ft_strchr("|<>", cmd[ft_get_before(cmd, i - 1)]) == 1)
			return (1);
	}
	return (0);
}

int	ft_check_before_after_symbole(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		skip_single_dbl_quote(cmd, &i);
		if (ft_complete(cmd, i))
			return (1);
		if (cmd[i] == '<' && cmd[i + 1] != '<' && cmd[i - 1] != '<')
		{
			if (ft_strchr("<>|", cmd[ft_get_after(cmd, i + 1)]) == 1)
				return (1);
			if (ft_strchr("<>", cmd[ft_get_before(cmd, i - 1)]) == 1)
				return (1);
		}
		if (cmd[i] == '>' && cmd[i + 1] != '>' && cmd[i - 1] != '>')
		{
			if (ft_strchr("<>|", cmd[ft_get_after(cmd, i + 1)]) == 1)
				return (1);
			if (ft_strchr("<>", cmd[ft_get_before(cmd, i - 1)]) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
