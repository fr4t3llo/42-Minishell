/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:00:27 by matef             #+#    #+#             */
/*   Updated: 2022/10/22 05:46:09 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*init_lexer(int *i, t_lexm **lexer)
{
	*i = -1;
	*lexer = NULL;
	return (ft_strdup(""));
}

void	ft_to_exp(int *i, char *cmd, t_lexm **lexer, char **to_expand)
{
	set_to_expand(lexer, to_expand);
	ft_lexer_2(i, cmd, lexer);
}

char	*ft_lexer_22(int *i, char *cmd, t_lexm **lexer, char *to_expand)
{
	if (cmd[*i] != '>' && cmd[*i] != '<' && cmd[*i] != '|')
		to_expand = ft_strjoin(to_expand, ft_substr(cmd, *i, 1));
	else
	{
		if (to_expand[0] != '\0')
		{
			add_to_lexer(lexer, to_expand);
			to_expand = ft_strdup("");
		}
		if (cmd[*i + 1] == cmd[*i])
		{
			add_to_lexer(lexer, ft_substr(cmd, *i, 2));
			(*i)++;
		}
		else
			add_to_lexer(lexer, ft_substr(cmd, *i, 1));
	}
	(*i)++;
	return (to_expand);
}

t_lexm	*ft_lexer(char *cmd)
{
	int		i;
	char	*to_expand;
	t_lexm	*lexer;

	i = 0;
	to_expand = ft_strdup("");
	lexer = NULL;
	while (cmd[i])
	{
		while (cmd[i] && cmd[i] != ' ')
		{
			if (cmd[i] == '\'' || cmd[i] == '\"')
				to_expand = ft_lexer_1(&i, cmd, to_expand);
			else
				to_expand = ft_lexer_22(&i, cmd, &lexer, to_expand);
		}
		if (to_expand[0] != '\0')
		{
			add_to_lexer(&lexer, to_expand);
			to_expand = ft_strdup("");
		}
		i++;
	}
	return (lexer);
}
