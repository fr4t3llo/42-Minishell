/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_aux_functions2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:52:46 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:46:13 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_get_args(char *cmd, t_pipe **lst_of_args, int *i)
{
	int		j;
	char	c;

	j = *i;
	while (cmd[*i] && cmd[*i] != ' ' && cmd[*i] != '>' && cmd[*i] != '<')
	{
		if (cmd[*i] && (cmd[*i] == '\"' || cmd[*i] == '\''))
		{
			c = cmd[*i];
			(*i)++;
			while (cmd[*i] && (cmd[*i] != c))
				(*i)++;
		}
		(*i)++;
	}
	ft_lstadd_back(lst_of_args, ft_substr(cmd, j, *i - j));
}

void	ft_get_red(char *cmd, int *i, t_redic **lst_of_red)
{
	int		j;
	char	c;

	c = cmd[*i];
	(*i)++;
	if (cmd[*i] == c)
	{
		(*i)++;
		c = 'a';
	}
	while (cmd[*i] && cmd[*i] == ' ')
		(*i)++;
	j = *i;
	while (cmd[*i] && !ft_strchr(" ><", cmd[*i]))
		(*i)++;
	if (cmd[*i])
		(*i)--;
	ft_lstadd_back_red(lst_of_red, ft_substr(cmd, j, (*i) - j + 1), c);
}

char	**ft_get_env2(void)
{
	int		i;
	char	**ptr;
	t_env	*tmp;

	i = 0;
	tmp = g_var.env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = g_var.env;
	ptr = (char **)malloc(sizeof(char *) * (i + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	add_garbage(ptr);
	while (tmp)
	{
		ptr[i++] = ft_strjoin(ft_strjoin(tmp->data, "="), tmp->value);
		tmp = tmp->next;
	}
	ptr[i] = NULL;
	return (ptr);
}
